/*****************************************************

 名称：MainWindow.h

 作者：钱姿 邢健开

 内容描述：定义MainWindow类，该类时显示的主窗口

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QTableWidget>
#include "Commodity.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QPushButton>
#include <QObject>

#include "commodityproxy_gui.h"
#include "filterwidget.h"
#include "adddialog.h"
#include "addwidget.h"

std::vector<Commodity*> MainWindow::com;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("My AccountSystem");
    //initSingleList();
    //initSingleList();

}
void MainWindow::initSingleList(){

    filterWidget = new FilterWidget;
    addWidget=new AddWidget;

    //显示表头
    table = new QTableWidget(0,4);
    QStringList headerLabels;
    headerLabels << "Date" << "Name"<<"Price"<<"Detail";
    table->setHorizontalHeaderLabels(headerLabels);
    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    table->horizontalHeader()->setStretchLastSection(true);

    //设置菜单栏

    addMenu = menuBar()->addMenu(tr("&Add"));
    addAct = new QAction(tr("&Add new commodity..."), this);
    addMenu->addAction(addAct);
    connect(addAct,&QAction::triggered, addWidget,&AddWidget::showAddEntryDialog_Multi);
    connect(addWidget,SIGNAL(sendcom(Commodity*)),this,SLOT(add(Commodity*)));

    toolMenu = menuBar()->addMenu(tr("&Tools"));
    FilterAct = new QAction(tr("&Filter Entry..."), this);
    toolMenu->addAction(FilterAct);

    connect(FilterAct, &QAction::triggered, filterWidget, &FilterWidget::showFilterEntryDialog);
    connect(filterWidget, SIGNAL(sendList(std::vector<Commodity*>)), this, SLOT(adds(std::vector<Commodity*>)));
    //第二个connect的后两个参数换成接收list指针并显示的类和函数

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->addWidget(table);
    QWidget *centerWindow = new QWidget(this);
    this->setCentralWidget(centerWindow);
    centerWindow->setLayout(vbox);
}


void MainWindow::enterNumber()
{
    NumberDialog d1;
    if(d1.exec())
    {
        int peo = d1.num->text().toInt();
        qDebug()<<peo;
        enterName(peo);
    }
}
void MainWindow::enterName(int num)
{
    NameDialog d2(num);
    if(d2.exec())
    {
        //qDebug()<<"done";
        for(int i=0;i<num;i++)
            namestr.push_back(d2.name[i]->text());
        initMultiList();
    }
}
void MainWindow::initMultiList(){
    qDebug()<<namestr.size()<<" in init";
    filterWidget = new FilterWidget;
    addWidget=new AddWidget;

    //显示表头
    table = new QTableWidget(0,4);
    QStringList headerLabels;
    headerLabels << "Date" << "Name"<<"Price"<<"Detail";
    table->setHorizontalHeaderLabels(headerLabels);
    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    table->horizontalHeader()->setStretchLastSection(true);

    //设置菜单栏

    addMenu = menuBar()->addMenu(tr("&Add"));
    addAct = new QAction(tr("&Add new commodity..."), this);
    addMenu->addAction(addAct);
    connect(addAct,&QAction::triggered, addWidget,&AddWidget::showAddEntryDialog_Multi);
    connect(addWidget,SIGNAL(sendcom(Commodity*)),this,SLOT(add(Commodity*)));

    toolMenu = menuBar()->addMenu(tr("&Tools"));
    FilterAct = new QAction(tr("&Filter Entry..."), this);
    toolMenu->addAction(FilterAct);

    connect(FilterAct, &QAction::triggered, filterWidget, &FilterWidget::showFilterEntryDialog);
    connect(filterWidget, SIGNAL(sendList(std::vector<Commodity*>)), this, SLOT(adds(std::vector<Commodity*>)));

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->addWidget(table);
    QWidget *centerWindow = new QWidget(this);
    this->setCentralWidget(centerWindow);
    centerWindow->setLayout(vbox);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//显示筛选出的商品
void MainWindow::adds(std::vector<Commodity*> coms)
{
    QTableWidget* table = new QTableWidget(0,4);
    QStringList headerLabels;
    headerLabels << "Date" << "Name"<<"Price"<<"Detail";
    table->setHorizontalHeaderLabels(headerLabels);
    table->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    table->horizontalHeader()->setStretchLastSection(true);
    int cnt=0;
    for(auto i:coms)
    {
        cnt++;
        CommodityProxy_GUI gui1(i);
        gui1.show(table);
    }
    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->addWidget(table);
    QWidget *centerWindow = new QWidget();
    centerWindow->setLayout(vbox);
    centerWindow->show();
    qDebug()<<"num:"<<cnt;
}
//添加商品
void MainWindow::add(Commodity* com)
{
    filterWidget->allCommodity.push_back(com);
    this->com.push_back(com);
    CommodityProxy_GUI gui1(com);
    gui1.show(this->table);
}

void MainWindow::on_Single_clicked()
{
    initSingleList();
}

void MainWindow::on_Multi_clicked()
{
    enterNumber();
}
