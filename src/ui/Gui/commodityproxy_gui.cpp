/*****************************************************

 名称：commodityproxy_gui.h

 作者：钱姿

 内容描述：继承CommodityProxy类，为商品信息在gui下的显示

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/
#include "commodityproxy_gui.h"
#include "detailslot.h"

#include <vector>
#include <QTableWidget>
#include "Commodity.h"
#include <QTableWidgetItem>
#include <QPushButton>
#include <QTableWidget>
#include <QApplication>
#include <QVBoxLayout>
#include "mainwindow.h"
#include <QComboBox>
#include <mainwindow.H>
#include <QMessageBox>
#include <QDebug>
using std::vector;

void CommodityProxy_GUI::show(QTableWidget *table) {

    mytable=table;
    //显示商品名称
    std::string name=com->CommodityName();
    QString name_q = QString::fromStdString(name);
    int num= table->rowCount();
    table->insertRow(num);
    QTableWidgetItem *item = new QTableWidgetItem (name_q);
    table->setItem(num, 1, item);

    //显示日期
    Date date=com->Date();
    int y=date.year;
    int m=date.month;
    int d=date.day;
    int h=date.hour;
    QString y_q = QString::number(y, 10);
    QString m_q = QString::number(m, 10);
    QString d_q = QString::number(d, 10);
    QString h_q = QString::number(h, 10);
    QString date_q=y_q+"-"+m_q+"-"+d_q+"-"+h_q;
    QTableWidgetItem *item1 = new QTableWidgetItem (date_q);
    table->setItem(num, 0, item1);

    //显示价格
    SingleMoney money=com->TotalPrice();
    double money_temp=money.Money();
    std::string unit=money.Currency();
    QString unit_q = QString::fromStdString(unit);
    QString money_q= QString::number( money_temp,'g', 6 );
    money_q+=unit_q;
    QTableWidgetItem *item2 = new QTableWidgetItem (money_q);
    table->setItem(num, 2, item2);

    //DetailButton
    QPushButton *button=new QPushButton();
    button->setText("Detail");
    Detail*detail=new Detail();
    detail->detailcom(com);
    QObject::connect(button,SIGNAL(clicked()),detail,SLOT(clickslot()));
    button->setEnabled(true);
    table->setCellWidget(num,3,button);
}

