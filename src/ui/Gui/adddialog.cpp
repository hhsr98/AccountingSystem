/*****************************************************

 名称：adddialoh.cpp

 作者：钱姿

 内容描述：实现adddialog类，该类是在添加商品信息时与用户交互的窗口

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/

#include "adddialog.h"
#include <QtWidgets>
#include "globalvar.h"
//! [0]
adddialog::adddialog(int num,QWidget *parent)
    : QDialog(parent)
{
    //定义标签名称
    nameLabel = new QLabel("Commodity name");
    dateLabel = new QLabel("date(eg.2017053010)");
    priceLabel =new QLabel("totalprice");
    unitLabel = new QLabel("quantity");
    shopLabel =new QLabel ("shop");
    remarkLabel = new QLabel ("remark");
    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    //定义文本窗口
    name = new QLineEdit;
    date = new QLineEdit;
    price = new QLineEdit;
    unit = new QLineEdit;
    shop = new QLineEdit;
    remark = new QLineEdit;

    //设置位置
    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 6+num);
    gLayout->addWidget(nameLabel, 0, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(name, 0, 1, Qt::AlignLeft);

    gLayout->addWidget(dateLabel, 1, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(date, 1, 1, Qt::AlignLeft);

    gLayout->addWidget(priceLabel, 2, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(price, 2, 1, Qt::AlignLeft);

    gLayout->addWidget(unitLabel, 3, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(unit, 3, 1, Qt::AlignLeft);

    gLayout->addWidget(shopLabel, 4, 0,Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(shop, 4, 1, Qt::AlignLeft);

    gLayout->addWidget(remarkLabel, 5, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(remark, 5, 1, Qt::AlignLeft);

    for(int i=0;i<num;i++)
    {
        peoplepay1[i] = new QLabel(namestr[i]+" - money paid");
        peoplepay[i] = new QLineEdit;
        gLayout->addWidget(peoplepay1[i], 6+i, 0, Qt::AlignLeft|Qt::AlignTop);
        gLayout->addWidget(peoplepay[i], 6+i, 1, Qt::AlignLeft);
    }
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 6+num, 1, Qt::AlignRight);

    //显示
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    //按钮
    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle(tr("Add a Commodity"));
}
//! [0]
