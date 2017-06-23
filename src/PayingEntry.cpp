#include "PayingEntry.h"

PayingEntry::PayingEntry(Commodity *com):_com(com),\
    payed_money(),to_pay_money(),payed_ratio(),to_pay_ratio,\
    payed_mode(Money),to_pay_mode(Money)
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
        payed_ratio[some]=rate>0?rate,0;
    }
}

void PayingEntry::setRatioToPay(Person* some,double rate)
{
    if(payed_mode==Ratio)
    {
        to_pay_ratio[some]=rate>0?rate,0;
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
SingleMoney PayingEntry::getMoneyPayed(Person *some)
{
    if(payed_mode==Ratio)
    {
        double total=0;
        for(auto p:payed_ratio)
        {
            total+=p->second;
        }
        for(auto p:payed_ratio)
        {
            payed_money[p->first]=p->second*
        }
    }
}
