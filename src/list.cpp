#include "list.h"
using namespace std;

List::List(const Filter *f,const List *faList,bool include_sublist):criteria(),vec_commodity(),vec_sublist()
{
    if(include_sublist) vec_commodity=faList->get_CommodityList_All();
    else vec_commodity=faList->get_CommodityList();
    for(auto com:vec_commodity)
        com->regObserverList(this);
    setFilter(f);
}

SingleMoney List::Sum() const
{
	int i;
	SingleMoney _sum;
	for (const auto a:vec_commodity)
		_sum+=a->TotalPrice();
	for(const auto a:vec_sublist)
		_sum+=a->Sum();
    return _sum;
}

set<Commodity*> List::get_CommodityList ()const	{
	return vec_commodity;
}

set<List*>List::get_Sublist()const {
	return vec_sublist;
}

set<Commodity*> List::get_CommodityList_All() const
{
    set<Commodity*> new_set=vec_commodity;
    for(auto l: vec_sublist)
    {
        set<Commodity*> temp=l->get_CommodityList_All();
        for(auto c: temp)
            new_set.insert(c);
    }
    return new_set;
}
void List::deleteCommodity(Commodity *com)
{
    if(vec_commodity.find(com)!=vec_commodity.end())
    {
        com->delObserverList(this);
        vec_commodity.erase(com);
    }
}
void List::setFilter(const Filter *f)
{
    criteria=f;
    std::vector<Commodity*> del;
    for(const auto r:vec_commodity)
    {
        if(!isValidCommodity(r))
            del.push_back(r);
    }
    for(const auto r:del)
    {
        r->delObserverList(this);
        vec_commodity.erase(r);
    }
}
Commodity* List::getCommodity(int i)
{
    int k=0;
    for(auto r:vec_commodity)
    {
        if(k==i) return r;
        k++;
    }
    return nullptr;
}
List* List::getSubList(int i)
{
    int k=0;
    for(auto r:vec_sublist)
    {
        if(k==i) return r;
        k++;
    }
    return nullptr;

}
