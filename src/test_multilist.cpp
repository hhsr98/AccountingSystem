#include<iostream>
#include<map>
#include<cstring>
#include "../inc/Commodity.h"
#include<vector>
#include"../inc/PayingEntry.h"
#include"../inc/MultiList.h"
using namespace std;

int main() {
	//�Զ�����rate
	Commodity com;
	string a="�㽶";
	com.setCommodityName(a);
	com.setQuantity(3);
	double b=100;
	SingleMoney m(b,"CNY");
	com.setUnitPrice(m);
	PayingEntry pay(&com,5,0);//������5���˲���ĸ�����Ŀ�����Զ�����rate���˴�����������Լ��������
	MultiList Mul("Qian");
	Mul.add_entry(&pay);
	Mul.set_topay();
	Mul.show_topay();//��η���
	map<vector<string>,double>temp=Mul.get_how_to_pay();
	map<vector<string>,double>::iterator iter;
	for(iter=temp.begin();iter!=temp.end();iter++)
	{
  		cout<<iter->first[0]<<"֧����"<<iter->first[1]<<iter->second<<endl;
	}
	//�ֶ�����Ӧ�����
	Commodity com;
	string a="�㽶";
	com.setCommodityName(a);
	com.setQuantity(3);
	double b=100;
	SingleMoney m(b,"CNY");
	com.setUnitPrice(m);
	PayingEntry pay(&com,5,1);//������5���˲���ĸ�����Ŀ�����ֶ�����Ӧ�����˴�����������Լ��������������Ӧ�����
	MultiList Mul("Qian");
	Mul.add_entry(&pay);
	Mul.set_topay();
	Mul.show_topay();//��η���
	map<vector<string>,double>temp=Mul.get_how_to_pay();
	map<vector<string>,double>::iterator iter;
	for(iter=temp.begin();iter!=temp.end();iter++)
	{
  		cout<<iter->first[0]<<"֧����"<<iter->first[1]<<iter->second<<endl;
	}
	system("pause");
	return 0;
}
