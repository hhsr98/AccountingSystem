#-------------------------------------------------
#
# Project created by QtCreator 2017-06-15T14:53:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_demo_01
TEMPLATE = app

INCLUDEPATH += third_party/inc
INCLUDEPATH += third_party/src
INCLUDEPATH += inc/
INCLUDEPATH += inc/ui/
INCLUDEPATH += inc/ui/Console
INCLUDEPATH += inc/ui/GUI
INCLUDEPATH += src/
INCLUDEPATH += src/ui/
INCLUDEPATH += src/ui/Console
INCLUDEPATH += src/ui/GUI
SOURCES += main.cpp\
        mainwindow.cpp \
    src/Analize.cpp \
    src/Commodity.cpp \
    src/date.cpp \
    src/Display.cpp \
    src/ExchangeRate.cpp \
    src/Filter.cpp \
    src/list.cpp \
    src/MultiList.cpp \
    src/MultiMoney.cpp \
    src/PayingEntry.cpp \
    src/SampleTest.cpp \
    src/SingleMoney.cpp \
    src/SingleMoneyTest.cpp \
    src/test.cpp \
    src/test_multilist.cpp \
    src/Unit.cpp \
    src/ui/CommodityProxy.cpp \
    src/ui/ListProxy.cpp \
    src/ui/MultiListProxy.cpp \
    src/ui/ProxyManager.cpp \
    src/ui/Console/CommodityProxy_Console.cpp \
    src/ui/Console/ListProxy_Console.cpp \
    src/ui/Console/MultiListProxy_Console.cpp \
    src/ui/Gui/adddialog.cpp \
    src/ui/Gui/addwidget.cpp \
    src/ui/Gui/commodityproxy_gui.cpp \
    src/ui/Gui/filterdialog.cpp \
    src/ui/Gui/filterwidget.cpp \
    src/ui/Gui/numberdialog.cpp \
    src/ui/Gui/namedialog.cpp \
    src/ui/Gui/globalvar.cpp

HEADERS  += mainwindow.h \
    inc/Analize.h \
    inc/Commodity.h \
    inc/date.h \
    inc/Display.h \
    inc/ExchangeRate.h \
    inc/Filter.h \
    inc/list.h \
    inc/MultiList.h \
    inc/MultiMoney.h \
    inc/PayingEntry.h \
    inc/Remark.h \
    inc/Shop.h \
    inc/SingleMoney.h \
    inc/test.h \
    inc/Unit.h \
    inc/User.h \
    inc/ui/AbstractProxy.h \
    inc/ui/CommodityProxy.h \
    inc/ui/ListProxy.h \
    inc/ui/MultiListProxy.h \
    inc/ui/ProxyManager.h \
    inc/ui/Console/CommodityProxy_Console.h \
    inc/ui/Console/ListProxy_Console.h \
    inc/ui/Console/MultiListProxy_Console.h \
    inc/ui/Gui/adddialog.h \
    inc/ui/Gui/addwidget.h \
    inc/ui/Gui/commodityproxy_gui.h \
    inc/ui/Gui/filterdialog.h \
    inc/ui/Gui/filterwidget.h \
    inc/ui/Gui/detailslot.h \
    inc/ui/Gui/namedialog.h \
    inc/ui/Gui/numberdialog.h \
    inc/ui/Gui/globalvar.h



FORMS    += mainwindow.ui

DISTFILES += \
    inc/location.py
