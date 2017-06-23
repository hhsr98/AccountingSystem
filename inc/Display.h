#ifndef DISPLAY_H
#define DISPLAY_H
#include<iostream>
#include<string>
#include"list.h"
#include"SingleMoney.h"
#include"MultiMoney.h"
#include"date.h"
#include"Unit.h"
#include"Shop.h"
#include"Remark.h"
#include"Commodity.h"
#include<vector>
#define sublist_num 100 //最大子账单数;
using namespace std;

class DisplayImp
{
protected:
	/*Commodity* _commodity;
	List* _list;*/
public:
	/*DisplayImp(Commodity* commodity) :_commodity(commodity) {}
	DisplayImp(List* list) :_list(list) {}*/
	virtual void show(const Commodity* m) = 0;
	virtual void show(const List* m) = 0;
	virtual void show(Commodity* m) = 0;
	virtual void show(List* m) = 0;
	virtual void display(vector<List*> m) = 0;
	//virtual void display(const List* m) = 0;
};


class QtImp :public DisplayImp
{
public:
	void show(Commodity* m) {}
};


class CmdImp :public DisplayImp
{
public:
	/*CmdImp(Commodity* commodity) :DisplayImp(commodity) {}
	CmdImp(List* list) :DisplayImp(list) {};*/

	void show(const Commodity* m);
	void show(Commodity* m);

	void show(const List* list);
	void show(List* list);

	//void operate(char opr);//用户输入操作;

	void display(vector<List*> m);
	//void display(const List* m);
};

#endif
