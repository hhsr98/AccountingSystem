#include "../inc/MultiList.h"
MultiList::MultiList(string name):List_name(name),num_entry(0){

}

void MultiList::add_entry(Commodity* com,int num) {//添加新的付款条目，将其地址存放在vec_entry中
	num_entry++;
	SmartPtr<PayingEntry>ptr=new PayingEntry(com,num);
	vec_entry.push_back(ptr);
} 


void MultiList::set_topay() {//设置存放多人账单中涉及的所有人的应付金额的map
	vector<SmartPtr<PayingEntry>>::iterator iter;
	person_topay=(*(vec_entry[0])).get_person_topay();
	person_topaycopy=person_topay;//拷贝PayingEntry中的静态变量
	num_person=(*(vec_entry[0])).get_total_person_num();//拷贝PayingEntry中的静态变量
	for(iter=vec_entry.begin();iter!=vec_entry.end();iter++) {//遍历存放付款条目的vector
		map<string,double>::iterator iter1;
		map<string,double>temp=((*iter)->get_person_rate_list());//获取该笔付款条目中的人名及其对应的比例
		double sum=((*iter)->get_total_num());//获取该笔付款条目中的总金额
		for(iter1=temp.begin();iter1!=temp.end();iter1++) {
			person_topay[iter1->first]+=iter1->second*sum;//将某个人每笔payingEntry该付的金额相加存在person_topay中
		}
	}
}

double MultiList::get_topay(string name) {//获得每个人需要支付多少
	return person_topaycopy[name];
}

void MultiList::show_topay() {//输出如何转账的方案
	map<string,double>::iterator iter,iter_swap;
	for(iter=person_topay.begin();iter!=person_topay.end();iter++) {//遍历map
		if(iter->second>0)//当大于0的时候，则将所付金额数转给后面第一个所付金额非零的人
		{
			iter_swap=iter++;
			while((iter_swap)->second==0)
				iter_swap++;
			cout<<iter->first<<"支付给"<<iter_swap->first<<iter->second<<endl;
			iter_swap->second+=iter->second;
			iter->second=0;
		}
		if(iter->second<0)//当小于零时，从前面第一个所付金额非零的人出转入所缺的金额数
		{
				iter_swap=iter--;
				while(iter_swap->second==0)
					iter_swap--;
				cout<<iter_swap->first<<"支付给"<<iter->first<<iter->second<<endl;
				iter_swap->second+=iter->second;
				iter->second=0;
		}

	}

}

