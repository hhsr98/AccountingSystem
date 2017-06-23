/*****************************
名称：Display.h
作者：尹一帆
时间：2017-06-22
描述：用于在命令行等情况下显示相关账单等信息的类
版权：自行完成
******************************/
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
public:
	virtual void show(const Commodity* m) = 0;
	virtual void show(const List* m) = 0;
	virtual void show(Commodity* m) = 0;
	virtual void show(List* m) = 0;
	virtual void display(vector<List*> m) = 0;
};

//to do...
class QtImp :public DisplayImp
{
public:
	void show(Commodity* m) {
		//to do...
	}
};


class CmdImp :public DisplayImp
{
public:
	void show(const Commodity* m);
	void show(Commodity* m);

	void show(const List* list);
	void show(List* list);

	void display(vector<List*> m);
};

#endif
