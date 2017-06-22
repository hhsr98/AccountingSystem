#include "../inc/MultiList.h"
MultiList::MultiList(std::string name):List_name(name),num_entry(0){

}

void MultiList::add_entry(PayingEntry* payingentry) {//添加新的付款条目，将其地址存放在vec_entry中
	num_entry++;
	vec_entry.push_back(payingentry);
}


void MultiList::set_topay() {//设置存放多人账单中涉及的所有人的应付金额的map
	std::vector<PayingEntry*>::iterator iter;
	person_topay=(*(vec_entry[0])).get_person_topay();
	person_topaycopy=person_topay;//拷贝PayingEntry中的静态变量
	num_person=(*(vec_entry[0])).get_total_person_num();//拷贝PayingEntry中的静态变量
	for(iter=vec_entry.begin();iter!=vec_entry.end();iter++) {//遍历存放付款条目的vector
		std::map<std::string,double>::iterator iter1;
		std::map<std::string,double>temp=((*iter)->get_person_rate_list());//获取该笔付款条目中的人名及其对应的比例
		double sum=((*iter)->get_total_num());//获取该笔付款条目中的总金额
		for(iter1=temp.begin();iter1!=temp.end();iter1++) {
			person_topay[iter1->first]+=iter1->second*sum;//将某个人每笔payingEntry该付的金额相加存在person_topay中
		}
	}
}

double MultiList::get_topay(std::string name) {//获得每个人需要支付多少
	return person_topaycopy[name];
}

void MultiList::show_topay() {//输出如何转账的方案
	std::map<std::string,double>::iterator iter,iter_swap;
	std::vector<std::string>temp;
	for(iter=person_topay.begin();iter!=person_topay.end();iter++) {//遍历map
		if(iter->second!=0)
		{
			temp.push_back(iter->first);
			 iter_swap=iter;
			 iter_swap++;
			while((iter_swap)->second==0)
			{
				iter_swap++;
			}
				temp.push_back(iter_swap->first);
				iter_swap->second+=iter->second;
				how_to_pay.insert ( std::pair<std::vector<std::string>,double>(temp,iter->second) );
				iter->second=0;
				std::vector <std::string>().swap(temp);
				iter_swap=iter;
				 iter_swap++;
				if((iter_swap->second<0.0000001&&iter_swap->second>-0.0000001))
					break;
		}
	}
}

const std::map<std::vector<std::string>,double> MultiList::get_how_to_pay()const {
	return how_to_pay;
}

const std::vector<PayingEntry*>MultiList::get_vec_entry()const {
	return vec_entry;
}

const std::map<std::string,double>MultiList::getperson_topaycopy()const {
	return person_topaycopy;
}

const std::string MultiList::get_name()const {
	return List_name;
}

const int MultiList::get_num() const {
	return num_entry;
}
