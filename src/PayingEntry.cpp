#include "PayingEntry.h"

PayingEntry::PayingEntry(Commodity *com):_com(com),payed_money(),\
    to_pay_money(),payed_ratio(),to_pay_ratio(),payed_mode(Money),to_pay_mode(Money)
{

}
void PayingEntry::setPayedMode(Mode m)
{
    payed_mode=m;
    if(m==Ratio) clearMoneyPayed();
    else clearRatioPayed();
}
void PayingEntry::setToPayMode(Mode m)
{
    to_pay_mode=m;
    if(m==Ratio) clearMoneyToPay();
    else clearRatioToPay();
}
void PayingEntry::setRatioPayed(Person* some,double rate)
{
    if(payed_mode==Ratio)
    {
        payed_ratio[some]=rate>0?rate:0;
    }
}

void PayingEntry::setRatioToPay(Person* some,double rate)
{
    if(payed_mode==Ratio)
    {
        to_pay_ratio[some]=rate>0?rate:0;
    }
}
void PayingEntry::setMoneyPayed(Person* some,SingleMoney money)
{
    if(payed_mode==Money)
    {
        payed_money[some]=money;
    }
}
void PayingEntry::setMoneyToPay(Person* some,SingleMoney money)
{
    if(payed_mode==Money)
    {
        to_pay_money[some]=money;
    }
}
void PayingEntry::clearRatioPayed()
{
    payed_ratio.clear();
}
void PayingEntry::clearRatioToPay()
{
    to_pay_ratio.clear();
}
void PayingEntry::clearMoneyPayed()
{
    payed_money.clear();
}
void PayingEntry::clearMoneyToPay()
{
    to_pay_money.clear();
}
/*
double PayingEntry::getRatioPayed(Person *some)
{
    if(payed_mode==Money)
    {
        for(auto p:payed_ratio)
    }
}
*/
void PayingEntry::convertToMoney(std::map<Person*,double> &rate,std::map<Person*,SingleMoney> &money)
{
    double total=0;
    SingleMoney tot=_com->TotalPrice();
    for(auto p:rate)
    {
        total+=p.second;
    }
    for(auto p:rate)
    {
        money[p.first]=(p.second/total)*tot;
    }
}
SingleMoney PayingEntry::getMoneyPayed(Person *some)
{
    if(payed_mode==Ratio)
    {
        convertToMoney(payed_ratio,payed_money);
    }
    if(payed_money.find(some)==payed_money.end())
    {
        return SingleMoney();
    }
    else
    {
        return payed_money[some];
    }
}
SingleMoney PayingEntry::getMoneyToPay(Person *some)
{
    if(to_pay_mode==Ratio)
    {
        convertToMoney(to_pay_ratio,to_pay_money);
    }
    if(to_pay_money.find(some)==to_pay_money.end())
    {
        return SingleMoney();
    }
    else
    {
        return to_pay_money[some];
    }
}
std::map<Person*,SingleMoney> PayingEntry::getMoneyPayed()
{
    if(payed_mode==Ratio)
    {
        convertToMoney(payed_ratio,payed_money);
    }
    return payed_money;
}
std::map<Person*,SingleMoney> PayingEntry::getMoneyToPay()
{
    if(to_pay_mode==Ratio)
    {
        convertToMoney(to_pay_ratio,to_pay_money);
    }
    return to_pay_money;
}
