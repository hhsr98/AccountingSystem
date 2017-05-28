#include"Filter.h"
#include<iostream>
using namespace std;

Filter::Filter(Filter* _filtertype) {
	this->filtertype=_filtertype;
}

Filter::Filter() {

}

Filter::~Filter() {

}

void Filter::FilterIt(Request* request) {
	if(doFilter(request)) {
		if (filtertype!=NULL)
		{
			this->filtertype->FilterIt(request);
		}
	}
}

dateFilter::dateFilter( Filter* _filtertype,Date _start_time,Date _end_time):Filter(_filtertype),start_time(_start_time),end_time(_end_time){

}

const Date& dateFilter::get_start_date() const {
	return(this->start_time);
}

const Date& dateFilter::get_end_date() const {
	return(this->end_time);
}


priceFilter::priceFilter(Filter* _filtertype,SingleMoney _start_price, SingleMoney _end_price): Filter(_filtertype),start_price(_start_price),end_price(_end_price){

}

const SingleMoney& priceFilter::get_start_price() const {
	return(this->start_price);
}

const SingleMoney& priceFilter::get_end_price() const {
	return(this->end_price);
}

placeFilter::placeFilter(Shop* pshop):ptr_shop(pshop){

}

const Shop* placeFilter::get_shop()const {
	return(this->ptr_shop);
}

bool dateFilter::doFilter(Request* request) {
	if (request->getDate()<end_time&&request->getDate()>start_time)
	{
		request->accept();
		return true;
	}
	else
	{
		request->reject();
		return false;
	}
}

bool priceFilter::doFilter(Request* request) {
	if(request->getMoney()>start_price&&request->getMoney()<end_price)
	{
		request->accept();
		return true;
	}
	else
	{
		request->reject();
		return false;
	}
}
