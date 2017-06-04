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

	//�����Ʒ���˵��У�������Filter����������ӳɹ�������true�����ʧ���򷵻�false
	bool addCommodity(Commodity *com);

	//����Ʒ���˵��У�ɾ����Ʒ�������ڣ���ִ���κβ���
	void deleteCommodity(Commodity *com);

	//�����Ʒ�Ƿ�����˵���Filter��Ҫ���Ƿ���true�����Ƿ���false
	bool isValidCommodity(Commodity *com) const;

	//����Filter�����¼��������Ʒ
	void setFilter(const Filter *f);

	//����Filterָ�룬const���ͷ�ֹ��filter���������
	const Filter* getFilter() const;

	//�������˵������˵������������˵��ļ��
	void addSublist(List *sub);


	SingleMoney Sum()const;

	std::vector<Commodity*> get_CommodityList ()const;

	std::vector<List*>get_Sublist()const;
};

#endif
