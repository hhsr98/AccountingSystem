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
	std::vector<Commodity*> vec_commodity;//��ȥСƱɨ���˵��⣬�����˵�������Ʒֱ�����ɣ����˵������һ�����ʵ�
	std::vector<List*> vec_sublist;//����СƱɨ���˵�
	SingleMoney _sum;
	int num_commodity;
	int num_sublist;
public:
	List(Filter* filter);
	/*List(Commodity* commodity)
	{
		vec_commodity.push_back(commodity);
	}
	List(List* list)
	{
		vec_sublist.push_back(list);
	}
	List(vector<Commodity*> commodity)
	{
		vec_commodity = commodity;
	}
	List(vector<List*> sublist)
	{
		vec_sublist = sublist;
	}*/
	SingleMoney Sum();
	const std::vector<Commodity*> get_CommodityList ()const;
	const std::vector<List*>get_Sublist()const;
};

#endif
