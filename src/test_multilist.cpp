/*#include<iostream>
#include<map>
#include<cstring>
#include "../inc/Commodity.h"
#include<vector>
#include"../inc/PayingEntry.h"
#include"../inc/MultiList.h"
using namespace std;

int main() {
	//自动计算rate
	Commodity com;
	string a="香蕉";
	com.setCommodityName(a);
	com.setQuantity(3);
	double b=100;
	SingleMoney m(b,"CNY");
	com.setUnitPrice(m);
	PayingEntry pay(&com,5,0);//设置有5个人参与的付款条目，且自动计算rate，此处需键入人名以及所付金额
	MultiList Mul("Qian");
	Mul.add_entry(&pay);
	Mul.set_topay();
	Mul.show_topay();//如何分配
	map<vector<string>,double>temp=Mul.get_how_to_pay();
	map<vector<string>,double>::iterator iter;
	for(iter=temp.begin();iter!=temp.end();iter++)
	{
  		cout<<iter->first[0]<<"支付给"<<iter->first[1]<<iter->second<<endl;
	}
	//手动输入应付金额
	Commodity com1;
	string a1="早饭";
	com1.setCommodityName(a1);
	com1.setQuantity(3);
	b=100;
	SingleMoney m1(b,"CNY");
	com.setUnitPrice(m1);
	PayingEntry pay1(&com1,5,1);//设置有5个人参与的付款条目，且手动输入应付金额，此处需键入人名以及所付金额，而后键入应付金额
	MultiList Mul1("Qian");
	Mul1.add_entry(&pay1);
	Mul1.set_topay();
	Mul1.show_topay();//如何分配
	map<vector<string>,double>temp1=Mul1.get_how_to_pay();
	map<vector<string>,double>::iterator iter1;
	for(iter1=temp1.begin();iter1!=temp1.end();iter1++)
	{
  		cout<<iter1->first[0]<<"支付给"<<iter1->first[1]<<iter1->second<<endl;
	}

	system("pause");
	return 0;
}*/
