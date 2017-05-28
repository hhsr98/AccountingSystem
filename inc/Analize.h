#pragma once
#include "date.h"
#include <vector>
#include "Commodity.h"
#include "list.h"
#include "display.h"
class Analize{
	vector<List> list;
	Display _display;
	Date _startDate, endDate;
	int _startHour, endHour;
	void init(int type, Date a, Date b, int startHour, int endHour, vector<string> s1, vector<string> s2, int l, int h) {
		Date tmp = b;
		_startDate = a;
		_endDate = b;
		_startHour = startHour;
		_endHour = endHour;
		switch(type):
			case 0:
				for (; tmp >= a; tmp = tmp - Timelen(0, 0, 1, 0))
					list.push_back(List(tmp - Timelen(0, 0, 1, 0), tmp, startHour, endHour, s1, s2, l, h));
				break;
			case 1:
				for (; tmp >= a; tmp = tmp - Timelen(0, 0, 7, 0))
					list.push_back(List(tmp - Timelen(0, 0, 7, 0), tmp, startHour, endHour, s1, s2, l, h));
				break;
			case 2:
				for (; tmp >= a; tmp = tmp - Timelen(0, 1, 0, 0))
					list.push_back(List(tmp - Timelen(0, 1, 0, 0), tmp, startHour, endHour, s1, s2, l, h));
				break;
			case 3:
				for (; tmp >= a; tmp = tmp - Timelen(1, 0, 0, 0))
					list.push_back(List(tmp - Timelen(1, 0, 0, 0), tmp, startHour, endHour, s1, s2, l, h));
				break;
			case 4:
				list.push_back(List(a, b, startHour, endHour, s1, s2, l, h));
			default:
				list.push_back(List(a, b, startHour, endHour, s1, s2, l, h));
				break;
	}
public:
	Analize(int type, Date a, Date b = Date(), int startHour = 0, int endHour = 24, vector<string> SelectCommoditiesNames = vector<string>(), vector<string> SelectShopsNames = vector<string>(), int lowPrice = 0, int highPrice = 100000000){
		init(type, a, b, startHour, endHour, SelectCommoditiesNames, SelectShopsNames, lowPrice, highPrice);
	}
	Analize(int type, TimeLen a, Date b = Date(), int startHour = 0, int endHour = 24, vector<string> SelectCommoditiesNames = vector<string>(), vector<string> SelectShopsNames = vector<string>(), int lowPrice = 0, int highPrice = 100000000) {
		init(type, b - a, b, startHour, endHour, SelectCommoditiesNames, SelectShopsNames, lowPrice, highPrice);
	}
	void display(int type)
	{
		_display.show(type, list);
	}
};
