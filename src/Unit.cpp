/*******************************************************
名称：Unit.cpp
作者：尹一帆
最后修改：2017-06-21
内容描述：单位类源文件。
*******************************************************/
#include "../inc/Unit.h"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define dim(a) (Dimension)(a>>8)
#define bitpos(b) (b<<8)
using namespace std;
double mat[10][100];
string UnitName[0x500];
bool Unit::is_init=false;
void Unit::mat_init()
{
    mat[Length][meter-bitpos(Length)]=m_m;
    mat[Length][centimeter-bitpos(Length)]=cm_m;
    mat[Length][kilometer-bitpos(Length)]=km_m;
    mat[Length][inch-bitpos(Length)]=inch_m;

    mat[Weight][kilogram-bitpos(Weight)]=kg_kg;
    mat[Weight][gram-bitpos(Weight)]=g_kg;
    mat[Weight][ch_Jing-bitpos(Weight)]=chJing_kg;
    mat[Weight][ch_Liang-bitpos(Weight)]=chLiang_kg;
    mat[Weight][pound-bitpos(Weight)]=pound_kg;

    mat[Capacity][liter-bitpos(Capacity)]=l_l;
    mat[Capacity][milliliter-bitpos(Capacity)]=ml_l;
    mat[Capacity][uk_gallon-bitpos(Capacity)]=ukGallon_l;
    mat[Capacity][us_gallon-bitpos(Capacity)]=usGallon_l;

    mat[Discrete][piece-bitpos(Discrete)]=1;
    mat[Discrete][no_unit-bitpos(Discrete)]=1;

    UnitName[meter]="m";
    UnitName[centimeter]="cm";
    UnitName[kilometer]="km";
    UnitName[inch]="inch";
    UnitName[kilogram]="kg";
    UnitName[gram]="g";
    UnitName[ch_Jing]="ch_Jing";
    UnitName[ch_Liang]="ch_Liang";
    UnitName[pound]="pd";
    UnitName[liter]="L";
    UnitName[milliliter]="mL";
    UnitName[uk_gallon]="uk_gallon";
    UnitName[us_gallon]="us_gallon";
    UnitName[piece]="piece";
    UnitName[no_unit]="no_unit";
}

Unit::Unit():_unit(no_unit),_dimension(Discrete)
{
    if(!is_init)
    {
        is_init=true;
        mat_init();
    }
}
Unit::Unit(aUnit unit):_unit(unit),_dimension(dim(unit))
{
    if(!is_init)
    {
        is_init=true;
        mat_init();
    }
}
void Unit::setUnit(aUnit unit)
{
    _unit=unit;
    _dimension=dim(unit);
}
Unit::aUnit Unit::getUnit() const
{
    return _unit;
}
Unit::Dimension Unit::getDimension() const
{
    return _dimension;
}
double Unit::convertTo(aUnit target_unit)
{
    if(dim(target_unit)!=_dimension) return 1;
    double temp=mat[_dimension][target_unit-(_dimension<<8)]/mat[_dimension][_unit-(_dimension<<8)];
    _unit=target_unit;
    return temp;
}
ostream& operator<<(ostream&os,const Unit &a)
{
    os << UnitName[a._unit].c_str();
	return os;
}
