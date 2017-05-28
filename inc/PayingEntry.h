#ifndef PAYINGENTRY
#define PAYINGENTRY
#include "Commodity.h"
#include <map>
#include<cstring>
#include<iostream>
using namespace std;
class PayingEntry {
private:
	Commodity* _com;//��Ʒ��Ϣ
	map<string,double> person_rate;//��������Լ���Ӧ�ı���
	map<string,double>person_price;//��������Լ���Ӧ��ʵ�ʸ���
	static map<string,double> person_topay;//��̬���������������������Ҫ֧����Ǯ
	static int num;//�����˵����漰��������
	double total_num;//�ܸ���
	int person_num;//�漰����
public:
	PayingEntry(Commodity* com,int num);
	void set_map();//���� person_rate
	double setRate(string name);//�������
	double set_total_sum();//�����ܸ���
	void set_static(string name);//�жϸ������Ƿ��Ѿ�¼��person_topay��
	const map<string,double> get_person_rate_list() const;
	const map<string,double> get_person_topay() const;
	const double get_total_num() const;
	const Commodity* get_Commodity()const;
	const int get_person_num()const;
	const int get_total_person_num()const;
};
#endif