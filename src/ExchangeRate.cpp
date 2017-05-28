#include".../inc/ExchangeRate.h"
using namespace std;

ExchangeRate::ExchangeRate()
{
	num++;
	Rate[1] = new double[N]{ 100,88.792,689.770,514.677,853.253,6.212,517.418,730.456,0.609,19.947,22.541 };
	CurrencyType[1] = new string[N]{ "CNY", "HKD", "USD", "CAD", "GBP", "JPY", "AUD", "EUR", "KRW", "THB", "TWD" };
	for (int i = 11; i < N; i++)//init;
	{
		Rate[1][i] = 0;
		CurrencyType[1][i] = "0";
	}
}

void ExchangeRate::addExchangeRate()
{
	num++;
	Rate[num] = new double[N];
	CurrencyType[num] = new string[N];
	for (int i = 0; i < N; i++)//init;
	{
		Rate[num][i] = 0;
		CurrencyType[num][i] = "0";
	}
	int n = 0;
	cout << "请输货币1:";
	cin >> CurrencyType[num][n];
	while (CurrencyType[num][n] != "0")
	{
		cout << "请输入汇率" << n + 1 << ":";
		cin >> Rate[num][n];
		n++;
		cout << "请输入货币" << n + 1 << ":";
		cin >> CurrencyType[num][n];
	}
	if (CurrencyType[num][0] == "0")
		num--;
}

void ExchangeRate::deleteExchangeRate(int i)
{
	if (i < num)
	{
		for (int j = i; j < num; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (CurrencyType[j][k] != "0" || CurrencyType[j + 1][k] != "0")
				{
					Rate[j][k] = Rate[j + 1][k];
					CurrencyType[j][k] = CurrencyType[j + 1][k];
				}
				else
				{
					delete[] Rate[num];
					delete[] CurrencyType[num];
					Rate[num] = { NULL };
					CurrencyType[num] = { NULL };
					num--;
					return;
				}
			}
		}
	}
	delete[] Rate[num];
	delete[] CurrencyType[num];
	Rate[num] = { NULL };
	CurrencyType[num] = { NULL };
	num--;
}

void ExchangeRate::resetExchangeRate(int i,int j)
{
	cout << "请重新输入货币" << j << ":";
	cin >> CurrencyType[i][j-1];
	cout << "请重新输入汇率" << j << ":";
	cin >> Rate[i][j - 1];
}

void ExchangeRate::resetExchangeRate(int i, string s)
{
	for (int j = 0; j < N; j++)
	{
		if (CurrencyType[i][j] == s)
		{
			cout << "请重新输入货币" << j+1 << ":";
			cin >> CurrencyType[i][j];
			cout << "请重新输入汇率" << j+1 << ":";
			cin >> Rate[i][j];
			return;
		}
	}
}

void ExchangeRate::addExchangeRate(int i)
{
	for (int j = 0; j < N; j++)
	{
		if (Rate[i][j] == 0)
		{
			cout << "请输入货币" << j + 1 << ":";
			cin >> CurrencyType[i][j];
			cout << "请输入汇率" << j + 1 << ":";
			cin >> Rate[i][j];
			return;
		}
	}
}

void ExchangeRate::showExchangeRate(int i)
{
	if (i <= 0 || i > num)
	{
		cout << "汇率访问操作出错！" << endl;
		return;
	}
	for (int j = 0; j < N; j++)
	{
		if (CurrencyType[i][j] != "0")
			cout << CurrencyType[i][j] << ":" << Rate[i][j] << endl;
		else return;
	}
}

void ExchangeRate::showExchangeRate()
{
	cout << "一共有" << num << "套汇率" << endl;
}

ExchangeRate::~ExchangeRate()
{
	for (int i = 1; i < N; i++)
	{
		if(Rate[i]!=NULL)
		delete[] Rate[i];
		if(CurrencyType[i]!=NULL)
		delete[] CurrencyType[i];
	}
}

void ExchangeRate::select(int n)
{
	choice = n;
}

int ExchangeRate::num = 0;

double* ExchangeRate::Rate[N] = { NULL };

string* ExchangeRate::CurrencyType[N] = { NULL };

int ExchangeRate::choice = 1;