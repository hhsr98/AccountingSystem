#include"MultiMoney.h"
using namespace std;
MultiMoney::MultiMoney()
{
	double amount;
	string type;
	cout << "请输入货币1金额：";
	while (cin >> amount)
	{
		if (amount <= 0)
			break;
		cout << "请输入货币" << num + 1 << "类型：";
		cin >> type;
		num++;
		SingleMoney temp(amount, type);
		single[num] = temp;
		cout << "请输入货币" << num + 1 << "金额：";
	}
}

/*void MultiMoney::converseSingleMoney()
{
	SingleMoney temp=single[1];
	for (int i = 2; i <= num; i++)
	{
		temp += single[i];
	}
	return temp;
}*/

void MultiMoney::converseSingleMoney(string type)
{
	for (int i = 1; i <= num; i++)
	{
		single[i].converseCurrencyPermanent(type);
	}
}

void MultiMoney::show()
{
	for (int i = 1; i <= num; i++)
		single[i].showSingleMoney();
}

MultiMoney& MultiMoney::operator+(SingleMoney& m)
{
	num++;
	single[num] = m;
	return *this;
}

/*MultiMoney MultiMoney::operator-(MultiMoney& m)
{
	return 0;
}*/

MultiMoney& MultiMoney::operator*(double x)
{
	for (int i = 1; i <= num; i++)
	{
		single[i] *= x;
	}
	return *this;
}

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

SingleMoney MultiMoney::sum(string DstCurrency)
{
	SingleMoney sum(0, DstCurrency);
		for (int i = 1; i <= num; i++)
			sum += single[i];
	return sum;
}