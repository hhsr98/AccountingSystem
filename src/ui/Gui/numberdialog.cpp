#include "numberdialog.h"
#include <QtWidgets>

//! [0]
//!
//建立筛选窗口
NumberDialog::NumberDialog(QWidget *parent)
    : QDialog(parent)
{
    numstr = new QLabel("number of people");
    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    num = new QLineEdit;

    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);
    gLayout->addWidget(numstr, 0, 0);
    gLayout->addWidget(num, 0, 1);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 2, 1, Qt::AlignRight);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);
    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);
    setWindowTitle(tr("enter number"));
}
//! [0]
