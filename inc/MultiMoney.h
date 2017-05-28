#ifndef MULTIMONEY_H
#define MULTIMONEY_H
#include"SingleMoney.h"
#include<iostream>
#define N 200
using namespace std;

class MultiMoney
{
	SingleMoney single[N];
	int num{ 0 };
public:
	MultiMoney();//���죻

	//SingleMoney converseSingleMoney();

	void converseSingleMoney(string type);//���б���ת��Ϊָ�������֣�

	void show();//չʾ�����

	MultiMoney& operator+(SingleMoney& m);//���һ�

	//MultiMoney operator-(MultiMoney& m);

	MultiMoney& operator*(double x);//�ҳˣ�

	friend MultiMoney& operator*(double x, MultiMoney& m)//��ˣ�
	{
		return m*x;
	}

	MultiMoney& operator/(double x);

	MultiMoney& operator+=(SingleMoney& m);//���һ�

	MultiMoney& operator*=(double x);

	MultiMoney& operator/=(double x);

	SingleMoney sumPart(string DstCurrency);//��ĳ�ֻ������;

	SingleMoney sum(string DstCurrency);//���������Ϊĳ����;

	~MultiMoney() = default;

};


#endif
