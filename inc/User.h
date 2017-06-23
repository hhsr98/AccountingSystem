/********************************
���ƣ�User.h
���ߣ���һ��
ʱ�䣺2017-06-22
������һ������չʾ�����ļ򵥵��û���
��Ȩ���������
*********************************/
#ifndef USER_H
#define USER_H
#include"Filter.h"
#include"MultiList.h"
#include"Remark.h"
#include"PayingEntry.h"
#include"Display.h"
#include<vector>

class User
{
protected:
	vector<Commodity*> vec_Commodity;
	vector<List*> vec_List;
	vector<PayingEntry*> vec_PayingEntry;
	vector<MultiList*> Multilist;
	Filter* filter;
public:

	/*
	*���ܣ��û���cmd�������Ʒ��Ϣ��
	*������
	*	��
	*����ֵ��
	*	��
	*�㷨��
	*	��
	*/
	void addCommodity()
	{
		Commodity* commodity = new Commodity();

		cout << "��Ʒ��:";
		std::string commodity_name;
		cin >> commodity_name;
		commodity->setCommodityName(commodity_name);

		cout << "��Ʒ����:";
		double amount;
		std::string type;
		cin >> amount >> type;
		SingleMoney single_money(amount, type);
		commodity->setUnitPrice(single_money);

		Date date;
		commodity->setDate(date);

		cout << "��Ʒ�ۿ�:";
		double discount;
		cin >> discount;
		commodity->setDiscount(discount);

		cout << "��Ʒ����:";
		double quantity;
		cin >> quantity;
		commodity->setQuantity(quantity);

		Unit unit;
		commodity->setUnit(unit);//UnitĬ���޵�λ��

		cout << "�̵�����:";
		std::string shop_name;
		cin >> shop_name;
		Shop* shop = new Shop(shop_name);
		commodity->setShop(shop);

		vec_Commodity.push_back(commodity);
	}

	const vector<Commodity*> getCommodity() const
	{
		return vec_Commodity;
	}

	//���filterɸѡ��
	void setFilter()
	{
		cout << "��ͽ������߽��:";
		double start_money, end_money;
		cin >> start_money >> end_money;
		filter = new priceFilter(nullptr, SingleMoney(start_money, "CNY"), SingleMoney(end_money, "CNY"));
	}

	//���List��
	void addList()
	{
		setFilter();
		List* list = new List(filter);
		vec_List.push_back(list);
	}

	//���PayingEntry��
	void addPayingEntry(int i)
	{
		int num;
		cout << "����:";
		cin >> num;
		PayingEntry* paying_entry=new PayingEntry(vec_Commodity[i], num, false);
		vec_PayingEntry.push_back(paying_entry);
	}

	//��Ӷ����˵���
	void addMultiList()
	{
		string list_name;
		cout << "�˵�����:";
		cin >> list_name;
		MultiList* multilist = new MultiList(list_name);
		for (int i = 0; i < vec_PayingEntry.size(); i++)
			multilist->add_entry(vec_PayingEntry[i]);
	}

	/*
	*���ܣ���cmd�������Ӧ��Ϣ��
	*������
	*	i��һ��������type��һ��string
	*����ֵ��
	*	��
	*�㷨��
	*	��
	*/
	void show(string type, int i)
	{
		DisplayImp* display = new CmdImp;
		if (type == "commodity")
		{
			if (i >= 0 && i < vec_Commodity.size())
				display->show(vec_Commodity[i]);//i�ڷ�Χ���������i����Ʒ��
			else
				for (int j = 0; j < vec_Commodity.size(); j++)
					display->show(vec_Commodity[j]);//�������ȫ����Ʒ��
		}

		else if (type == "list")
		{
			if (i >= 0 && i < vec_List.size())
				display->show(vec_List[i]);
			else
			{
				display->display(vec_List);
			}
		}
	}	
};

#endif