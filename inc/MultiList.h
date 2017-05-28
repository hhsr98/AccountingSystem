#ifndef MULTILIST_H
#define MULTILIST_H
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include"PayingEntry.h"
#include"SmartPtr.h"
using namespace std;
class MultiList {
private:
	string List_name;
	vector<SmartPtr<PayingEntry>> vec_entry;//��Ÿ�����Ŀ��ļ���ָ�������
	map<string,double>person_topay,person_topaycopy;//��Ŷ����˵����漰�������˵�Ӧ�����
	int num_entry;//������Ŀ����Ŀ
	int num_person;//�����˵����漰��������
public:
	MultiList(string name);
	void add_entry(Commodity* com,int num);//�ڶ����˵�����Ӹ�����Ŀ
	double get_topay(string name);//��ȡĳ���˵�Ӧ�����
	void show_topay();//������ת�˵ķ���
	void set_topay();//����person_topay�����������˵�Ӧ�����
};

#endif 