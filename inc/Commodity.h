/*******************************************************
���ƣ�Commodity.h
���ߣ������
����޸ģ�2017-06-22
������������Ʒ��Ϣ���ͷ�ļ�����Ʒ��Ϣ�ౣ����Ʒ�����ơ�
          ���ۡ�������������λ���̼ҡ��û����۵���Ϣ����
          ��һϵ�й�����Щ��Ϣ�Ĳ�������Ʒ��Ϣ�����˵���
          List��ʵ�ֹ۲���ģʽ����֤����Ʒ��Ϣ���޸�ʱ��
          ������Ʒ���˵��ܽ�����Ӧ�жϡ�
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
    static int maxCommodityID;      //��ǰ������Ʒ��ţ����ڶ���־û�

    bool modified;                  //��Ʒ��Ϣ�Ƿ񾭹��޸ĵı�־λ�����ڶ���־û�
    int _CommodityID;               //��Ʒ��ţ�ͨ�������ݿ�ӿ������ã��û�����ӵ���IDΪ-1
    std::string _CommodityName;
    SingleMoney _UnitPrice;
    Unit _Unit;
    Shop *pShop;
    double _Quantity;
    double _Discount;
    Date _Date;
    Remark *pRemark;                //�û����۽ӿ�
    std::set<List*> regdit;         //�۲����б��а�����Commodity���������List����ָ��

    //����Ʒ��Ϣ�������ģ�֪ͨ���۲��߽�����Ӧ����
    void inform_modified();
public:

    //idͨ��Ϊȱʡ���������ݿ�ӿ�ʹ��ʱ��ֵ
    Commodity(int id=-1);

    ~Commodity();

    //ע��һ��List����Ϊ�۲���
    void regObserverList(List *l);

    //�ӹ۲��߶�����ɾ��һ��List�����������б��У���ִ���κβ���
    void delObserverList(List *l);

    //������״̬����Ϊδ���ģ��������ݿ�ӿ��ڱ���ʱ����������
    void set_unmodified()
    {modified=false;}

    bool is_modified()
    {return modified;}

    int CommodityID() const
    {return _CommodityID;}

    //�ýӿ�ͨ�������ݿ�ӿ�������
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

    //�����ۿۣ���Χ0-1�����óɹ�����true�����򷵻�false
    bool setDiscount(double discount)
    {
        if(discount>=0&&discount<1)
        {modified=true;_Discount=discount;inform_modified();return true;}
        else
        {return false;}
    }
    double Discount() const
    {return _Discount;}

    //���õ�λ�����ж����ٲ��Ҳ����������л���
    void setUnit(Unit &_unit)
    {modified=true;_Unit=_unit;}

    //��λת��������������ͬʱ����ת��������true������ת��ʧ�ܣ�����false
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
