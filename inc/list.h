#ifndef LIST_H
#define LIST_H
#include "Commodity.h"
#include "Filter.h"
#include <cstring>
#include<iostream>
#include<vector>
class List {
private:
	vector<Commodity*> vec_commodity;//��ȥСƱɨ���˵��⣬�����˵�������Ʒֱ�����ɣ����˵������һ�����ʵ�
	vector<List*> vec_sublist;//����СƱɨ���˵�
	SingleMoney _sum;
	int num_commodity;
	int num_sublist;
public:
	List();
	SingleMoney Sum();
	const Commodity* get_Commodity(int i) const;//���ص�i����Ʒ
	const Commodity* get_SublistCommodity(int i,int j) const;//���ص�i�����ʵ��е�j����Ʒ
};
#endif