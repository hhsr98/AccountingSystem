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
const Commodity* List::get_Commodity(int i) const {
	return (vec_commodity[i]);
}
const Commodity* List::get_SublistCommodity(int i,int j) const {
	return(vec_sublist[i]->get_Commodity(j));
}
List::List():_sum(0,"NAN") {
	//void setList();
	Sum();
}