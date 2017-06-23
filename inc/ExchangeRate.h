//使用SingleMoney前先构建一个公用的ExchangeRate类，该类的汇率、货币、总套数、指定某套汇率均为static；
#ifndef CURRENCY_H
#define CURRENCY_H

#include<iostream>
#include<string>
const int _N=200;

class ExchangeRate
{
	friend class SingleMoney;
	static double* Rate[_N];
	static std::string* CurrencyType[_N];
	static int num;//汇率套数；
	static int choice;//选择的汇率套数；
public:

	ExchangeRate();//初始构造；

	void addExchangeRate();//输入一套新的汇率；

	void deleteExchangeRate(int i);//删除某套汇率；

	void resetExchangeRate(int i,int j);//重设第i套汇率的第i项；

	void resetExchangeRate(int i, std::string s);

	void addExchangeRate(int i);//在第i套汇率中新添一项；

	void showExchangeRate(int i);//展示输出某套汇率；

	void showExchangeRate();//输出总汇率套数；

	void select(int n);//选定一套汇率来使用；

	~ExchangeRate();

};


#endif
