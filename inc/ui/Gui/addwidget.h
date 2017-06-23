/*****************************************************

 名称：addwidget.h

 作者：钱姿

 内容描述：定义AddWidget类，该类启动商品信息存储函数

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/

#ifndef ADDWIDGET_H
#define ADDWIDGET_H
#include <SingleMoney.h>
#include <QItemSelection>
#include <QTabWidget>
#include <Commodity.h>
#include <QObject>
#include "globalvar.h"
QT_BEGIN_NAMESPACE
class QSortFilterProxyModel;
class QItemSelectionModel;
QT_END_NAMESPACE

//extern std::vector<QString> namestr;
class AddWidget : public QTabWidget
{
    Q_OBJECT

public:

    AddWidget(QWidget *parent = 0){};

public slots:

    //存储dialog中的商品信息
    void showAddEntryDialog();
    void showAddEntryDialog_Multi();
    //添加商品信息
    void addEntry(Commodity* com);

signals:

    //发送商品信息信号
    void sendcom(Commodity* com);

};
//! [0]

#endif // ADDWIDGET_H
