//SingleMoney.cpp
#include"../inc/SingleMoney.h"
#include<iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
SingleMoney::SingleMoney(double single_money, string currency_type_now)
	:SingleMoneyAmount(single_money), CurrencyTypeNow(currency_type_now)
{
}


SingleMoney SingleMoney:: operator+(const SingleMoney& m) const
{
	double x = this->SingleMoneyAmount + m.converseCurrency(CurrencyTypeNow);
	SingleMoney temp(x, this->CurrencyTypeNow);
	return temp;
}

SingleMoney SingleMoney::operator-(const SingleMoney& m) const
{
	double x = this->SingleMoneyAmount - m.converseCurrency(CurrencyTypeNow);
	SingleMoney temp(x, this->CurrencyTypeNow);
	return temp;
}

SingleMoney SingleMoney::operator*(double x) const
{
	return SingleMoney(x*this->SingleMoneyAmount, this->CurrencyTypeNow);
}

SingleMoney SingleMoney::operator/(double x) const
{
	if (x <= 0)
	{
		cout << "The divisor must be positive!" << endl;
		return SingleMoney(0, this->CurrencyTypeNow);
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
	if (x <= 0)
	{
		cout << "The divisor must be positive!" << endl;
		return SingleMoney(0, this->CurrencyTypeNow);
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

/*void SingleMoney::addCurrencyTypeAmount()//一次加一种；
{
	string CurrencyName;
	double CurrencyExchangeRate;
	cin >> CurrencyName;
	cin >> CurrencyExchangeRate;
	CurrencyTypeAmount++;
	ExchangeRate::Rate[CurrencyTypeAmount - 1] = CurrencyExchangeRate;
	CurrencyType[CurrencyTypeAmount - 1] = CurrencyName;
}*/

double SingleMoney::findRate(string name) const
{
	for (int i = 0; i < _N; i++)
	{
		if (name == ExchangeRate::CurrencyType[ExchangeRate::choice][i])
		{
			return ExchangeRate::Rate[ExchangeRate::choice][i];
		}
	}
	return 0;
}

double SingleMoney::converseCurrency(string DstCurrency) const
{
	double n;
	n = SingleMoneyAmount * findRate(CurrencyTypeNow) / findRate(DstCurrency);
	return n;
}

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
