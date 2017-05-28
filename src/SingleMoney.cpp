//SingleMoney.cpp
#include"../inc/SingleMoney.h"
#include<iostream>

SingleMoney::SingleMoney(double single_money, string currency_type_now)
	:SingleMoneyAmount(single_money), CurrencyTypeNow(currency_type_now)
{
}


SingleMoney SingleMoney:: operator+(SingleMoney& m)
{
	double x = this->SingleMoneyAmount + m.converseCurrency(CurrencyTypeNow);
	SingleMoney temp(x, this->CurrencyTypeNow);
	return temp;
}

SingleMoney SingleMoney::operator-(SingleMoney& m)
{
	double x = this->SingleMoneyAmount - m.converseCurrency(CurrencyTypeNow);
	SingleMoney temp(x, this->CurrencyTypeNow);
	return temp;
}

SingleMoney SingleMoney::operator*(double x)
{
	return SingleMoney(x*this->SingleMoneyAmount, this->CurrencyTypeNow);
}

SingleMoney SingleMoney::operator/(double x)
{
	if (x <= 0)
	{
		cout << "The divisor must be positive!" << endl;
		return SingleMoney(0, this->CurrencyTypeNow);
	}
	return SingleMoney(this->SingleMoneyAmount / x, this->CurrencyTypeNow);
}

SingleMoney SingleMoney::operator+=(SingleMoney& m)
{
	*this = *this + m;
	return *this;
}

SingleMoney SingleMoney::operator-=(SingleMoney& m)
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

bool SingleMoney::operator<(SingleMoney& m)
{
	return this->SingleMoneyAmount < m.converseCurrency(this->CurrencyTypeNow);
}

bool SingleMoney::operator>(SingleMoney& m)
{
	return this->SingleMoneyAmount > m.converseCurrency(this->CurrencyTypeNow);
}

bool SingleMoney::operator<=(SingleMoney& m)
{
	return this->SingleMoneyAmount <= m.converseCurrency(this->CurrencyTypeNow);
}

bool SingleMoney::operator>=(SingleMoney& m)
{
	return this->SingleMoneyAmount >= m.converseCurrency(this->CurrencyTypeNow);
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

double SingleMoney::findRate(string name)
{
	for (int i = 0; i < N; i++)
	{
		if (name == ExchangeRate::CurrencyType[ExchangeRate::choice][i])
		{
			return ExchangeRate::Rate[ExchangeRate::choice][i];
		}
	}
	return 0;
}

double SingleMoney::converseCurrency(string DstCurrency)
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