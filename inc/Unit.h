/*******************************************************
名称：Unit.cpp
作者：尹一帆
最后修改：2017-06-21
内容描述：单位类头文件。实现单位换算相关功能。
*******************************************************/
#ifndef __UNIT_H
#define __UNIT_H

#include<iostream>
#include<string>
#define kg_kg 1
#define g_kg 1000
#define chJing_kg 2
#define chLiang_kg 20
#define pound_kg 2.205

#define m_m 1
#define cm_m 100
#define km_m 0.001
#define inch_m 39.4

#define l_l 1
#define ml_l 1000
#define ukGallon_l 0.22
#define usGallon_l 0.263

class Unit
{
public:
//常见量纲枚举
     enum Dimension
    {
        Length=0x0,
        Weight=0x1,
        Area=0x2,
        Capacity=0x3,
        Discrete=0x4
    };
//常见单位枚举，3位16进制数，最高位为对应量纲枚举的值
    enum aUnit
    {
        kilogram=0x100,
        gram=0x101,
        ch_Jing=0x102,
        ch_Liang=0x103,
        pound=0x104,

        meter=0x000,
        centimeter=0x001,
        kilometer=0x002,
        inch=0x003,

        liter=0x300,
        milliliter=0x301,
        uk_gallon=0x302,
        us_gallon=0x303,

        piece=0x401,
        no_unit=0x400
    };

    Unit();

    Unit(aUnit unit);

//单位设置函数，直接设置单位，无返回值，不同量纲单位也可设置，请慎重使用
    void setUnit(aUnit unit);

    aUnit getUnit() const;

    Dimension getDimension() const;

//单位转换函数，只有同量纲单位才能成功转换，返回值为 新单位/旧单位（即原数值直接乘以返回值），转换不成功返回常数1
    double convertTo(aUnit target_unit);

    friend std::ostream& operator<< (std::ostream &os,const Unit &a);

private:
    Dimension _dimension;//量纲
    aUnit _unit;//单位
    static bool is_init;//是否初始化转换矩阵
    static void mat_init();
};

#endif // __UNIT_H
