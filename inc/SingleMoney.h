//SingleMoney.h 只实现了预设固定汇率，没有实时汇率；
#ifndef SingleMoney_H
#define SingleMoney_H
#include<string>
#include"ExchangeRate.h"

class SingleMoney
{
	friend class MultiMoney;
	std::string CurrencyTypeNow;//当前货币种类；
	double SingleMoneyAmount;//当前货币金额；
public:
	SingleMoney(double single_money, std::string currency_type_now);

	SingleMoney() = default;

	std::string Currency() const
	{
	    return CurrencyTypeNow;
	}
	double Money() const
	{
	    return SingleMoneyAmount;
	}

	SingleMoney operator+(const SingleMoney& m) const;//重载多币种相加，返回结果为当前货币类型；

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
	friend bool operator>=(const SingleMoney& m,const SingleMoney& n);

	//void addCurrencyTypeAmount();//用户添加货币种类；

	double findRate(std::string name)const;//找到相应货币种类的对人民币汇率；

	double converseCurrency(std::string DstCurrency)const ;//将货币兑换为目标类型；

	SingleMoney& converseCurrencyPermanent(std::string DstCurrency);//将货币永久转换为目标类型；

	void showSingleMoney();//输出展示当前金额与种类；

	friend std::ostream& operator<<(std::ostream& os,const SingleMoney& money);

};
bool operator<(const SingleMoney& m,const SingleMoney& n);
bool operator>(const SingleMoney& m,const SingleMoney& n);
bool operator<=(const SingleMoney& m,const SingleMoney& n);
bool operator>=(const SingleMoney& m,const SingleMoney& n);
#endif

