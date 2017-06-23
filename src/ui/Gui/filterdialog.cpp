#include "filterdialog.h"
#include <QtWidgets>

//! [0]
//!
//建立筛选窗口
filterdialog::filterdialog(QWidget *parent)
    : QDialog(parent)
{
    lpLabel = new QLabel("low price");
    hpLabel = new QLabel("high price");
    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    lp = new QLineEdit;
    hp = new QLineEdit;

    QGridLayout *gLayout = new QGridLayout;
    gLayout->setColumnStretch(1, 2);
    gLayout->addWidget(lpLabel, 0, 0);
    gLayout->addWidget(lp, 0, 1);

    gLayout->addWidget(hpLabel, 1, 0, Qt::AlignLeft|Qt::AlignTop);
    gLayout->addWidget(hp, 1, 1, Qt::AlignLeft);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 2, 1, Qt::AlignRight);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle(tr("Filter"));
}
//! [0]
