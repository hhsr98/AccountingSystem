/************************************
���ƣ�EXchangeRate.cpp
���ߣ���һ��
ʱ�䣺2017-06-22
�������������ʵ���ļ�
��Ȩ���������
*************************************/
#include"../inc/ExchangeRate.h"
using namespace std;

/*
*���ܣ�Ĭ�Ϲ���һ�׻��ʣ�
*������
*	��
*����ֵ��
*	��
*�㷨��
*	����
*/
ExchangeRate::ExchangeRate()
{
	num++;//ÿ����һ�׻��ʣ��ܻ�����+1��
	Rate[1] = new double[_N]{ 100,88.792,689.770,514.677,853.253,6.212,517.418,730.456,0.609,19.947,22.541 };
	CurrencyType[1] = new string[_N]{ "CNY", "HKD", "USD", "CAD", "GBP", "JPY", "AUD", "EUR", "KRW", "THB", "TWD" };
	for (int i = 11; i < _N; i++)//��ʼ����
	{
		Rate[1][i] = 0;
		CurrencyType[1][i] = "0";
	}
}

/*
*���ܣ��������һ�׻��ʣ�
*������
*	��
*����ֵ��
*	��
*�㷨��
*	����
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
	cout << "�������1:";
	cin >> CurrencyType[num][n];
	while (CurrencyType[num][n] != "0")//ֱ��������ҽ��Ϊ0Ϊֹ����ͣ����һ���»�������ӵ�����ʣ�
	{
		cout << "���������" << n + 1 << ":";
		cin >> Rate[num][n];
		n++;
		cout << "���������" << n + 1 << ":";
		cin >> CurrencyType[num][n];
	}
	if (CurrencyType[num][0] == "0")//�������ĵ�һ����ʾ�Ϊ0���򱣳ֻ����������䣬֮ǰ+1��
		num--;
}

/*
*���ܣ�ɾ����i�׻��ʣ�
*������
*	i��һ������
*����ֵ��
*	��
*�㷨��
*	����
*/
void ExchangeRate::deleteExchangeRate(int i)
{
	if (i < num && i > 0)//�ж�ɾ������������Ƿ���Ϲ�������ɾ�������һ�׻��ʵ������
	{
		for (int j = i; j < num; j++)//����i�׻����Ժ�Ļ���ǰ��һλ��
		{
			for (int k = 0; k < _N; k++)
			{
				if (CurrencyType[j][k] != "0" || CurrencyType[j + 1][k] != "0")
				{
					Rate[j][k] = Rate[j + 1][k];
					CurrencyType[j][k] = CurrencyType[j + 1][k];
				}
				else//ɾ��ԭ�������һ�ף�
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
	//���ɾ���������һ�ף�
	delete[] Rate[num];
	delete[] CurrencyType[num];
	Rate[num] = { NULL };
	CurrencyType[num] = { NULL };
	num--;
}

/*
*���ܣ������i�׻����еĵ�j�
*������
*	i��j����������
*����ֵ��
*	��
*�㷨��
*	��
*/
void ExchangeRate::resetExchangeRate(int i,int j)
{
	cout << "�������������" << j << ":";
	cin >> CurrencyType[i][j-1];
	cout << "�������������" << j << ":";
	cin >> Rate[i][j - 1];
}

/*
*���ܣ������i�׻����е�s���һ��ʣ�
*������
*	i��һ��������s��һ��string
*����ֵ��
*	��
*�㷨��
*	����
*/
void ExchangeRate::resetExchangeRate(int i, string s)
{
	for (int j = 0; j < _N; j++)
	{
		if (CurrencyType[i][j] == s)
		{
			cout << "�������������" << j+1 << ":";
			cin >> CurrencyType[i][j];
			cout << "�������������" << j+1 << ":";
			cin >> Rate[i][j];
			return;
		}
	}
}

/*
*���ܣ������i�׻��ʣ�
*������
*	i��һ������
*����ֵ��
*	��
*�㷨��
*	����
*/
void ExchangeRate::addExchangeRate(int i)
{
	for (int j = 0; j < _N; j++)
	{
		if (Rate[i][j] == 0)
		{
			cout << "���������" << j + 1 << ":";
			cin >> CurrencyType[i][j];
			cout << "���������" << j + 1 << ":";
			cin >> Rate[i][j];
			return;
		}
	}
}

/*
*���ܣ�չʾ�����i�׻��ʣ�
*������
*	i��һ������
*����ֵ��
*	��
*�㷨��
*	��
*/
void ExchangeRate::showExchangeRate(int i)
{
	if (i <= 0 || i > num)//��Ų��ڷ�Χ��
	{
		cout << "���ʷ��ʲ�������" << endl;//�����ʾ��Ϣ�����أ�
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
	cout << "һ����" << num << "�׻���" << endl;
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
*���ܣ���SingleMoney������ʵ������ʱѡ����Ӧ��ĳ�׻��ʣ�
*������
*	n��һ������
*����ֵ��
*	��
*�㷨��
*	��
*/
void ExchangeRate::select(int n)
{
	choice = n;
}

int ExchangeRate::num = 0;

double* ExchangeRate::Rate[_N] = { NULL };

string* ExchangeRate::CurrencyType[_N] = { NULL };

int ExchangeRate::choice = 1;
