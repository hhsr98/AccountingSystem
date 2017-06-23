/*****************************************************

 名称：numberdialog.h

 作者：邢健开

 内容描述：定义numberdialog类，该类是筛选窗口

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/
#ifndef NUMBERDIALOG_H
#define NUMBERDIALOG_H
#include <QDialog>
QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTextEdit;
class QLineEdit;
QT_END_NAMESPACE

//! [0]
class NumberDialog : public QDialog
{
    Q_OBJECT

public:
    //输入数字对话框
    NumberDialog(QWidget *parent = 0);
    QLineEdit *num;
private:
    QLabel *numstr;
    QPushButton *okButton;
    QPushButton *cancelButton;
};
//! [0]
#endif // NUMBERDIALOG_H
