#pragma once
#include <vector>
#include <map>
#include "date.h"
#include "Commodity.h"
#include "list.h"
#include "Filter.h"
#include "Display.h"
#include "SingleMoney.h"
class AnalizeVal {
	double real, perc;
public:
	AnalizeVal(double x = 0, double y = 0) :real(x), perc(y) {}
	double getreal();
	double getperc();
	void setreal(double x);
	void setperc(double x);
};
class Analize{
public:
	Filter *filter;
	List* list;
	map< string,SingleMoney > mp;
	DisplayImp* display;
	Analize() { filter = NULL; }
	void addDateStrict(Date a,Date b);
	//void addHourStrict(int st,int ed);
	void addPriceStrict(SingleMoney low, SingleMoney high);
	//void addShopStrict(vector<string> shopnames);
	//void addCommodityStrict(vector<string> names);
	void makeList();
	virtual void startAnalize() = 0;
	void show();
};
class AnalizeByDate :public Analize{
public:
	TimeLen* t;
	AnalizeByDate(DisplayImp* display, TimeLen* t = new TimeLen(0,1,0,0));
	void startAnalize();
};
class AnalizeByHour :public Analize {
	int inter;
	AnalizeByHour(DisplayImp* display, int x = 0);
	void startAnalize();
};
/*class AnalizeByShop:public Analize{
	vector<string> shopNames;
	AnalizeByShop(DisplayImp* display, vector<string> s = vector<string>());
	void startAnalize();
};
class AnalizeByPrice :public Analize {
	SingleMoney inter;
	AnalizeByPrice(DisplayImp *display, int x = 0);
	void startAnalize();
};
class AnalizeByComm :public Analize{
	vector<string> commNames;
	AnalizeByComm(DisplayImp* display, vector<string> s = vector<string>());
	void startAnalize();
};*/
