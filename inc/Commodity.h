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

class Commodity
{
    const int _CommodityID;
    std::string _CommodityName;
    SingleMoney _UnitPrice;
    Unit _Unit;
    Shop *pShop;
    double _Quantity;
    double _Discount;
    Date _Date;
    Remark *pRemark;
public:

    Commodity(int id=-1);

    ~Commodity()=default;

    int CommodityID()
    {return _CommodityID;}

    void setCommodityName(std::string _name);

    std::string CommodityName() const;

    void setShop(Shop *_shop)
    {pShop=_shop;}

    const Shop& Shop() const
    {return *pShop;}

    void setQuantity(double _quantity)
    {_Quantity=_quantity;}

    double Quantity() const
    {return _Quantity;}

    void setDate(Date &_date)
    {_Date=_date;}

    const Date& Date() const
    {return _Date;}

    void setUnitPrice(SingleMoney &_total_price,double _quantity=1)
    {_UnitPrice=_total_price/_quantity;}

    const SingleMoney& UnitPrice() const
    {return _UnitPrice;}

    bool setDiscount(double discount)
    {
        if(discount>=0&&discount<1)
        {_Discount=discount;return true;}
        else
        {return false;}
    }
    double Discount() const
    {return _Discount;}

    void setUnit(Unit &_unit)
    {_Unit=_unit;}

    bool convertToUnit(Unit &_unit)
    {
        if(_unit.getDimension()!=_Unit.getDimension())
            return false;
        else
            _UnitPrice*=_Unit.convertTo(_unit.getUnit());
    }

    const Unit& Unit() const
    {return _Unit;}

    SingleMoney TotalPrice()
    {return _UnitPrice*_Quantity;}

    SingleMoney OriginalUnitPrice()
    {return _UnitPrice/(1-_Discount);}

    void setRemark(Remark *_remark)
    {pRemark=_remark;}

};
#endif // __COMMODITY_H
