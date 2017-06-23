/*****************************************************

 名称：adddialoh.h

 作者：钱姿

 内容描述：定义adddialog类，该类是在添加商品信息时与用户交互的窗口

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/

#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QObject>
#include "globalvar.h"
QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTextEdit;
class QLineEdit;
QT_END_NAMESPACE

//extern std::vector<QString> namestr;
//! [0]
class adddialog : public QDialog
{
    Q_OBJECT

public:

    adddialog(int num=0,QWidget *parent = 0);
    //六个填写标签
    QLineEdit *name,*date,*price,*unit,*remark,*shop;

    QLineEdit *peoplepay[10];
private:

    QLabel *nameLabel;

    QLabel *dateLabel;

    QLabel *priceLabel;

    QLabel *unitLabel;

    QLabel *remarkLabel;

    QLabel *shopLabel;

    QLabel *peoplepay1[10];

    QPushButton *okButton;

    QPushButton *cancelButton;
};
//! [0]

#endif // ADDDIALOG_H
