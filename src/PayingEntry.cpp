#include"../inc/PayingEntry.h"
#include<iostream>
using namespace std;
PayingEntry::PayingEntry(Commodity* com,int num):_com(com), person_num(num){
	set_map();
}

 map<string,double> PayingEntry::person_topay=map<string,double>();//定义静态成员变量

 int PayingEntry::num=0;//定义静态成员变量，记录涉及人的总数

void PayingEntry::set_static(string name) {
	map<string,double>::iterator iter_r;
	bool judge=true;
	for(iter_r=person_topay.begin();iter_r!=person_topay.end();iter_r++) {//判断是否已经储存该名字
		if (string(iter_r->first)==string(name))
		{
			judge=false;
			break;
		}	
	}
	if(judge) {
		person_topay[name];
		num++;//涉及的总人数加一
	}
}

void PayingEntry::set_map() { //设置付款的人以及金额
	string str1;
	double price;
	while(cin>>str1>>price) { //输入人名以及对应的付款
		person_rate[str1];
		person_price[str1]=price;
		set_static(str1);
	}

	total_num=set_total_sum();

    map<string,double>::iterator iter;
	for(iter=person_rate.begin();iter!=person_rate.end();iter++) {
		iter->second=setRate(iter->first);
	}
}

double PayingEntry::setRate(string name) { //输入人名，返回该人对应的比例
	double average=total_num/person_num;//每个人应付的数目
	double paying_need=average-person_price[name];//每个人最后需要付的数目
	return paying_need/total_num;
}

double PayingEntry::set_total_sum() {//获得付款的总金额
	map<string,double>::iterator iter;
	double sum=0;
	for(iter=person_price.begin();iter!=person_price.end();iter++) {
		sum=sum+iter->second;
	}
	return sum;
}


const map<string,double> PayingEntry::get_person_rate_list() const {
	return person_rate;
}

const double PayingEntry::get_total_num() const {
	return total_num;
}

const Commodity* PayingEntry::get_Commodity()const {
	return _com;
}

const int PayingEntry::get_person_num()const {
	return person_num;
}

const map<string,double> PayingEntry::get_person_topay() const {
	return person_topay;
}

const int PayingEntry::get_total_person_num()const {
	return num;
}
