/*****************************************************

 名称：filterdialog.h

 作者：邢健开

 内容描述：定义filterdialog类，该类是筛选窗口

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/
#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H
//建立筛选对话框
#include <QDialog>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTextEdit;
class QLineEdit;
QT_END_NAMESPACE

//! [0]
class filterdialog : public QDialog
{
    Q_OBJECT

public:
    filterdialog(QWidget *parent = 0);
    QLineEdit *lp,*hp;
private:
    //最低价，最高价
    QLabel *lpLabel;
    QLabel *hpLabel;
    QPushButton *okButton;
    QPushButton *cancelButton;
};
//! [0]

#endif // FILTERDIALOG_H
