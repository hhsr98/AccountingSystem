#ifndef LIST_H
#define LIST_H
#include "Commodity.h"
#include "Filter.h"
#include <cstring>
#include<iostream>
#include<vector>
class List {
private:
	vector<Commodity*> vec_commodity;//除去小票扫描账单外，其他账单都是商品直接生成，及账单最多套一层子帐单
	vector<List*> vec_sublist;//超市小票扫描账单
	SingleMoney _sum;
	int num_commodity;
	int num_sublist;
public:
	List();
	SingleMoney Sum();
	const Commodity* get_Commodity(int i) const;//返回第i个商品
	const Commodity* get_SublistCommodity(int i,int j) const;//返回第i个子帐单中第j个商品
};
#endif