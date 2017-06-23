/************************************
名称：EXchangeRate.h
作者：尹一帆
时间：2017-06-22
描述：一个汇率类，包含构造默认汇率、自行添加汇率等操作
版权：自行完成
*************************************/
#ifndef CURRENCY_H
#define CURRENCY_H

#include<iostream>
#include<string>
const int _N=200;

class ExchangeRate
{
	friend class SingleMoney;//以便SingleMoney使用汇率；
	static double* Rate[_N];//存放汇率的数组；
	static std::string* CurrencyType[_N];//存放币种的数组；
	static int num;//总汇率套数；
	static int choice;//选择的汇率套数；
public:

	ExchangeRate();//初始默认构造；

	void addExchangeRate();//自行输入一套新的汇率；

	void deleteExchangeRate(int i);//删除编号为i的一套汇率；

	void resetExchangeRate(int i,int j);//重设第i套汇率的第j项；

	void resetExchangeRate(int i, std::string s);//重设第i套汇率中的s币种；

	void addExchangeRate(int i);//在第i套汇率中新添一项；

	void showExchangeRate(int i);//展示输出某套汇率；

	void showExchangeRate();//输出总汇率套数；

	void select(int n);//选定一套汇率来使用；

	~ExchangeRate();

};


#endif
