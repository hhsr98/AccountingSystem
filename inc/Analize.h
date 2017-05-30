#pragma once
#include <vector>
#include "date.h"
#include "Commodity.h"
#include "list.h"
#include "Filter.h"
#include "Display.h"
class AnalizeVal {
	double real, perc;
public:
	double getreal();
	double getperc();
	double setreal(double x);
	double setperc(double x);
};
class Analize{
public:
	Filter *filter;
	List* list;
	map< string,AnalizeVal > mp;
	DisplayImp* display;
	void addDateStrict(Date a,Date b);
	void addHourStrict(int st,int ed);
	void addPriceStrict(int low,int high);
	void addShopStrict(vector<string> shopnames);
	void addCommodityStrict(vector<string> names);
	virtual void startAnalize() = 0;
	void show();
};
class AnalizeByDate :public Analize{
public:
	TimeLen* t;
	AnalizeByDate(DisplayImp* display, TimeLen* t = new TimeLen(0,1,0,0));
	void startAnalize();
};
class AnalizeByShop:public Analize{
	vector<string> shopNames;
	AnalizeByShop(DisplayImp* display, vector<string> s = vector<string>());
	void startAnalize();
};
class AnalizeByPrice :public Analize {
	int inter;
	AnalizeByPrice(DisplayImp *display, int x = 0);
	void startAnalize();
};
class AnalizeByHour :public Analize {
	int inter;
	AnalizeByHour(DisplayImp* display, int x = 0);
	void startAnalize();
};
class AnalizeByComm :public Analize{
	vector<string> commNames;
	AnalizeByComm(DisplayImp* display, vector<string> s = vector<string>());
	void startAnalize();
};
