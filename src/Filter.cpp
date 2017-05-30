#include"../inc/Filter.h"
#include<iostream>
using namespace std;

Filter::Filter(Filter* _filtertype) {
	this->filtertype=_filtertype;
}

Filter::Filter() {

}

Filter::~Filter() {

}

bool Filter::FilterIt(Commodity* com) {
	if(doFilter(com)) {
		if (filtertype!=NULL)
		{
			this->filtertype->FilterIt(com);
		}
	}
	else
		return false;
	return true;
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

bool dateFilter::doFilter(Commodity* com) {
	if (com->Date()<end_time&&com->Date()>start_time)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool priceFilter::doFilter(Commodity* com) {
	if(com->TotalPrice()>start_price&&com->TotalPrice()<end_price)
	{
		return true;
	}
	else
	{
		return false;
	}
}
