//HSR20170509
#ifndef __COMMODITY_H
#define __COMMODITY_H

#include "Unit.h"
#include "Shop.h"
#include "date.h"
#include "SingleMoney.h"
#include "Remark.h"
#include<iostream>
#include<string>
#include<set>
class List;
class Commodity
{
    static int maxCommodityID;

    bool modified;
    int _CommodityID;
    std::string _CommodityName;
    SingleMoney _UnitPrice;
    Unit _Unit;
    Shop *pShop;
    double _Quantity;
    double _Discount;
    Date _Date;
    Remark *pRemark;
    std::set<List*> regdit;

    void inform_modified();
public:

    Commodity(int id=-1);

    ~Commodity();

    void regObserverList(List *l);

    void delObserverList(List *l);

    void set_unmodified()
    {modified=false;}

    bool is_modified()
    {return modified;}

    int CommodityID() const
    {return _CommodityID;}

    void setCommodityID()
    {maxCommodityID++;_CommodityID=maxCommodityID;}

    void setCommodityName(std::string _name);

    std::string CommodityName() const;

    void setShop(Shop *_shop)
    {modified=true;pShop=_shop;inform_modified();}

    const Shop& Shop() const
    {return *pShop;}

    void setQuantity(double _quantity)
    {modified=true;_Quantity=_quantity;inform_modified();}

    double Quantity() const
    {return _Quantity;}

    void setDate(Date &_date)
    {modified=true;_Date=_date;inform_modified();}

    const Date& Date() const
    {return _Date;}

    void setUnitPrice(SingleMoney &_total_price,double _quantity=1)
    {modified=true;_UnitPrice=_total_price/_quantity;inform_modified();}

    const SingleMoney UnitPrice() const
    {return _UnitPrice;}

    bool setDiscount(double discount)
    {
        if(discount>=0&&discount<1)
        {modified=true;_Discount=discount;inform_modified();return true;}
        else
        {return false;}
    }
    double Discount() const
    {return _Discount;}

    void setUnit(Unit &_unit)
    {modified=true;_Unit=_unit;}

    bool convertToUnit(Unit &_unit)
    {
        if(_unit.getDimension()!=_Unit.getDimension())
            return false;
        else
        {modified=true;_UnitPrice*=_Unit.convertTo(_unit.getUnit());inform_modified();return true;}
    }

    const Unit& Unit() const
    {return _Unit;}

    SingleMoney TotalPrice() const
    {return _UnitPrice*_Quantity;}

    SingleMoney OriginalUnitPrice() const
    {return _UnitPrice/(1-_Discount);}

    void setRemark(Remark *_remark)
    {modified=true;pRemark=_remark;inform_modified();}

    friend std::ostream& operator<< (std::ostream &os,const Commodity& com);

};
#endif // __COMMODITY_H
