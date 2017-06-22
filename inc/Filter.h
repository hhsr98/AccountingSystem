/*******************************************************
名称：Filter.h
作者：钱姿
最后修改：2017-06-21
内容描述：筛选条件类头文件。筛选条件体系采用责任链模式
          实现。Filter类为其抽象接口类。Filter对象会销
          毁其指向的下一级Filter对象，故不要将同一Filter
          对象用于构造多个链。本文件下还定义了子类用于
          筛选购买日期、购买单价和总价。
*******************************************************/
#ifndef __FILTER_H
#define __FILTER_H
#include "date.h"
#include "Commodity.h"
#include "Shop.h"
#include<vector>

class List;
class Filter
{
private:
	const Filter* subfilter;
	virtual bool isSelfValid(const Commodity *com) const=0;
public:
	Filter(const Filter *sub_criteria=nullptr):subfilter(sub_criteria){}
	virtual ~Filter()
	{
	    if(subfilter) delete subfilter;
	}
	bool isValid(const Commodity *com) const
	{
	    return isSelfValid(com) && (subfilter==nullptr|| subfilter->isValid(com));
	}
};

//对所有商品都判断符合条件
class AllFilter:public Filter
{
    bool isSelfValid(const Commodity *com) const
    {
        return true;
    }
};

//筛选购买日期
class dateFilter:public Filter {
private:
	Date start_time,end_time;
    bool isSelfValid(const Commodity *com) const
	{
	    return (com->Date()>=start_time)&&(com->Date()<=end_time);
	}
public:
	dateFilter(Date _start_time,Date _end_time,const Filter *subcriteria=nullptr):Filter(subcriteria)
	{
	    start_time=_start_time;
	    end_time=_end_time;
	}
	const Date& get_start_date()const
	{
	    return start_time;
	}

	const Date& get_end_date()const
	{
	    return end_time;
	}
};

//筛选单价
class priceFilter:public Filter {
private:
	SingleMoney start_price,end_price;
	bool isSelfValid(const Commodity *com) const
	{
	    return (start_price<=com->UnitPrice())&&(end_price>=com->UnitPrice());
	}
public:
	priceFilter(double _start_price,double _end_price,std::string currency,const Filter *subcriteria=nullptr)\
	:Filter(subcriteria),start_price(_start_price,currency),end_price(_end_price,currency){}

	const SingleMoney& get_start_price() const
	{
	    return start_price;
	}
	const SingleMoney& get_end_price() const
	{
	    return end_price;
	}
};

//筛选总价
class TotalPriceFilter:public Filter
{
	SingleMoney start_price,end_price;
	bool isSelfValid(const Commodity *com) const
	{
	    return (start_price<=com->TotalPrice())&&(end_price>=com->TotalPrice());
	}
public:
	TotalPriceFilter(double _start_price,double _end_price,std::string currency,const Filter *subcriteria=nullptr)\
	:Filter(subcriteria),start_price(_start_price,currency),end_price(_end_price,currency){}

	const SingleMoney& get_start_price() const
	{
	    return start_price;
	}
	const SingleMoney& get_end_price() const
	{
	    return end_price;
	}
};

#endif
