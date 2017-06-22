/*******************************************************
���ƣ�Unit.cpp
���ߣ���һ��
����޸ģ�2017-06-21
������������λ��ͷ�ļ���ʵ�ֵ�λ������ع��ܡ�
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
//��������ö��
     enum Dimension
    {
        Length=0x0,
        Weight=0x1,
        Area=0x2,
        Capacity=0x3,
        Discrete=0x4
    };
//������λö�٣�3λ16�����������λΪ��Ӧ����ö�ٵ�ֵ
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

//��λ���ú�����ֱ�����õ�λ���޷���ֵ����ͬ���ٵ�λҲ�����ã�������ʹ��
    void setUnit(aUnit unit);

    aUnit getUnit() const;

    Dimension getDimension() const;

//��λת��������ֻ��ͬ���ٵ�λ���ܳɹ�ת��������ֵΪ �µ�λ/�ɵ�λ����ԭ��ֱֵ�ӳ��Է���ֵ����ת�����ɹ����س���1
    double convertTo(aUnit target_unit);

    friend std::ostream& operator<< (std::ostream &os,const Unit &a);

private:
    Dimension _dimension;//����
    aUnit _unit;//��λ
    static bool is_init;//�Ƿ��ʼ��ת������
    static void mat_init();
};

#endif // __UNIT_H
