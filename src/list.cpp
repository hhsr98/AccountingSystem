#include"../inc/list.h"
using namespace std;

List::List(const Filter *f):criteria(f),vec_commodity(),vec_sublist()
{

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

vector<Commodity*> List::get_CommodityList ()const	{
	return this->vec_commodity;
}

vector<List*>List::get_Sublist()const {
	return this->vec_sublist;
}

