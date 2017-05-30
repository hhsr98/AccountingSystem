#ifndef PAYINGENTRY
#define PAYINGENTRY
#include "Commodity.h"
#include <map>
#include<cstring>
#include<iostream>
class PayingEntry {
private:
	Commodity* _com;//��Ʒ��Ϣ
	std::map<std::string,double> person_rate;//��������Լ���Ӧ�ı���
	std::map<std::string,double>person_price;//��������Լ���Ӧ��ʵ�ʸ���
	static std::map<std::string,double> person_topay;//��̬���������������������Ҫ֧����Ǯ
	static int num;//�����˵����漰��������
	double total_num;//�ܸ���
	int person_num;//�漰����
	bool judge;//ѡ���Ƿ��ֶ��������
public:
	PayingEntry(Commodity* com,int num,bool judge);
	void set_map();//���� person_rate
	double is_set(std::string name);//�ֶ��������
	double setRate(std::string name);//�������
	double set_total_sum();//�����ܸ���
	void set_static(std::string name);//�жϸ������Ƿ��Ѿ�¼��person_topay��
	const std::map<std::string,double> get_person_rate_list() const;
	const std::map<std::string,double> get_person_topay() const;
	const double get_total_num() const;
	const Commodity* get_Commodity()const;
	const int get_person_num()const;
	const int get_total_person_num()const;
	const bool get_judge()const;
};
#endif
