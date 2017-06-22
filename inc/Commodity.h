/*******************************************************
名称：Commodity.h
作者：黄松睿
最后修改：2017-06-21
内容描述：商品信息类的头文件。商品信息类保存商品的名称、
          单价、数量、计量单位、商家、用户评论等信息，提
          供一系列关于这些信息的操作。商品信息类与账单类
          List间实现观察者模式，保证在商品信息被修改时包
          含该商品的账单能进行相应判断。
*******************************************************/
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
    static int maxCommodityID;      //当前最大的商品编号，用于对象持久化

    bool modified;                  //商品信息是否经过修改的标志位，用于对象持久化
    int _CommodityID;               //商品编号，通常由数据库接口来设置，用户新添加的类ID为-1
    std::string _CommodityName;
    SingleMoney _UnitPrice;
    Unit _Unit;
    Shop *pShop;
    double _Quantity;
    double _Discount;
    Date _Date;
    Remark *pRemark;                //用户评论接口
    std::set<List*> regdit;         //观察者列表中包含该Commodity对象的所有List对象指针

    void inform_modified();
public:

    /*
    *功能：构造器，对除_CommodityIDa外的所有成员进行默认初始化
    *参数：
    *   id=-1；商品信息类对象的编号，通常缺省，仅数据库接口应当对其赋值
    */
    Commodity(int id=-1);

    ~Commodity();

    /*
    *功能：将一List对象添加进观察者列表中
    *参数：
    *   l：要添加的观察者
    */
    void regObserverList(List *l);

    /*
    *功能：将一List对象从观察者列表中删除，若其不存在于列表中，不执行任何操作
    *参数：
    *   l：要删除的观察者
    */
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
