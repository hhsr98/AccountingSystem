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
	vector<Commodity*> vec_commodity;//除去小票扫描账单外，其他账单都是商品直接生成，及账单最多套一层子帐单
	vector<List*> vec_sublist;//超市小票扫描账单
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