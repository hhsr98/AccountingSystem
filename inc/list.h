#ifndef LIST_H
#define LIST_H
#include "Commodity.h"
#include "Filter.h"
#include <cstring>
#include<iostream>
#include<vector>
class Filter;
class List {
private:
	vector<Commodity*> vec_commodity;//��ȥСƱɨ���˵��⣬�����˵�������Ʒֱ�����ɣ����˵������һ�����ʵ�
	vector<List*> vec_sublist;//����СƱɨ���˵�
	SingleMoney _sum;
	int num_commodity;
	int num_sublist;
public:
	List(Filter* filter);
	SingleMoney Sum();
	const vector<Commodity*> get_CommodityList ()const;
	const vector<List*>get_Sublist()const;
};

#endif