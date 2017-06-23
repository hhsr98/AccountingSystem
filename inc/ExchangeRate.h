/************************************
���ƣ�EXchangeRate.h
���ߣ���һ��
ʱ�䣺2017-06-22
������һ�������࣬��������Ĭ�ϻ��ʡ�������ӻ��ʵȲ���
��Ȩ���������
*************************************/
#ifndef CURRENCY_H
#define CURRENCY_H

#include<iostream>
#include<string>
const int _N=200;

class ExchangeRate
{
	friend class SingleMoney;//�Ա�SingleMoneyʹ�û��ʣ�
	static double* Rate[_N];//��Ż��ʵ����飻
	static std::string* CurrencyType[_N];//��ű��ֵ����飻
	static int num;//�ܻ���������
	static int choice;//ѡ��Ļ���������
public:

	ExchangeRate();//��ʼĬ�Ϲ��죻

	void addExchangeRate();//��������һ���µĻ��ʣ�

	void deleteExchangeRate(int i);//ɾ�����Ϊi��һ�׻��ʣ�

	void resetExchangeRate(int i,int j);//�����i�׻��ʵĵ�j�

	void resetExchangeRate(int i, std::string s);//�����i�׻����е�s���֣�

	void addExchangeRate(int i);//�ڵ�i�׻���������һ�

	void showExchangeRate(int i);//չʾ���ĳ�׻��ʣ�

	void showExchangeRate();//����ܻ���������

	void select(int n);//ѡ��һ�׻�����ʹ�ã�

	~ExchangeRate();

};


#endif
