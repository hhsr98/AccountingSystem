#include"../inc/PayingEntry.h"
#include<iostream>
using namespace std;
PayingEntry::PayingEntry(Commodity* com,int num):_com(com), person_num(num){
	set_map();
}

 map<string,double> PayingEntry::person_topay=map<string,double>();//���徲̬��Ա����

 int PayingEntry::num=0;//���徲̬��Ա��������¼�漰�˵�����

void PayingEntry::set_static(string name) {
	map<string,double>::iterator iter_r;
	bool judge=true;
	for(iter_r=person_topay.begin();iter_r!=person_topay.end();iter_r++) {//�ж��Ƿ��Ѿ����������
		if (string(iter_r->first)==string(name))
		{
			judge=false;
			break;
		}	
	}
	if(judge) {
		person_topay[name];
		num++;//�漰����������һ
	}
}

void PayingEntry::set_map() { //���ø�������Լ����
	string str1;
	double price;
	while(cin>>str1>>price) { //���������Լ���Ӧ�ĸ���
		person_rate[str1];
		person_price[str1]=price;
		set_static(str1);
	}

	total_num=set_total_sum();

    map<string,double>::iterator iter;
	for(iter=person_rate.begin();iter!=person_rate.end();iter++) {
		iter->second=setRate(iter->first);
	}
}

double PayingEntry::setRate(string name) { //�������������ظ��˶�Ӧ�ı���
	double average=total_num/person_num;//ÿ����Ӧ������Ŀ
	double paying_need=average-person_price[name];//ÿ���������Ҫ������Ŀ
	return paying_need/total_num;
}

double PayingEntry::set_total_sum() {//��ø�����ܽ��
	map<string,double>::iterator iter;
	double sum=0;
	for(iter=person_price.begin();iter!=person_price.end();iter++) {
		sum=sum+iter->second;
	}
	return sum;
}


const map<string,double> PayingEntry::get_person_rate_list() const {
	return person_rate;
}

const double PayingEntry::get_total_num() const {
	return total_num;
}

const Commodity* PayingEntry::get_Commodity()const {
	return _com;
}

const int PayingEntry::get_person_num()const {
	return person_num;
}

const map<string,double> PayingEntry::get_person_topay() const {
	return person_topay;
}

const int PayingEntry::get_total_person_num()const {
	return num;
}
