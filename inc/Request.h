#ifndef REQUEST_H
#define REQUEST_H
#include "Commodity.h"
#include<cstring>
#include<iostream>
#include "Date.h"
#include "SingleMoney.h"
using namespace std;
class Request {
private:
	bool _reject;
	Commodity* ptr;
public:
	string getName();
	Date getDate();
	Shop getShop();
	SingleMoney getMoney();
	void accept();
	void reject();
	Request(Commodity* _ptr);
};
#endif