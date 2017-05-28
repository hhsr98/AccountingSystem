#ifndef FILTER_H
#define FILTER_H
#include "list.h"
#include "date.h"
#include "Commodity.h"
#include "Shop.h"
#include "Request.h"
#include<vector>
class List;
class Filter {
protected:
	Filter* filtertype;
public:
	Filter(Filter* _filtertype);
	Filter();
	virtual bool doFilter(Request* request)=0;
	virtual ~Filter();
	Request* FilterIt(Request* request);
};

class dateFilter:public Filter {
private:
	Date start_time,end_time;
public:
	dateFilter( Filter* _filtertype,Date _start_time=2017-0-0-0,Date _end_time=2017-1-0-0);
	bool doFilter(Request* request);
	const Date& get_start_date()const;
	const Date& get_end_date()const;
};

class priceFilter:public Filter {
private:
	SingleMoney start_price,end_price;
public:
	priceFilter(Filter* _filtertype,SingleMoney _start_price=SingleMoney(0,"CNY"), SingleMoney _end_price=SingleMoney(100,"CNY"));
	bool doFilter(Request* request);
	const SingleMoney& get_start_price() const;
	const SingleMoney& get_end_price() const;
};

class placeFilter:public Filter {
private:
	Shop* ptr_shop;
public:
	placeFilter(Shop* pshop);
	//bool doFilter(Request* request);
	const Shop* get_shop()const;
};

#endif