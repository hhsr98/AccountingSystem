/*****************************************************

 名称：addwidget.cpp

 作者：钱姿

 内容描述：实现AddWidget类，该类启动商品信息存储函数

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/
//#include "adddialog.h"
#include "addwidget.h"
#include "adddialog.h"
#include "mainwindow.h"
#include "PayingEntry.h"
#include <QDebug>
#include <QtWidgets>
#include <QString>
#include <globalvar.h>
void AddWidget::showAddEntryDialog()
{
   adddialog dia;
   if (dia.exec()) {

       Commodity* com_01=new Commodity;
       //存储商品编码
       com_01->setCommodityID();

       //获得商品名称并储存
       std::string name = (dia.name->text()).toStdString();
       com_01->setCommodityName(name);

       //获得日期并储存
       QString date=dia.date->text();
       if(date.size()<10)
       {
           Date day;
           com_01->setDate(day);
       }
       else
       {
            QString y_01=date.left(4);
            int y=y_01.toInt();
            QString m_01=QString(date.at(4))+QString(date.at(5));
            int m=m_01.toInt();
            QString d_01=QString(date.at(6))+QString(date.at(7));
            int d=d_01.toInt();
            QString h_01=date.right(2);
            int h=h_01.toInt();
            Date day1(y,m,d,h);
            com_01->setDate(day1);
       }

       //获得数量并储存
       double quantity=dia.unit->text().toDouble();
       if(quantity==0)quantity=1;
       com_01->setQuantity(quantity);

       //获得价格并储存
       double price =dia.price->text().toDouble();
       SingleMoney _price(price,"CNY");
       com_01->setUnitPrice(_price,quantity);

       std::string shop=(dia.shop->text()).toStdString();
       std::string remark=(dia.remark->text()).toStdString();    
       //Shop *_shop(&shop);
       //com_01->setShop(_shop);
       //Remark *_remark(&remark);
       //com_01->setRemark(_remark);

       this->addEntry(com_01);
       qDebug()<<"it is saved";

   }

}
void AddWidget::showAddEntryDialog_Multi()
{
    //添加多人账单
    qDebug()<<"done multi "<<namestr.size();
   adddialog dia(namestr.size());
   if (dia.exec()) {

       Commodity* com_01=new Commodity;
       com_01->setCommodityID();

       std::string name = (dia.name->text()).toStdString();
       com_01->setCommodityName(name);

       QString date=dia.date->text();
       if(date.size()<10)
       {
           Date day;
           com_01->setDate(day);
       }
       else
       {
            QString y_01=date.left(4);
            int y=y_01.toInt();
            QString m_01=QString(date.at(4))+QString(date.at(5));
            int m=m_01.toInt();
            QString d_01=QString(date.at(6))+QString(date.at(7));
            int d=d_01.toInt();
            QString h_01=date.right(2);
            int h=h_01.toInt();
            Date day1(y,m,d,h);
            com_01->setDate(day1);
       }

       double quantity=dia.unit->text().toDouble();
       if(quantity==0)quantity=1;
       com_01->setQuantity(quantity);

       double price =dia.price->text().toDouble();
       SingleMoney _price(price,"CNY");
       com_01->setUnitPrice(_price,quantity);

       std::string shop=(dia.shop->text()).toStdString();
       std::string remark=(dia.remark->text()).toStdString();
       //Shop *_shop(&shop);
       //com_01->setShop(_shop);
       //Remark *_remark(&remark);
       //com_01->setRemark(_remark);
       this->addEntry(com_01);
        //未实现部分
       /*int num_p=dia.num;
       PayingEntry *entry=new PayingEntry(com_01,num_p,0);
       for(int i=0;i<num_p;i++)
       {
       double pr=dia.people_paid[i]->text().toDouble();
       QString name_temp=namestr[i];
       name=name_temp.toStdString();
       entry->set_map(name,pr);
       }
       for(int i=0;i<num_p;i++)
       {
       QString name_temp=namestr[i];
       name=name_temp.toStdString();
       entry->setRate(name);
       entry->set_total_sum();
       }*/
       qDebug()<<"it is saved";

   }

}
void AddWidget::addEntry(Commodity* com)
{
    emit sendcom(com);
}
