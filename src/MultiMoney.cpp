/*****************************
名称：MultiMoney.cpp
作者：尹一帆
时间：2017-06-22
描述：实现文件
版权：自行完成
******************************/
#include"../inc/MultiMoney.h"
using namespace std;

/*
*功能：输入构造一个多币种类；
*参数：
*	无
*返回值：
*	无
*算法：
*	无
*/
MultiMoney::MultiMoney()
{
	double amount;
	string type;
	cout << "请输入货币1金额：";
	while (cin >> amount)
	{
		if (amount <= 0)//金额小于等于0则停止输入；
			break;
		cout << "请输入货币" << num + 1 << "类型：";
		cin >> type;
		num++;
		SingleMoney temp(amount, type);
		single[num] = temp;
		cout << "请输入货币" << num + 1 << "金额：";
	}
}

//将所有币种转化为同一币种；
void MultiMoney::converseSingleMoney(string type)
{
	for (int i = 1; i <= num; i++)
	{
		single[i].converseCurrencyPermanent(type);
	}
}

//输出所有单币种；
void MultiMoney::show()
{
	for (int i = 1; i <= num; i++)
		single[i].showSingleMoney();
}

//重载加号；
MultiMoney& MultiMoney::operator+(SingleMoney& m)
{
	num++;
	single[num] = m;
	return *this;
}

//重载乘号；
MultiMoney& MultiMoney::operator*(double x)
{
	for (int i = 1; i <= num; i++)
	{
		single[i] *= x;
	}
	return *this;
}

//重载除号；
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

//暴力加和目标类型的币种；
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

//暴力加和所有币种；
SingleMoney MultiMoney::sum(string DstCurrency)
{
	SingleMoney sum(0, DstCurrency);
		for (int i = 1; i <= num; i++)
			sum += single[i];
	return sum;
}