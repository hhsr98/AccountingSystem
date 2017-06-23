/*****************************
���ƣ�MultiMoney.cpp
���ߣ���һ��
ʱ�䣺2017-06-22
������ʵ���ļ�
��Ȩ���������
******************************/
#include"../inc/MultiMoney.h"
using namespace std;

/*
*���ܣ����빹��һ��������ࣻ
*������
*	��
*����ֵ��
*	��
*�㷨��
*	��
*/
MultiMoney::MultiMoney()
{
	double amount;
	string type;
	cout << "���������1��";
	while (cin >> amount)
	{
		if (amount <= 0)//���С�ڵ���0��ֹͣ���룻
			break;
		cout << "���������" << num + 1 << "���ͣ�";
		cin >> type;
		num++;
		SingleMoney temp(amount, type);
		single[num] = temp;
		cout << "���������" << num + 1 << "��";
	}
}

//�����б���ת��Ϊͬһ���֣�
void MultiMoney::converseSingleMoney(string type)
{
	for (int i = 1; i <= num; i++)
	{
		single[i].converseCurrencyPermanent(type);
	}
}

//������е����֣�
void MultiMoney::show()
{
	for (int i = 1; i <= num; i++)
		single[i].showSingleMoney();
}

//���ؼӺţ�
MultiMoney& MultiMoney::operator+(SingleMoney& m)
{
	num++;
	single[num] = m;
	return *this;
}

//���س˺ţ�
MultiMoney& MultiMoney::operator*(double x)
{
	for (int i = 1; i <= num; i++)
	{
		single[i] *= x;
	}
	return *this;
}

//���س��ţ�
MultiMoney& MultiMoney::operator/(double x)
{
	for (int i = 1; i <= num; i++)
	{
		single[i] /= x;
	}
	return *this;
}

MultiMoney& MultiMoney::operator+=(SingleMoney& m)
{
	return *this + m;
}

MultiMoney& MultiMoney::operator*=(double x)
{
	return *this*x;
}

MultiMoney& MultiMoney::operator/=(double x)
{
	return *this / x;
}

//�����Ӻ�Ŀ�����͵ı��֣�
SingleMoney MultiMoney::sumPart(string DstCurrency)
{
	SingleMoney sum(0, DstCurrency);
	for (int i = 1; i <= num; i++)
	{
		if (single[i].CurrencyTypeNow == DstCurrency)
		{
			sum += single[i];
		}
	}
	return sum;
}

//�����Ӻ����б��֣�
SingleMoney MultiMoney::sum(string DstCurrency)
{
	SingleMoney sum(0, DstCurrency);
		for (int i = 1; i <= num; i++)
			sum += single[i];
	return sum;
}