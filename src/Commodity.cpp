#include "../inc/Commodity.h"

Commodity::Commodity(int id):_CommodityName(),_UnitPrice(),\
    _Unit(),pShop(nullptr),_Quantity(0),_Discount(0),_Date(),\
    pRemark(nullptr),_CommodityID(id)
{

}
void Commodity::setCommodityName(std::string _name)
{
    _CommodityName=_name;
}
std::string Commodity::CommodityName() const
{
    return _CommodityName;
}
