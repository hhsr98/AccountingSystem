/*******************************
���ƣ�Display.cpp
���ߣ���һ��
ʱ�䣺2017-06-22
������Display.h��ʵ���ļ�
��Ȩ���������
********************************/
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

/*
*���ܣ���cmd����ʾ����˵��е���Ʒ��Ϣ�����˵�����֧�����˵����۵���򿪲�����
*������
*	list��һ��const List��ָ��
*����ֵ��
*	��
*�㷨��
*	��
*/
void CmdImp::show(const List* list)
{
	int i = 0;
	while (i < list->get_CommodityList().size())
	{
		show(list->get_CommodityList()[i]);
		i++;
	}

	int j = 0;
	while (j < list->get_Sublist().size())
	{
		cout << "Sublist" << j + 1 << endl;
		j++;
	}

	List temp = *list;
	cout << "sublist������ܼ�:" << temp.Sum() << endl;

	if (list->get_Sublist().size() != 0)//�ж��Ƿ������˵���
	{
		vector<char> operate;//��¼һϵ�в���;
		char opr;
		cout << "������Ҫ�鿴�����˵���ţ�";
		std::cin >> opr;
		while (int(opr) - '0' <= list->get_Sublist().size() && opr > '0')//�ж������Ƿ�Ϸ���
		{
			operate.push_back(opr);
			for (int i = 0; i < list->get_Sublist().size();i++)
			{
				int num = 0;//��������;
				for (int j = 0; j < operate.size(); j++)
				{
					if (int(operate[j]) - '1' == i)
					{
						num++;
					}
				}
				if (num % 2)//��ͬһ���˵���������������ʾ��;
				{
					show(list->get_Sublist()[i]);
				}
				else
					cout << "Sublist" << i + 1 << endl;
			}
			cout << "������Ҫ�鿴�����˵���ţ�";
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

/*
*���ܣ�չʾ���һϵ��ĸ�˵�����֧�ָ���ĸ�˵������˵��Ĳ鿴���۵���
*������
*	list��һ��Listָ���vector
*����ֵ��
*	��
*�㷨��
*	��
*/
void CmdImp::display(vector<List*> list)
{
	for (int k = 0; k != list.size(); k++)
	{
		cout << "ĸ�˵�" << k + 1 << endl;
		int i = 0;
		while (i < list[k]->get_CommodityList().size())
		{
			show(list[k]->get_CommodityList()[i]);
			i++;
		}

		int j = 0;
		while (j < list[k]->get_Sublist().size())
		{
			cout << "Sublist" << j + 1 << endl;
			j++;
		}

		List temp = *list[k];
		cout << "sublist������ܼ�:" << temp.Sum() << endl;
	}

	cout << "������Ҫ�鿴���˵���ĸ�˵����:";
	int n = 0;
	cin >> n;
	while (n > 0 && n <= list.size())//�ж������Ƿ�Ϸ���
	{
		show(list[n - 1]);
		cout << "������Ҫ�鿴���˵���ĸ�˵����:";
		cin >> n;
	}
	return;
}

