#ifndef LIST_H
#define LIST_H
#include "Commodity.h"
#include "MultiMoney.h"
#include "Filter.h"
#include <cstring>
#include<iostream>
#include<vector>

class Filter;
class Commodity;
class List {
private:
    const Filter *criteria;
	std::vector<Commodity*> vec_commodity;
	std::vector<List*> vec_sublist;
public:
	List(const Filter* f);

	//添加商品至账单中，若符合Filter的条件则添加成功，返回true，添加失败则返回false
	bool addCommodity(Commodity *com);

	//若商品在账单中，删除商品；若不在，不执行任何操作
	void deleteCommodity(Commodity *com);

	//检查商品是否符合账单的Filter的要求，是返回true，不是返回false
	bool isValidCommodity(Commodity *com) const;

	//设置Filter并重新检查所有商品
	void setFilter(const Filter *f);

	//返回Filter指针，const类型防止对filter的意外更改
	const Filter* getFilter() const;

	//增加子账单，父账单并不负责子账单的检查
	void addSublist(List *sub);


	SingleMoney Sum()const;

	std::vector<Commodity*> get_CommodityList ()const;

	std::vector<List*>get_Sublist()const;
};

#endif
