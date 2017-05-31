#include "../inc/date.h"
#include "../inc/Unit.h"
#include "../inc/Shop.h"
<<<<<<< HEAD

//#include "../inc/Analize.h"
#include"../inc/User.h"
#include"../inc/Display.h"

#include "../inc/Analize.h"
#include "../inc/Shop.h"

=======
<<<<<<< HEAD
//#include "../inc/Analize.h"
#include"../inc/User.h"
#include"../inc/Display.h"
=======
#include "../inc/Analize.h"
#include "../inc/Shop.h"
>>>>>>> 40f3313747fb26b1e4c5ed73c0e6b3cbd12cc0af
>>>>>>> 70de74d1dd4c02ba53c1b82a4d6bb489bc104262
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <time.h>
#include <sstream>
using namespace std;
AnalizeByDate* a;
int main()
{
<<<<<<< HEAD
   /* db_connector::AbstractDbConnector *a=new db_connector::sqlpp11::sqlite3::DbConnector("DataBase.db");
    auto pp=a->selectCommodityAll();
    pp=a->selectCommodityAll();
    Date ndate(2017,8,9,23);
    for(auto ss:(*pp))
    {
        std::cout<<(*ss)<<std::endl;
        ss->setDate(ndate);
    }

    std::cout<<std::endl<<std::endl<<std::endl;
    Commodity *comm=new Commodity();
    comm->setCommodityName("rice");
    SingleMoney money(8,"CNY");
    comm->setUnitPrice(money);
    Unit u(Unit::ch_Jing);
    comm->setUnit(u);
    comm->setQuantity(20);
    comm->setDate(ndate);
    pp->push_back(comm);
    a->saveCommodity(*pp);*/

=======
>>>>>>> 70de74d1dd4c02ba53c1b82a4d6bb489bc104262
	ExchangeRate exchange_rate;
	string opr;
	User* user = new User;
	cin >> opr;
	while (opr != "stop")
	{
		if (opr == "add_commodity")
			user->addCommodity();
		else if (opr == "add_list")
			user->addList();
		else if (opr == "add_paying_entry")
		{
			int i;
			cin >> i;
			user->addPayingEntry(i);
		}
		else if (opr == "add_multilist")
			user->addMultiList();
		else if (opr == "show_commodity")
		{
			int i;
			cin >> i;
			user->show("commodity", i);
		}
		else if (opr == "show_list")
		{
			int i;
			cin >> i;
			user->show("list", i);
		}
		cin >> opr;
	}

	system("pause");
	return 0;
}
