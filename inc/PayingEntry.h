#ifndef PAYINGENTRY
#define PAYINGENTRY
#include "Commodity.h"
#include <map>
#include<cstring>
#include<iostream>
class PayingEntry {
private:
	Commodity* _com;//商品信息
	std::map<std::string,double> person_rate;//存放人名以及对应的比例
	std::map<std::string,double>person_price;//存放人名以及对应的实际付款
	static std::map<std::string,double> person_topay;//静态变量，存放人名和最终需要支付的钱
	static int num;//多人账单中涉及的总人数
	double total_num;//总付款
	int person_num;//涉及人数
	bool judge;//选择是否手动输入比例
public:
	PayingEntry(Commodity* com,int num,bool judge);
	void set_map();//设置 person_rate
	double is_set(std::string name);//手动输入比例
	double setRate(std::string name);//计算比例
	double set_total_sum();//计算总付款
	void set_static(std::string name);//判断该人名是否已经录入person_topay中
	const std::map<std::string,double> get_person_rate_list() const;
	const std::map<std::string,double> get_person_topay() const;
	const double get_total_num() const;
	const Commodity* get_Commodity()const;
	const int get_person_num()const;
	const int get_total_person_num()const;
	const bool get_judge()const;
};
#endif
