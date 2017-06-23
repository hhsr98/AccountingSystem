/************************************
名称：EXchangeRate.cpp
作者：尹一帆
时间：2017-06-22
描述：汇率类的实现文件
版权：自行完成
*************************************/
#include"../inc/ExchangeRate.h"
using namespace std;

/*
*功能：默认构造一套汇率；
*参数：
*	无
*返回值：
*	无
*算法：
*	暴力
*/
ExchangeRate::ExchangeRate()
{
	num++;//每构建一套汇率，总汇率数+1；
	Rate[1] = new double[_N]{ 100,88.792,689.770,514.677,853.253,6.212,517.418,730.456,0.609,19.947,22.541 };
	CurrencyType[1] = new string[_N]{ "CNY", "HKD", "USD", "CAD", "GBP", "JPY", "AUD", "EUR", "KRW", "THB", "TWD" };
	for (int i = 11; i < _N; i++)//初始化；
	{
		Rate[1][i] = 0;
		CurrencyType[1][i] = "0";
	}
}

/*
*功能：自行添加一套汇率；
*参数：
*	无
*返回值：
*	无
*算法：
*	暴力
*/
void ExchangeRate::addExchangeRate()
{
	num++;
	Rate[num] = new double[_N];
	CurrencyType[num] = new string[_N];
	for (int i = 0; i < _N; i++)//init;
	{
		Rate[num][i] = 0;
		CurrencyType[num][i] = "0";
	}
	int n = 0;
	cout << "请输货币1:";
	cin >> CurrencyType[num][n];
	while (CurrencyType[num][n] != "0")//直到输入货币金额为0为止，不停地在一套新汇率中添加单项汇率；
	{
		cout << "请输入汇率" << n + 1 << ":";
		cin >> Rate[num][n];
		n++;
		cout << "请输入货币" << n + 1 << ":";
		cin >> CurrencyType[num][n];
	}
	if (CurrencyType[num][0] == "0")//如果输入的第一项汇率就为0，则保持汇率套数不变，之前+1；
		num--;
}

/*
*功能：删除第i套汇率；
*参数：
*	i：一个整数
*返回值：
*	无
*算法：
*	暴力
*/
void ExchangeRate::deleteExchangeRate(int i)
{
	if (i < num && i > 0)//判断删除的套数编号是否符合规则，这是删除非最后一套汇率的情况；
	{
		for (int j = i; j < num; j++)//将第i套汇率以后的汇率前移一位；
		{
			for (int k = 0; k < _N; k++)
			{
				if (CurrencyType[j][k] != "0" || CurrencyType[j + 1][k] != "0")
				{
					Rate[j][k] = Rate[j + 1][k];
					CurrencyType[j][k] = CurrencyType[j + 1][k];
				}
				else//删除原来的最后一套；
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
	//如果删除的是最后一套；
	delete[] Rate[num];
	delete[] CurrencyType[num];
	Rate[num] = { NULL };
	CurrencyType[num] = { NULL };
	num--;
}

/*
*功能：重设第i套汇率中的第j项；
*参数：
*	i，j：两个整数
*返回值：
*	无
*算法：
*	无
*/
void ExchangeRate::resetExchangeRate(int i,int j)
{
	cout << "请重新输入货币" << j << ":";
	cin >> CurrencyType[i][j-1];
	cout << "请重新输入汇率" << j << ":";
	cin >> Rate[i][j - 1];
}

/*
*功能：重设第i套汇率中的s货币汇率；
*参数：
*	i：一个整数；s：一个string
*返回值：
*	无
*算法：
*	暴力
*/
void ExchangeRate::resetExchangeRate(int i, string s)
{
	for (int j = 0; j < _N; j++)
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

/*
*功能：重设第i套汇率；
*参数：
*	i：一个整数
*返回值：
*	无
*算法：
*	暴力
*/
void ExchangeRate::addExchangeRate(int i)
{
	for (int j = 0; j < _N; j++)
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

/*
*功能：展示输出第i套汇率；
*参数：
*	i：一个整数
*返回值：
*	无
*算法：
*	无
*/
void ExchangeRate::showExchangeRate(int i)
{
	if (i <= 0 || i > num)//编号不在范围内
	{
		cout << "汇率访问操作出错！" << endl;//输出提示信息并返回；
		return;
	}
	for (int j = 0; j < _N; j++)
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
	for (int i = 1; i < _N; i++)
	{
		if(Rate[i]!=NULL)
		delete[] Rate[i];
		if(CurrencyType[i]!=NULL)
		delete[] CurrencyType[i];
	}
}

/*
*功能：在SingleMoney等类中实际运用时选择相应的某套汇率；
*参数：
*	n：一个整数
*返回值：
*	无
*算法：
*	无
*/
void ExchangeRate::select(int n)
{
	choice = n;
}

int ExchangeRate::num = 0;

double* ExchangeRate::Rate[_N] = { NULL };

string* ExchangeRate::CurrencyType[_N] = { NULL };

int ExchangeRate::choice = 1;
