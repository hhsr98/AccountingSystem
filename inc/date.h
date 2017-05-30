#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
const int monthDay[13]{0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool checkyear(int x);// check if x is leap year
int getYearDay(int y);// return the number of day in year y
int getMonthDay(int x,int y);// return the number of day in year x,month y
class Date {
	void init();
public:
	long long tothour;//how many hour from 0-0-0-0 to year-month-day-hour
	int year, month, day, hour;
	Date();
	Date(int y, int m=1,int d=1,int h=0);
	Date(long long t);
	virtual bool operator <(const Date &a) const;
	virtual bool operator <=(const Date &a) const;
	virtual bool operator >(const Date &a) const;
	virtual bool operator >=(const Date &a) const;
	friend std::ostream& operator<< (std::ostream&out, const Date &x);
	friend std::istream& operator>> (std::istream&in, Date &x);
};
class TimeLen :public Date {
	void init();
public:
	TimeLen() {}
	TimeLen(int y, int m=0, int d=0, int h=0);
	TimeLen(long long t);
	friend std::ostream& operator<< (std::ostream&out, const TimeLen &x);
	friend std::istream& operator>> (std::istream&in, TimeLen &x);
};
Date operator -(const Date &a, const TimeLen &b);
Date operator +(const Date &a, const Date &b);
Date operator +(const Date &a, const TimeLen &b);
TimeLen operator -(const Date &a, const Date &b);
