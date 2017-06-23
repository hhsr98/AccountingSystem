/******************************************
���ƣ�SingleMoney.h
���ߣ���һ��
ʱ�䣺2017-06-22
������һ�������������ֵĵ����ֻ����࣬�ں���������������Լ���ʾ�����ͻ���ת�������ȵȣ�
��Ȩ���Լ�
*******************************************/
//ע��ʹ��ǰ�ȹ���һ��ExchangeRate�ࣻ

#ifndef SingleMoney_H
#define SingleMoney_H
#include<string>
#include"ExchangeRate.h"

class SingleMoney
{
	friend class MultiMoney;//�Ա���MultiMoney�����SingleMoney��������뺯����
	std::string CurrencyTypeNow;//��ǰ�������ࣻ
	double SingleMoneyAmount;//��ǰ���ҽ�
public:
	SingleMoney(double single_money, std::string currency_type_now);//������Ӧ�����ֵĻ��ң�

	SingleMoney() = default;//Ĭ�Ϲ��캯����

	std::string Currency() const//���ص�ǰ�������ࣻ
	{
	    return CurrencyTypeNow;
	}
	double Money() const//���ص�ǰ���ҽ�
	{
	    return SingleMoneyAmount;
	}

	SingleMoney operator+(const SingleMoney& m) const;//���ص�������ӣ����ؽ��Ϊ��ǰ�������ͣ�

	SingleMoney operator-(const SingleMoney& m) const;//�����

	SingleMoney operator*(double x) const ;//�ҳˣ�

	friend SingleMoney operator*(double x, SingleMoney& m);//��ˣ�����ûʵ���������㣬ֻ�����Ӽ���

	SingleMoney operator/(double x) const ;//�����

	SingleMoney operator+=(const SingleMoney& m);//+=;

	SingleMoney operator-=(const SingleMoney& m);//-=;

	SingleMoney operator*=(double x); //*= ;

	SingleMoney operator/=(double x); // /=;

	friend bool operator<(const SingleMoney& m,const SingleMoney& n);																	
	friend bool operator>(const SingleMoney& m,const SingleMoney& n);
	friend bool operator<=(const SingleMoney& m,const SingleMoney& n);
	friend bool operator>=(const SingleMoney& m,const SingleMoney& n);//���ظ���ƫ���ϵ��

	double findRate(std::string name)const;//�ҵ���Ӧ��������Ķ�����һ��ʣ�

	double converseCurrency(std::string DstCurrency)const ;//�����Ҷһ�ΪĿ�����ͣ�

	SingleMoney& converseCurrencyPermanent(std::string DstCurrency);//����������ת��ΪĿ�����ͣ�

	void showSingleMoney();//���չʾ��ǰ��������ࣻ

	friend std::ostream& operator<<(std::ostream& os,const SingleMoney& money);//��������������

};

#endif

