/********************************
���ƣ�MultiMoney.h
���ߣ���һ��
ʱ�䣺2017-06-22
�����������ܶ൥���ֻ��ҵĶ���ֻ�����
��Ȩ���������
*********************************/
#ifndef MULTIMONEY_H
#define MULTIMONEY_H
#include"../inc/SingleMoney.h"
#include<iostream>
const int N=200;

class MultiMoney
{
	SingleMoney single[N];
	int num{ 0 };
public:
	MultiMoney();//���죻

	void converseSingleMoney(std::string type);//���б���ת��Ϊָ�������֣�

	void show();//չʾ�����

	MultiMoney& operator+(SingleMoney& m);//���ؼӷ���

	MultiMoney& operator*(double x);//�ҳˣ�

	friend MultiMoney& operator*(double x, MultiMoney& m)//��ˣ�
	{
		return m*x;
	}

	MultiMoney& operator/(double x);

	MultiMoney& operator+=(SingleMoney& m);//���һ�

	MultiMoney& operator*=(double x);

	MultiMoney& operator/=(double x);

	SingleMoney sumPart(std::string DstCurrency);//��ĳ�ֻ������;

	SingleMoney sum(std::string DstCurrency);//���������Ϊĳ����;

	~MultiMoney() = default;

};


#endif
