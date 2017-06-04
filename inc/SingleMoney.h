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

	std::string Currency() const
	{
	    return CurrencyTypeNow;
	}
	double Money() const
	{
	    return SingleMoneyAmount;
	}

	SingleMoney operator+(const SingleMoney& m) const;//���ض������ӣ����ؽ��Ϊ��ǰ�������ͣ�

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
	friend bool operator>=(const SingleMoney& m,const SingleMoney& n);

	//void addCurrencyTypeAmount();//�û���ӻ������ࣻ

	double findRate(std::string name)const;//�ҵ���Ӧ��������Ķ�����һ��ʣ�

	double converseCurrency(std::string DstCurrency)const ;//�����Ҷһ�ΪĿ�����ͣ�

	SingleMoney& converseCurrencyPermanent(std::string DstCurrency);//����������ת��ΪĿ�����ͣ�

	void showSingleMoney();//���չʾ��ǰ��������ࣻ

	friend std::ostream& operator<<(std::ostream& os,const SingleMoney& money);

};
bool operator<(const SingleMoney& m,const SingleMoney& n);
bool operator>(const SingleMoney& m,const SingleMoney& n);
bool operator<=(const SingleMoney& m,const SingleMoney& n);
bool operator>=(const SingleMoney& m,const SingleMoney& n);
#endif

