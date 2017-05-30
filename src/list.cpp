#include"../inc/list.h"
using namespace std;

SingleMoney List::Sum() {
	int i;
	for (i=0;i!=num_commodity;i++) 
		this->_sum=this->vec_commodity[i]->TotalPrice()+this->_sum;
	for(i=0;i!=num_sublist;i++)
		this->_sum=this->_sum+vec_sublist[i]->_sum;
	return (this->_sum);
}

const vector<Commodity*> List::get_CommodityList ()const	{
	return this->vec_commodity;
}

const vector<List*>List::get_Sublist()const {
	return this->vec_sublist;
}

List::List(Filter* filter):_sum(0,"NAN") {
	/* for(int i;i!=all_num;i++)//遍历商品信息
	{
	Request _request(&commodity[i]);
	if (_filter->FilterIt(&_request)._isReject())
		//this->vec_commodity.push_back(&commodity[i]);
	}*/
	Sum();
}
