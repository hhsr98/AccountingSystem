#include "../inc/Request.h"
Request::Request(Commodity* _ptr):ptr(_ptr){

}

string Request::getName() {
	return ptr->CommodityName();
}

Date Request::getDate() {
	return ptr->Date();
}

Shop Request::getShop() {
	return ptr->Shop();
}

SingleMoney Request::getMoney() {
	return ptr->TotalPrice();
}

void Request::accept() {
	this->_reject=true;
}

void Request::reject() {
	this->_reject=false;
}





