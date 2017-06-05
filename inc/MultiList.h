#ifndef MULTILIST_H
#define MULTILIST_H
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include"PayingEntry.h"
class MultiList {
private:
	string List_name;
	vector<PayingEntry*> vec_entry;//存放付款条目类的计数指针的向量
	map<string,double>person_topay,person_topaycopy;//存放多人账单中涉及的所有人的应付金额
	map<vector<string>,double>how_to_pay;//存放人A转给人B多少钱
	int num_entry;//付款条目的数目
	int num_person;//多人账单中涉及的总人数
public:
	MultiList(string name);
	void add_entry(PayingEntry* payingentry);//在多人账单中添加付款条目
	double get_topay(string name);//获取某个人的应付金额
	void show_topay();//输出如何转账的方案
	void set_topay();//设置person_topay，设置所有人的应付金额
	const map<vector<string>,double> get_how_to_pay()const;
	const vector<PayingEntry*>get_vec_entry()const;
	const map<string,double>getperson_topaycopy()const;
	const std::string get_name()const;
	const int get_num()const;
};

#endif 