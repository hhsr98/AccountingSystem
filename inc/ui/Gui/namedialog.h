/*****************************************************

 名称：namedialog.h

 作者：邢健开

 内容描述：定义namedialog类，该类是名字输入窗口

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/
#ifndef NAMEDIALOG_H
#define NAMEDIALOG_H
//
//输入人名对话框
#include <QDialog>

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QTextEdit;
class QLineEdit;
QT_END_NAMESPACE

//! [0]
class NameDialog : public QDialog
{
    Q_OBJECT

public:
    //最多支持10人账单
    NameDialog(int num,QWidget *parent = 0);
    QLineEdit *name[10];
private:
    QLabel *namestr[10];
    QPushButton *okButton;
    QPushButton *cancelButton;
};
//! [0]
#endif // NAMEDIALOG_H
