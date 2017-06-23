/*****************************************************

 名称：MainWindow.h

 作者：钱姿 邢健开

 内容描述：定义MainWindow类，该类时显示的主窗口

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <QMainWindow>
#include <QTableWidget>
#include <vector>
#include <Commodity.h>
#include <addwidget.h>
#include <filterwidget.h>
#include <NameDialog.h>
#include <NumberDialog.h>
#include "globalvar.h"
#include"PayingEntry.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class CommodityProxy_GUI;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static int num_row;
    QTableWidget *table;
    FilterWidget *filterWidget;
    AddWidget *addWidget;
    void initSingleList();
    void enterNumber();
    void enterName(int num);
    void initMultiList();
    //void addshow(Commodity*com);
    static std::vector<Commodity*> com;
    //static List allList;

private:

    Ui::MainWindow *ui;
    QMenu *toolMenu;
    QMenu *addMenu;
    QAction *addAct;
    QAction *FilterAct;

public slots:
    void add(Commodity* com_0);
    void adds(std::vector<Commodity*> coms);
    //void add(PayingEntry* com_0);
private slots:
    void on_Single_clicked();
    void on_Multi_clicked();
};

#endif // MAINWINDOW_H
