/*****************************************************

 名称：detailslot.h

 作者：钱姿

 内容描述：定义detailslot类，这是一个补充类，用于完成commodityproxy_gui类中detail按钮显示功能

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/

#ifndef DETAILSLOT_H
#define DETAILSLOT_H

#include <QMessageBox>
#include "Commodity.h"

class Detail:public QMessageBox
{
     Q_OBJECT

public:

    Commodity* com;
    Detail(QWidget *parent=0):QMessageBox(parent){}
    void detailcom(Commodity* com){this->com=com;}
public slots:

    void clickslot()
    {
       QMessageBox* msgBox=new QMessageBox;
       //显示单价
       QString str=QString::number( com->UnitPrice().Money(),'g', 6 );
       str="Unitprice:"+str+QString::fromStdString( com->UnitPrice().Currency());
       msgBox->setText(str);
       //显示商家
       msgBox->setInformativeText(tr("Shop:no shop!"));
       //显示评论
       msgBox->setDetailedText(tr("no remark!"));

       msgBox->exec();
    }
};

#endif // DETAILSLOT_H
