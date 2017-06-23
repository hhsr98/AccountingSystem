#include"../inc/Display.h"
using namespace std;

void CmdImp::show(const Commodity* commodity)
{	
	cout << *commodity << endl;
}

void CmdImp::show(Commodity* m)
{
	const Commodity* temp = new Commodity(*m);
	show(temp);
	delete temp;
}

void CmdImp::show(const List* list)
{
	int i = 0;
	while (i < list->get_CommodityList().size())
	{
//		show(list->get_CommodityList()[i]);
		i++;
	}

	int j = 0;
	while (j < list->get_Sublist().size())
	{
		cout << "Sublist" << j + 1 << endl;
		j++;
	}

	List temp = *list;
	cout << "sublist以外的总价:" << temp.Sum() << endl;

	if (list->get_Sublist().size() != 0)//判断是否有子账单；
	{
		vector<char> operate;//记录一系列操作;
		char opr;
		cout << "请输入要查看的子账单编号：";
		std::cin >> opr;
		while (int(opr) - '0' <= list->get_Sublist().size() && opr > '0')
		{
			operate.push_back(opr);
			//cout << "Test:" << operate.size() << endl;
			for (int i = 0; i < list->get_Sublist().size();i++)
			{
				int num = 0;//操作计数;
				for (int j = 0; j < operate.size(); j++)
				{
					if (int(operate[j]) - '1' == i)
					{
						num++;
					}
				}
				//cout << "num:" << num << endl;
				if (num % 2)//对同一子账单操作奇数次则显示它;
				{
//					show(list->get_Sublist()[i]);
				}
				else
					cout << "Sublist" << i + 1 << endl;
			}
			cout << "请输入要查看的子账单编号：";
			std::cin >> opr;
		}
	}
}


void CmdImp::show(List* list)
{
	const List* temp = new List(*list);
	show(temp);
	delete temp;
}


void CmdImp::display(vector<List*> list)
{
	for (int k = 0; k != list.size(); k++)
	{
		cout << "母账单" << k + 1 << endl;
		int i = 0;
		while (i < list[k]->get_CommodityList().size())
		{
//			show(list[k]->get_CommodityList()[i]);
			i++;
		}

		int j = 0;
		while (j < list[k]->get_Sublist().size())
		{
			cout << "Sublist" << j + 1 << endl;
			j++;
		}

		List temp = *list[k];
		cout << "sublist以外的总价:" << temp.Sum() << endl;
	}

	cout << "请输入要查看子账单的母账单序号:";
	int n = 0;
	cin >> n;
	while (n > 0 && n <= list.size())
	{
		show(list[n - 1]);
		cout << "请输入要查看子账单的母账单序号:";
		cin >> n;
	}
	return;
}

