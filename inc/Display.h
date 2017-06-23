/*****************************
���ƣ�Display.h
���ߣ���һ��
ʱ�䣺2017-06-22
�����������������е��������ʾ����˵�����Ϣ����
��Ȩ���������
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
#define sublist_num 100 //������˵���;
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
