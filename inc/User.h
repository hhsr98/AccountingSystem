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
	vector<Commodity*>* vec_Commodity;
	vector<List*> vec_List;
	vector<PayingEntry*> vec_PayingEntry;
	vector<MultiList*> Multilist;
	Filter* filter;
public:
    void showAllVector()
    {

    }
    void addCommVector(vector<Commodity*>* p)
    {
        vec_Commodity=p;
    }
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
		commodity->setUnit(unit);//不太懂这个unit该怎么构造...

		cout << "商店名称:";
		std::string shop_name;
		cin >> shop_name;
		Shop* shop = new Shop(shop_name);
		commodity->setShop(shop);

		vec_Commodity->push_back(commodity);
	}

	const vector<Commodity*> getCommodity() const
	{
		return *vec_Commodity;
	}

	void setFilter()
	{
		cout << "最低金额与最高金额:";
		double start_money, end_money;
		cin >> start_money >> end_money;
		filter = new priceFilter(nullptr, SingleMoney(start_money, "CNY"), SingleMoney(end_money, "CNY"));
	}

	void addList()
	{
		setFilter();
		//List* list = new List(vec_Commodity);
		List* list = new List(filter);
		vec_List.push_back(list);
	}

	void addPayingEntry(int i)
	{
		int num;
		cout << "人数:";
		cin >> num;
		PayingEntry* paying_entry=new PayingEntry((*vec_Commodity)[i], num, false);
		vec_PayingEntry.push_back(paying_entry);
	}

	void addMultiList()
	{
		string list_name;
		cout << "账单名称:";
		cin >> list_name;
		//MultiList* multilist = new MultiList(list_name);
		//for (int i = 0; i < vec_PayingEntry.size(); i++)
			//multilist->add_entry(vec_PayingEntry[i]);
	}

	void show(string type, int i)
	{
		DisplayImp* display = new CmdImp;
		if (type == "commodity")
		{
		    if(i==-1)
            {
                for(auto r: *vec_Commodity)
                    display->show(r);
            }
            else
            {
                display->show((*vec_Commodity)[i]);
            }

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

		else if (type == "paying_entry")
		{

		}
	}
};

#endif
