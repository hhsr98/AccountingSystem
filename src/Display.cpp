#include"../inc/Display.h"
using namespace std;

void CmdImp::show(const Commodity* commodity)
{
	Commodity* tempCommodity =new Commodity(*commodity);
	SingleMoney* temp1 = new SingleMoney(commodity->UnitPrice());
	Shop* temp2 = new Shop(commodity->Shop());
	SingleMoney* temp3 =new SingleMoney (tempCommodity->TotalPrice());
	SingleMoney* temp4 =new SingleMoney( tempCommodity->OriginalUnitPrice());

	cout << commodity->CommodityName() << " ";
	temp1->showSingleMoney();
	cout << commodity->Quantity() << " " << commodity->Unit() << " ";
	cout << commodity->Discount() << " ";
	temp4->showSingleMoney();
	cout << " ";
	cout << commodity->Date() << " ";
	cout << temp2->getShopName() << " ";

	temp3->showSingleMoney();
	cout << endl;
	delete tempCommodity, temp1, temp2, temp3, temp4;
}

void CmdImp::show(Commodity* m)
{
	const Commodity* temp = m;
	show(temp);
	delete temp;
}

void CmdImp::show(const List* list)
{
	int i = 0;
	while (list->get_Commodity(i)!= NULL)
	{
		show(list->get_Commodity(i));
		i++;
	}
	int j = 0;
	while (list->get_Sublist(j) != NULL)
	{
		cout << "Sublist" << j + 1 << endl;
		j++;
	}
	List temp = *list;
	temp.Sum().showSingleMoney();
}

void CmdImp::show(List* list)
{
	const List* temp = new List(*list);
	show(temp);
	delete temp;
}


void CmdImp::display(vector<List*> list)
{
	vector<List*>::iterator it;
	for (it = list.begin(); it != list.end(); it++)
	{
		show(*it);
	}

	cout << "请输入要查看子账单的母账单序号:";
	char n ='0';
	cin >> n;
	while (n > '0' && int(n)-'0' <= list.size())
	{
		if (list[int(n)-'0']->get_Sublist(0) != NULL)//判断是否有子账单；
		{
			vector<char> operate;//记录一系列操作;
			char opr = '1';
			cout << "请输入要查看的子账单编号：";
			cin >> opr;
			while (int(opr)-'0' <= sublist_num || opr>'0')
			{
				vector<char>::iterator it1;
				operate.push_back(opr);
				int num = 0;//操作计数;
				for (char i = '1'; int(i) - '0' <= sublist_num; i++)
				{
					for (it1 = operate.begin; it1 != operate.end; it1++)
					{
						if (*it1 == i)
						{
							num++;
						}
					}
					if (num % 2)//对同一子账单操作奇数次则显示它;
					{
						show(list[int(opr)-'0']->get_Sublist(int(opr) - '0'));
					}
				}
				cout << "请输入要查看的子账单编号：";
				cin >> opr;
			}
		}
		cout << "请输入要查看子账单的母账单序号:";
		cin >> n;
	}
	return;
}

/*void CmdImp::display(const List* list)
{
	List* temp = new List(*list);
	display(temp);
	delete temp;
}*/