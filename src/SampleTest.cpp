#include <cassert>
#include <iostream>
//#include <sqlite3.h>
#include <string>
#include <vector>

#include<db_connector/sqlpp11_connector/sqlite3_connector/Sqlite3DbConnector.h>

#include <Commodity.h>

#include "ui/ProxyManager.h"
#include "ui/Console/Proxy_Console.h"

SQLPP_ALIAS_PROVIDER(left);
SQLPP_ALIAS_PROVIDER(pragma);
SQLPP_ALIAS_PROVIDER(sub);

namespace sql = sqlpp::sqlite3;
int main()
{
    system("CHCP 65001");

    ExchangeRate ee;

    db_connector::AbstractDbConnector *data_base=new db_connector::sqlpp11::sqlite3::DbConnector("DataBase.db");
    auto root_com_list=data_base->selectCommodityAll();
    List *root_date_list=new List(new AllFilter);
    std::set<Person*> root_person_list;
    Person pa("ALPHA"),pb("BETA");
    root_person_list.insert(&pa);
    root_person_list.insert(&pb);

    for(int i=2013;i<=2017;i++)
    {
        Date d(i,1,1,0),d2(i,12,31,23);
        List* l=new List(new dateFilter(d,d2));
        l->setListName(std::to_string(i));
        root_date_list->addSublist(l);
        for(int j=1;j<=12;j++)
        {
            Date y(i,j,1,0),y2(i,j,31,0);
            List *ll=new List(new dateFilter(y,y2));
            ll->setListName(std::to_string(i)+"."+std::to_string(j));
            l->addSublist(ll);
        }
    }
    for(auto com:(*root_com_list))
    {
        std::cout<<(*com)<<std::endl;
        AbstractProxy::AutoClassiy(com,root_date_list);
    }

    List a(nullptr),b(nullptr),c(nullptr),d(nullptr),e(nullptr);
    a.setListName("fruit");b.setListName("apple");
    c.setListName("banana");d.setListName("imported banana");
    e.setListName("home-grown banana");
    c.addSublist(&e);
    c.addSublist(&d);
    a.addSublist(&b);
    a.addSublist(&c);

    AbstractProxy::RootClassifyList=&a;
    AbstractProxy::RootDateList=root_date_list;
    AbstractProxy::RootPersonList=&root_person_list;

    RootProxy_Console root;
    ProxyManager manager;
    manager.setRootProxy(&root);
    std::string temp;
    ProxyManager::state re;
    manager.addProxy(new PayingEntryProxy_Console(new Commodity));
    while(1)
    {
        getline(std::cin,temp);
        re=manager.process(temp);
        if(re==ProxyManager::quit) break;
        if(re==ProxyManager::success) std::cout<<"successfully done\n";
        else if(re==ProxyManager::fail) std::cout<<"fail\n";
    }

    std::set<Commodity*> save=AbstractProxy::RootDateList->get_CommodityList_All();
    for(auto cc: save)
    {
        data_base->saveCommodity(cc);
    }

  return 0;
}
