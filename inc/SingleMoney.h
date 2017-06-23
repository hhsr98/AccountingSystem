/******************************************
名称：SingleMoney.h
作者：尹一帆
时间：2017-06-22
描述：一个包含金额与币种的单币种货币类，内含各种运算符重载以及显示函数和汇率转换函数等等；
版权：自己
*******************************************/
//注：使用前先构造一个ExchangeRate类；

#ifndef SingleMoney_H
#define SingleMoney_H
#include<string>
#include"ExchangeRate.h"

class SingleMoney
{
	friend class MultiMoney;//以便于MultiMoney类调用SingleMoney类的数据与函数；
	std::string CurrencyTypeNow;//当前货币种类；
	double SingleMoneyAmount;//当前货币金额；
public:
	SingleMoney(double single_money, std::string currency_type_now);//构造相应金额币种的货币；

	SingleMoney() = default;//默认构造函数；

	std::string Currency() const//返回当前货币种类；
	{
	    return CurrencyTypeNow;
	}
	double Money() const//返回当前货币金额；
	{
	    return SingleMoneyAmount;
	}

	SingleMoney operator+(const SingleMoney& m) const;//重载单币种相加，返回结果为当前货币类型；

	SingleMoney operator-(const SingleMoney& m) const;//相减；

	SingleMoney operator*(double x) const ;//右乘；

	friend SingleMoney operator*(double x, SingleMoney& m);//左乘，但是没实现四则运算，只有连加减；

	SingleMoney operator/(double x) const ;//相除；

	SingleMoney operator+=(const SingleMoney& m);//+=;

	SingleMoney operator-=(const SingleMoney& m);//-=;

	SingleMoney operator*=(double x); //*= ;

	SingleMoney operator/=(double x); // /=;

	friend bool operator<(const SingleMoney& m,const SingleMoney& n);																	
	friend bool operator>(const SingleMoney& m,const SingleMoney& n);
	friend bool operator<=(const SingleMoney& m,const SingleMoney& n);
	friend bool operator>=(const SingleMoney& m,const SingleMoney& n);//重载各种偏序关系；

	double findRate(std::string name)const;//找到相应货币种类的对人民币汇率；

	double converseCurrency(std::string DstCurrency)const ;//将货币兑换为目标类型；

	SingleMoney& converseCurrencyPermanent(std::string DstCurrency);//将货币永久转换为目标类型；

	void showSingleMoney();//输出展示当前金额与种类；

	friend std::ostream& operator<<(std::ostream& os,const SingleMoney& money);//重载输出运算符；

};

#endif

