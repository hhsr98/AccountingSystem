#pragma once
#include "date.h"
#include <vector>
//#include "Commodity.h"
//#include "zhangdan.h"
//#include "display.h"
class Analize{
	//vector<zd> zdSet;
	Date _startDate, endDate;
	int _startHour, endHour;
	void init(int type, Date a, Date b, int startHour, int endHour, vector<string> s1, vector<string> s2) {
		Date tmp = b;
		_startDate = a;
		_endDate = b;
		_startHour = startHour;
		_endHour = endHour;
		switch(type):
			case 0:
				for (; tmp >= a; tmp = tmp - Timelen(0, 0, 1, 0))
					zdSet.push_back(zd(tmp - Timelen(0, 0, 1, 0), tmp, startHour, endHour, s));
				break;
			case 1:
				for (; tmp >= a; tmp = tmp - Timelen(0, 0, 7, 0))
					zdSet.push_back(zd(tmp - Timelen(0, 0, 7, 0), tmp, startHour, endHour, s));
				break;
			case 2:
				for (; tmp >= a; tmp = tmp - Timelen(0, 1, 0, 0))
					zdSet.push_back(zd(tmp - Timelen(0, 1, 0, 0), tmp, startHour, endHour, s));
				break;
			case 3:
				for (; tmp >= a; tmp = tmp - Timelen(1, 0, 0, 0))
					zdSet.push_back(zd(tmp - Timelen(1, 0, 0, 0), tmp, startHour, endHour, s));
				break;
			case 4:
				zdSet.push_back(a, b, startHour, endHour, s));
			default:
				zdSet.push_back(a, b, startHour, endHour, s));
				break;
	}
public:
	Analize(int type, Date a, Date b = Date(), int startHour = 0, int endHour = 24, vector<string> SelectCommoditiesNames = vector<string>(), vector<string> SelectShopsNames = vector<string>()){
		init(type, a, b, startHour, endHour, SelectCommoditiesNames, SelectShopsNames);
	}
	Analize(int type, TimeLen a, Date b = Date(), int startHour = 0, int endHour = 24, vector<string> SelectCommoditiesNames = vector<string>(), vector<string> SelectShopsNames = vector<string>()) {
		init(type, b - a, b, startHour, endHour, SelectCommoditiesNames, SelectShopsNames);
	}
	addHourStrict(int startHour = 0, int endHour = 24)
	{

	}
	void display(int type)
	{
		_display.show(type, zdSet);
	}
};
