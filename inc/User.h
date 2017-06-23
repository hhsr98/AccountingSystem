/********************************
名称：User.h
作者：尹一帆
时间：2017-06-22
描述：一个用于展示操作的简单的用户类
版权：自行完成
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
	*功能：用户在cmd下添加商品信息；
	*参数：
	*	无
	*返回值：
	*	无
	*算法：
	*	无
	*/
	void addCommodity()
	{
		Commodity* commodity = new Commodity();

		cout << "商品名:";
		std::string commodity_name;
		cin >> commodity_name;
		commodity->setCommodityName(commodity_name);

		cout << "商品单价:";
		double amount;
		std::string type;
		cin >> amount >> type;
		SingleMoney single_money(amount, type);
		commodity->setUnitPrice(single_money);

		Date date;
		commodity->setDate(date);

		cout << "商品折扣:";
		double discount;
		cin >> discount;
		commodity->setDiscount(discount);

		cout << "商品数量:";
		double quantity;
		cin >> quantity;
		commodity->setQuantity(quantity);

		Unit unit;
		commodity->setUnit(unit);//Unit默认无单位；

		cout << "商店名称:";
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

	//添加filter筛选；
	void setFilter()
	{
		cout << "最低金额与最高金额:";
		double start_money, end_money;
		cin >> start_money >> end_money;
		filter = new priceFilter(nullptr, SingleMoney(start_money, "CNY"), SingleMoney(end_money, "CNY"));
	}

	//添加List；
	void addList()
	{
		setFilter();
		List* list = new List(filter);
		vec_List.push_back(list);
	}

	//添加PayingEntry；
	void addPayingEntry(int i)
	{
		int num;
		cout << "人数:";
		cin >> num;
		PayingEntry* paying_entry=new PayingEntry(vec_Commodity[i], num, false);
		vec_PayingEntry.push_back(paying_entry);
	}

	//添加多人账单；
	void addMultiList()
	{
		string list_name;
		cout << "账单名称:";
		cin >> list_name;
		MultiList* multilist = new MultiList(list_name);
		for (int i = 0; i < vec_PayingEntry.size(); i++)
			multilist->add_entry(vec_PayingEntry[i]);
	}

	/*
	*功能：在cmd下输出相应信息；
	*参数：
	*	i：一个整数；type：一个string
	*返回值：
	*	无
	*算法：
	*	无
	*/
	void show(string type, int i)
	{
		DisplayImp* display = new CmdImp;
		if (type == "commodity")
		{
			if (i >= 0 && i < vec_Commodity.size())
				display->show(vec_Commodity[i]);//i在范围内则输出第i个商品；
			else
				for (int j = 0; j < vec_Commodity.size(); j++)
					display->show(vec_Commodity[j]);//否则输出全部商品；
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