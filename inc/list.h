#ifndef LIST_H
#define LIST_H
#include "Commodity.h"
#include "MultiMoney.h"
#include "Filter.h"
#include <cstring>
#include<iostream>
#include<set>
#include<vector>

class Filter;
class Commodity;
class List {
private:
    std::string list_name;
    const Filter *criteria;
	std::set<Commodity*> vec_commodity;
	std::set<List*> vec_sublist;
public:
	List(const Filter* f):criteria(f),vec_commodity(),vec_sublist(){}

	List(const Filter *f,const List *faList,bool include_sublist=true);

	std::string ListName() const
	{return list_name;}

	void setListName(std::string name)
	{list_name=name;}

	//添加商品至账单中，若符合Filter的条件则添加成功，返回true，添加失败则返回false
	bool addCommodity(Commodity *com)
	{
	    if(criteria==nullptr|| criteria->isValid(com)) {vec_commodity.insert(com);return true;}
	    else return false;
	}

	//若商品在账单中，删除商品；若不在，不执行任何操作
	void deleteCommodity(Commodity *com);

	//检查商品是否符合账单的Filter的要求，是返回true，不是返回false
	bool isValidCommodity(Commodity *com) const
	{return (criteria==nullptr|| criteria->isValid(com));}

	//设置Filter并重新检查所有商品
	void setFilter(const Filter *f);

	//返回Filter指针，const类型防止对filter的意外更改
	const Filter* getFilter() const
	{return criteria;}

	//增加子账单，父账单并不负责子账单的检查
	void addSublist(List *sub)
	{vec_sublist.insert(sub);}

	//返回第i个商品，i从0起计数，若超出则返回nullptr
	Commodity* getCommodity(int i);

	List* getSubList(int i);

	SingleMoney Sum()const;

	std::set<Commodity*> get_CommodityList() const;

	std::set<Commodity*> get_CommodityList_All() const;

	std::set<List*>get_Sublist()const;
};

#endif
