#ifndef MULTILIST_H
#define MULTILIST_H
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include"PayingEntry.h"
class MultiList {
private:
	std::string List_name;
	std::vector<PayingEntry*> vec_entry;//��Ÿ�����Ŀ��ļ���ָ�������
	std::map<std::string,double>person_topay,person_topaycopy;//��Ŷ����˵����漰�������˵�Ӧ�����
	std::map<std::vector<std::string>,double>how_to_pay;//�����Aת����B����Ǯ
	int num_entry;//������Ŀ����Ŀ
	int num_person;//�����˵����漰��������
public:
	MultiList(std::string name);
	void add_entry(PayingEntry* payingentry);//�ڶ����˵�����Ӹ�����Ŀ
	double get_topay(std::string name);//��ȡĳ���˵�Ӧ�����
	void show_topay();//������ת�˵ķ���
	void set_topay();//����person_topay�����������˵�Ӧ�����
	const std::map<std::vector<std::string>,double> get_how_to_pay()const;
	const std::vector<PayingEntry*>get_vec_entry()const;
	const std::map<std::string,double>getperson_topaycopy()const;
	const std::string get_name()const;
	const int get_num()const;
};

#endif
