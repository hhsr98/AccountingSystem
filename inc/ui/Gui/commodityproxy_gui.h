/*****************************************************

 名称：commodityproxy_gui.h

 作者：钱姿

 内容描述：继承CommodityProxy类，为商品信息在gui下的显示

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/

#ifndef COMMODITYPROXY_GUI_H
#define COMMODITYPROXY_GUI_H
#include <CommodityProxy.h>
#include <Commodity.h>
#include <QTableWidget>
#include <vector>
#include <QObject>
#include <mainwindow.h>
using std::vector;

class CommodityProxy_GUI:public CommodityProxy,public QObject
{

private:

    using CommodityProxy::com;

public:

    using CommodityProxy::CommodityProxy;
    QTableWidget* mytable;
    void show(QTableWidget *table);
    void unshow(){}
    void showManip(){}
    void show(){}

public slots:

    void slotclicked();

};

#endif // COMMODITYPROXY_GUI_H
