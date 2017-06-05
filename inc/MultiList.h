#ifndef MULTILIST_H
#define MULTILIST_H
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include"PayingEntry.h"
class MultiList {
private:
	string List_name;
	vector<PayingEntry*> vec_entry;//��Ÿ�����Ŀ��ļ���ָ�������
	map<string,double>person_topay,person_topaycopy;//��Ŷ����˵����漰�������˵�Ӧ�����
	map<vector<string>,double>how_to_pay;//�����Aת����B����Ǯ
	int num_entry;//������Ŀ����Ŀ
	int num_person;//�����˵����漰��������
public:
	MultiList(string name);
	void add_entry(PayingEntry* payingentry);//�ڶ����˵�����Ӹ�����Ŀ
	double get_topay(string name);//��ȡĳ���˵�Ӧ�����
	void show_topay();//������ת�˵ķ���
	void set_topay();//����person_topay�����������˵�Ӧ�����
	const map<vector<string>,double> get_how_to_pay()const;
	const vector<PayingEntry*>get_vec_entry()const;
	const map<string,double>getperson_topaycopy()const;
	const std::string get_name()const;
	const int get_num()const;
};

#endif 