#include "namedialog.h"
#include <QtWidgets>

//! [0]
//!
//建立筛选窗口
NameDialog::NameDialog(int n,QWidget *parent)
    : QDialog(parent)
{
    for(int i=0;i<n;i++)
        namestr[i] = new QLabel("name"+QString(i));

    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    for(int i=0;i<n;i++)
        name[i] = new QLineEdit;

    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(n, 2);
    for(int i=0;i<n;i++)
    {
        gLayout->addWidget(namestr[i], i, 0);
        gLayout->addWidget(name[i], i, 1);
    }
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, n, 1, Qt::AlignRight);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);
    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);
    setWindowTitle(tr("enter name"));
}
//! [0]
