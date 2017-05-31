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
	std::vector<Commodity*> vec_commodity;//除去小票扫描账单外，其他账单都是商品直接生成，及账单最多套一层子帐单
	std::vector<List*> vec_sublist;//超市小票扫描账单
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
