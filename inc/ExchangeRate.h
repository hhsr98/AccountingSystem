//ʹ��SingleMoneyǰ�ȹ���һ�����õ�ExchangeRate�࣬����Ļ��ʡ����ҡ���������ָ��ĳ�׻��ʾ�Ϊstatic��
#ifndef CURRENCY_H
#define CURRENCY_H

#include<iostream>
#include<string>
const int _N=200;
using namespace std;

class ExchangeRate
{
	friend class SingleMoney;
	static double* Rate[_N];
	static string* CurrencyType[_N];
	static int num;//����������
	static int choice;//ѡ��Ļ���������
public:

	ExchangeRate();//��ʼ���죻

	void addExchangeRate();//����һ���µĻ��ʣ�

	void deleteExchangeRate(int i);//ɾ��ĳ�׻��ʣ�

	void resetExchangeRate(int i,int j);//�����i�׻��ʵĵ�i�

	void resetExchangeRate(int i, string s);

	void addExchangeRate(int i);//�ڵ�i�׻���������һ�

	void showExchangeRate(int i);//չʾ���ĳ�׻��ʣ�

	void showExchangeRate();//����ܻ���������

	void select(int n);//ѡ��һ�׻�����ʹ�ã�

	~ExchangeRate();

};


#endif
