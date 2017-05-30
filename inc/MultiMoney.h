#ifndef MULTIMONEY_H
#define MULTIMONEY_H
#include"SingleMoney.h"
#include<iostream>
const int N=200;

class MultiMoney
{
	SingleMoney single[N];
	int num{ 0 };
public:
	MultiMoney();//构造；

	//SingleMoney converseSingleMoney();

	void converseSingleMoney(std::string type);//所有币种转化为指定单币种；

	void show();//展示输出；

	MultiMoney& operator+(SingleMoney& m);//添加一项；

	//MultiMoney operator-(MultiMoney& m);

	MultiMoney& operator*(double x);//右乘；

	friend MultiMoney& operator*(double x, MultiMoney& m)//左乘；
	{
		return m*x;
	}

	MultiMoney& operator/(double x);

	MultiMoney& operator+=(SingleMoney& m);//添加一项；

	MultiMoney& operator*=(double x);

	MultiMoney& operator/=(double x);

	SingleMoney sumPart(std::string DstCurrency);//对某种货币求和;

	SingleMoney sum(std::string DstCurrency);//对总体求和为某币种;

	~MultiMoney() = default;

};


#endif
