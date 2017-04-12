#ifndef __UNIT_H
#define __UNIT_H

#define kg_kg 1
#define g_kg 0.001
#define chJing_kg 0.5
#define chLiang_kg 0.05
#define pound_kg 0.454

class Unit
{
    const Dimension _dimension;
    aUnit _unit;
public:
    Unit();
    Unit(aUnit unit);
    void setUnit(aUnit unit);
    aUnit getUnit() const;
    Dimension getDimension() const;
    double convertTo(aUnit target_unit);

    enum Dimension
    {
        Length=0x0,
        Weight=0x1,
        Area=0x2,
        Capacity=0x3,
        Discrete=0x4
    };
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
};

#endif // __UNIT_H
