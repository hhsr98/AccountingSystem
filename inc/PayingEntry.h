#ifndef __PAYINGENTRY_H
#define __PAYINGENTRY_H
#include "Commodity.h"
#include "Person.h"
#include <map>
#include<cstring>
#include<iostream>
class PayingEntry {
public:
    enum Mode
	{
	    Ratio,
	    Money
	};
private:
	Commodity* _com;
	Mode payed_mode,to_pay_mode;
	std::map<Person*,SingleMoney> payed_money;
	std::map<Person*,SingleMoney> to_pay_money;
	std::map<Person*,double> payed_ratio;
	std::map<Person*,double> to_pay_ratio;

	void convertToMoney(std::map<Person*,double> &rate,std::map<Person*,SingleMoney> &money);
public:
	PayingEntry(Commodity* com);

	void setPayedMode(Mode m);
	void setToPayMode(Mode m);

	Mode PayedMode()
	{return payed_mode;}
	Mode ToPayMode()
	{return to_pay_mode;}

	void setRatioPayed(Person* some,double rate);
	void setRatioToPay(Person* some,double rate);
	void setMoneyPayed(Person* some,SingleMoney money);
	void setMoneyToPay(Person* some,SingleMoney money);

	void clearRatioPayed();
	void clearMoneyPayed();
	void clearRatioToPay();
	void clearMoneyToPay();

	//double getRatioPayed(Person* some);
	//double getRatioToPay(Person* some);
    SingleMoney getMoneyPayed(Person* some);
	SingleMoney getMoneyToPay(Person* some);

	std::map<Person*,SingleMoney> getMoneyPayed();
	std::map<Person*,SingleMoney> getMoneyToPay();

};
#endif
