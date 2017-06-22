/*******************************************************
名称：Commodity.cpp
作者：黄松睿
最后修改：2017-06-22
内容描述：商品信息类的源文件。
*******************************************************/
#include "Commodity.h"
#include "list.h"

int Commodity::maxCommodityID=-1;
Commodity::Commodity(int id):_CommodityName(),_UnitPrice(),\
    _Unit(),pShop(nullptr),_Quantity(0),_Discount(0),_Date(),\
    pRemark(nullptr),_CommodityID(id),modified(false)
{
    maxCommodityID=id>maxCommodityID?id:maxCommodityID;

}
Commodity::~Commodity()
{
    for(auto l:regdit)
        l->deleteCommodity(this);
}
void Commodity::regObserverList(List *l)
{
    regdit.insert(l);
}
void Commodity::delObserverList(List *l)
{
    if(regdit.find(l)!=regdit.end()) regdit.erase(l);
}
void Commodity::inform_modified()
{
    for(auto l: regdit)
        if(  !(l->isValidCommodity(this))  )
        {
            l->deleteCommodity(this);
        }
}
void Commodity::setCommodityName(std::string _name)
{
    modified=true;
    _CommodityName=_name;
}
std::string Commodity::CommodityName() const
{
    return _CommodityName;
}
std::ostream& operator<<(std::ostream &os, const Commodity &com)
{
    //os<<"CommodityID:\t"<<com._CommodityID<<std::endl;
    os<<"CommodityName:\t"<<com._CommodityName<<std::endl;
    os<<"Price:\t\t"<<com._UnitPrice<<'/'<<com._Unit<<std::endl;
    os<<"TotalPrice:\t"<<com.TotalPrice()<<std::endl;
    os<<"Quantity:\t"<<com._Quantity<<com._Unit<<std::endl;
    os<<"OriginalPrice:\t"<<com.OriginalUnitPrice()<<'/'<<com._Unit<<std::endl;
    os<<"Discount:\t"<<com._Discount<<std::endl;
    os<<"Date:\t\t"<<com._Date<<std::endl;
    return os;
}
