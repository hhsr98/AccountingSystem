/*******************************************************
���ƣ�list.h
���ߣ�Ǯ��
����޸ģ�2017-06-21
�����������˵���ͷ�ļ����˵�Ϊһϵ��������Ӧ��������Ʒ
          �ļ��ϣ�ͬʱ�����������˵����˵������������
          �����ж����˵��е���Ʒ��Ҫʵ�ֲ�λ�������ɸ
          ѡӦ���û�ͨ�����˵������Ĺ�����ʵ�֡��˵���
          ��Ḻ��������ָ���Filter���������ʲ�Ҫ��ͬ
          һFilter�����첻ͬ���������費ͬ��List����
*******************************************************/
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
    const Filter *criteria; //ָ��Ϊ����Ὣ�κ���Ʒ����Ϊ��������
	std::set<Commodity*> vec_commodity;
	std::set<List*> vec_sublist;
public:
	List(const Filter* f):criteria(f),vec_commodity(),vec_sublist(){}

	List(const Filter *f,const List *faList,bool include_sublist=true);

	std::string ListName() const
	{return list_name;}

	void setListName(std::string name)
	{list_name=name;}

	//�����Ʒ���˵��У�������Filter����������ӳɹ�������true�����ʧ���򷵻�false
	bool addCommodity(Commodity *com)
	{
	    if(criteria==nullptr|| criteria->isValid(com)) {vec_commodity.insert(com);com->regObserverList(this); return true;}
	    else return false;
	}

	//����Ʒ���˵��У�ɾ����Ʒ�������ڣ���ִ���κβ���
	void deleteCommodity(Commodity *com);

	//�����Ʒ�Ƿ�����˵���Filter��Ҫ���Ƿ���true�����Ƿ���false
	bool isValidCommodity(Commodity *com) const
	{return (criteria==nullptr|| criteria->isValid(com));}

	//����Filter�����¼��������Ʒ
	void setFilter(const Filter *f);

	//����Filterָ�룬const���ͷ�ֹ��filter���������
	const Filter* getFilter() const
	{return criteria;}

	//�������˵������˵������������˵��ļ��
	void addSublist(List *sub)
	{vec_sublist.insert(sub);}

	//���ص�i����Ʒ��i��0��������������򷵻�nullptr
	Commodity* getCommodity(int i);

	List* getSubList(int i);

	SingleMoney Sum()const;

	std::set<Commodity*> get_CommodityList() const;

	std::set<Commodity*> get_CommodityList_All() const;

	std::set<List*>get_Sublist()const;

	std::set<List*>get_Sublist_All() const;
};

#endif
