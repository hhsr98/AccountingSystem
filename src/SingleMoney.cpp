/************************************
���ƣ�SingleMoney.cpp
���ߣ���һ��
ʱ�䣺2017-06-22
����������SingleMoney.h��ʵ���ļ�
��Ȩ���������
*************************************/
#include"../inc/SingleMoney.h"
#include<iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

//�ù����б���һ��SingleMoney��
SingleMoney::SingleMoney(double single_money, string currency_type_now)
	:SingleMoneyAmount(single_money), CurrencyTypeNow(currency_type_now)
{
}																	

/*
*���ܣ����ص����������
*������
*	m��һ��const SingleMoney�������
*����ֵ��
*	һ��SingleMoney����+֮ǰ�ĵ����ֻ��ҵĻ�������Ϊ��׼�����Ϊ����ת������ӣ�
*�㷨��
*	����
*/
SingleMoney SingleMoney:: operator+(const SingleMoney& m) const
{
	double x = this->SingleMoneyAmount + m.converseCurrency(CurrencyTypeNow);
	SingleMoney temp(x, this->CurrencyTypeNow);
	return temp;
}

/*
*���ܣ����ص����������
*������
*	m��һ��const SingleMoney�������
*����ֵ��
*	һ��SingleMoney����-֮ǰ�ĵ����ֻ��ҵĻ�������Ϊ��׼�����Ϊ����ת������ӣ�
*�㷨��
*	����
*/
SingleMoney SingleMoney::operator-(const SingleMoney& m) const
{
	double x = this->SingleMoneyAmount - m.converseCurrency(CurrencyTypeNow);
	SingleMoney temp(x, this->CurrencyTypeNow);
	return temp;
}


/*
*���ܣ����ص����������ˣ��ҳˣ�
*������
*	x��һ��double
*����ֵ��
*	һ��SingleMoney��ֱ�ӽ�����x��
*�㷨��
*	����
*/
SingleMoney SingleMoney::operator*(double x) const
{
	return SingleMoney(x*this->SingleMoneyAmount, this->CurrencyTypeNow);
}


/*
*���ܣ����ص����������
*������
*	x��һ��double
*����ֵ��
*	һ��SingleMoney��ֱ�ӽ�����x��
*�㷨��
*	����
*/
SingleMoney SingleMoney::operator/(double x) const
{
	if (x <= 0)//�жϳ����Ƿ�ϸ�
	{
		cout << "The divisor must be positive!" << endl;
		return SingleMoney(0, this->CurrencyTypeNow);//������������ϱ�׼�������������Ϣ���ý��Ϊ0��
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
	if (x <= 0)//�жϳ����Ƿ�ϸ�
	{
		cout << "The divisor must be positive!" << endl;
		return SingleMoney(0, this->CurrencyTypeNow);//���ϸ������������Ϣ�����㣻
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
*���ܣ��ҵ���Ӧ��������Ķ�����һ��ʣ�
*������
*	name��һ��string
*����ֵ��
*	һ��double����ʾ���׻����¸û�������Ķ�����һ��ʣ�
*�㷨��
*	����ѭ������
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
	cout << "�û������಻���ڣ�" << endl;
	return 0;//���û�ҵ���Ӧ�Ļ��ʣ������������Ϣ�������㣻
}


/*
*���ܣ�����õ�λ����ת��ΪĿ����ֵ����
*������
*	DstCurrency��һ��string
*����ֵ��
*	һ��doubleʵ����Ϊת����Ľ�
*�㷨��
*	����findRate������
*/
double SingleMoney::converseCurrency(string DstCurrency) const
{
	double n;
	n = SingleMoneyAmount * findRate(CurrencyTypeNow) / findRate(DstCurrency);
	return n;
}


/*
*���ܣ����õ����ֻ�������ת��ΪĿ����ң�
*������
*	DstCurrency��һ��string
*����ֵ��
*	*this��һ��SingleMoney���ã����Ϊת����Ľ���������ΪĿ����ң�
*�㷨��
*	������ʱת����converseCurrency����
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
