#ifndef PAYINGENTRY
#define PAYINGENTRY
#include "Commodity.h"
#include <map>
#include<cstring>
#include<iostream>
using namespace std;
class PayingEntry {
private:
	Commodity _com;
	map<string,double> person_rate;
	map<string,double>person_price;
	double total_num;
	int person_num;
public:
	PayingEntry(Commodity com,int num);
	void set_map();
	double setRate(string name);
	double set_total_sum();
	const map<string,double> get_person_rate_list() const;
	const double get_total_num() const;
	const Commodity get_Commodity()const;
	const int get_person_num()const;
};
#endif