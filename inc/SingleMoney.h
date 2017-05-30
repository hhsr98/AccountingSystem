//SingleMoney.h ֻʵ����Ԥ��̶����ʣ�û��ʵʱ���ʣ�
#ifndef SingleMoney_H
#define SingleMoney_H
#include<string>
#include"ExchangeRate.h"

class SingleMoney
{
	friend class MultiMoney;
	std::string CurrencyTypeNow;//��ǰ�������ࣻ
	double SingleMoneyAmount;//��ǰ���ҽ�
public:
	SingleMoney(double single_money, std::string currency_type_now);

	SingleMoney() = default;

	SingleMoney operator+(SingleMoney& m);//���ض������ӣ����ؽ��Ϊ��ǰ�������ͣ�

	SingleMoney operator-(SingleMoney& m);//�����

	SingleMoney operator*(double x);//�ҳˣ�

	friend SingleMoney operator*(double x, SingleMoney& m);//��ˣ�����ûʵ���������㣬ֻ�����Ӽ���

	SingleMoney operator/(double x);//�����

	SingleMoney operator+=(SingleMoney& m);//+=;

	SingleMoney operator-=(SingleMoney& m);//-=;

	SingleMoney operator*=(double x); //*= ;

	SingleMoney operator/=(double x); // /=;

	bool operator<(SingleMoney& m);

	bool operator>(SingleMoney& m);

	bool operator<=(SingleMoney& m);

	bool operator>=(SingleMoney& m);

	//void addCurrencyTypeAmount();//�û���ӻ������ࣻ

	double findRate(std::string name);//�ҵ���Ӧ��������Ķ�����һ��ʣ�

	double converseCurrency(std::string DstCurrency);//�����Ҷһ�ΪĿ�����ͣ�

	SingleMoney& converseCurrencyPermanent(std::string DstCurrency);//����������ת��ΪĿ�����ͣ�

	void showSingleMoney();//���չʾ��ǰ��������ࣻ

};
#endif

