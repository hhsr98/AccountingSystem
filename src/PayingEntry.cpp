#include"../inc/PayingEntry.h"
#include<iostream>
using namespace std;
PayingEntry::PayingEntry(Commodity com,int num):_com(com), person_num(num){
	set_map();
}
void PayingEntry::set_map() {
	string str1;
	double price;
	while(cin>>str1>>price) {
		person_rate[str1];
		person_price[str1]=price;
	}

	total_num=set_total_sum();

    map<string,double>::iterator iter;
	for(iter=person_rate.begin();iter!=person_rate.end();iter++) {
		iter->second=setRate(iter->first);
	}
}

double PayingEntry::setRate(string name) {
	double average=total_num/person_num;
	double paying_need=average-person_price[name];
	return paying_need/total_num;
}

double PayingEntry::set_total_sum() {
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

const Commodity PayingEntry::get_Commodity()const {
	return _com;
}

const int PayingEntry::get_person_num()const {
	return person_num;
}
