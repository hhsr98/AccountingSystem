/************************************
名称：SingleMoney.cpp
作者：尹一帆
时间：2017-06-22
描述：这是SingleMoney.h的实现文件
版权：自行完成
*************************************/
#include"../inc/SingleMoney.h"
#include<iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

//用构造列表构造一个SingleMoney；
SingleMoney::SingleMoney(double single_money, string currency_type_now)
	:SingleMoneyAmount(single_money), CurrencyTypeNow(currency_type_now)
{
}																	

/*
*功能：重载单币种类相加
*参数：
*	m：一个const SingleMoney类的引用
*返回值：
*	一个SingleMoney，以+之前的单币种货币的货币种类为基准，金额为汇率转换后相加；
*算法：
*	暴力
*/
SingleMoney SingleMoney:: operator+(const SingleMoney& m) const
{
	double x = this->SingleMoneyAmount + m.converseCurrency(CurrencyTypeNow);
	SingleMoney temp(x, this->CurrencyTypeNow);
	return temp;
}

/*
*功能：重载单币种类相减
*参数：
*	m：一个const SingleMoney类的引用
*返回值：
*	一个SingleMoney，以-之前的单币种货币的货币种类为基准，金额为汇率转换后相加；
*算法：
*	暴力
*/
SingleMoney SingleMoney::operator-(const SingleMoney& m) const
{
	double x = this->SingleMoneyAmount - m.converseCurrency(CurrencyTypeNow);
	SingleMoney temp(x, this->CurrencyTypeNow);
	return temp;
}


/*
*功能：重载单币种类数乘，右乘；
*参数：
*	x：一个double
*返回值：
*	一个SingleMoney，直接金额乘以x；
*算法：
*	暴力
*/
SingleMoney SingleMoney::operator*(double x) const
{
	return SingleMoney(x*this->SingleMoneyAmount, this->CurrencyTypeNow);
}


/*
*功能：重载单币种类相除
*参数：
*	x：一个double
*返回值：
*	一个SingleMoney，直接金额除以x；
*算法：
*	暴力
*/
SingleMoney SingleMoney::operator/(double x) const
{
	if (x <= 0)//判断除数是否合格；
	{
		cout << "The divisor must be positive!" << endl;
		return SingleMoney(0, this->CurrencyTypeNow);//如果除数不符合标准，则输出错误信息并置结果为0；
	}
	return SingleMoney(this->SingleMoneyAmount / x, this->CurrencyTypeNow);
}

SingleMoney SingleMoney::operator+=(const SingleMoney& m)
{
	*this = *this + m;
	return *this;
}

SingleMoney SingleMoney::operator-=(const SingleMoney& m)
{
	*this = *this - m;
	return *this;
}

SingleMoney SingleMoney::operator*=(double x)
{
	*this = *this*x;
	return *this;
}

SingleMoney SingleMoney::operator/=(double x)
{
	if (x <= 0)//判断除数是否合格；
	{
		cout << "The divisor must be positive!" << endl;
		return SingleMoney(0, this->CurrencyTypeNow);//不合格则输出错误信息并置零；
	}

	*this = *this / x;
	return *this;
}

SingleMoney operator*(double x, SingleMoney& m)
{
	return m*x;
}

bool operator<(const SingleMoney& m,const SingleMoney& n)
{
    return m.SingleMoneyAmount < n.converseCurrency(m.CurrencyTypeNow);
}
bool operator>(const SingleMoney& m,const SingleMoney& n)
{
    return m.SingleMoneyAmount > n.converseCurrency(m.CurrencyTypeNow);
}
bool operator<= (const SingleMoney& m,const SingleMoney& n)
{
    return m.SingleMoneyAmount <= n.converseCurrency(m.CurrencyTypeNow);
}
bool operator>= (const SingleMoney& m,const SingleMoney& n)
{
    return m.SingleMoneyAmount >= n.converseCurrency(m.CurrencyTypeNow);
}


/*
*功能：找到对应货币种类的对人民币汇率；
*参数：
*	name：一个string
*返回值：
*	一个double，表示该套汇率下该货币种类的对人民币汇率；
*算法：
*	暴力循环查找
*/
double SingleMoney::findRate(string name) const
{
	for (int i = 0; i < _N; i++)
	{
		if (name == ExchangeRate::CurrencyType[ExchangeRate::choice][i])
		{
			return ExchangeRate::Rate[ExchangeRate::choice][i];
		}
	}
	cout << "该货币种类不存在！" << endl;
	return 0;//如果没找到对应的汇率，则输出错误信息并返回零；
}


/*
*功能：计算该单位货币转换为目标币种的情况
*参数：
*	DstCurrency：一个string
*返回值：
*	一个double实数，为转换后的金额；
*算法：
*	调用findRate函数；
*/
double SingleMoney::converseCurrency(string DstCurrency) const
{
	double n;
	n = SingleMoneyAmount * findRate(CurrencyTypeNow) / findRate(DstCurrency);
	return n;
}


/*
*功能：将该单币种货币永久转换为目标货币；
*参数：
*	DstCurrency：一个string
*返回值：
*	*this，一个SingleMoney引用，金额为转换后的金额，货币种类为目标货币；
*算法：
*	调用临时转换的converseCurrency函数
*/
SingleMoney& SingleMoney::converseCurrencyPermanent(string DstCurrency)
{
	this->SingleMoneyAmount = converseCurrency(DstCurrency);
	this->CurrencyTypeNow = DstCurrency;
	return *this;
}

void SingleMoney::showSingleMoney()
{
	cout << SingleMoneyAmount << " " << CurrencyTypeNow << endl;
}

std::ostream& operator<<(std::ostream& os,const SingleMoney& money)
{
    os<<money.SingleMoneyAmount<<' '<<money.CurrencyTypeNow;
    return os;
}
