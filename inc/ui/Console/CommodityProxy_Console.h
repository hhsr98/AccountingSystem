#ifndef __COMMODITYPROXY_CONSOLE_H
#define __COMMODITYPROXY_CONSOLE_H

#include "ui/CommodityProxy.h"
class CommodityProxy_Console:public CommodityProxy
{
    using CommodityProxy::com;
    ClassifyProxy* getClassifyProxy(List *root_list);
public:
    using CommodityProxy::CommodityProxy;
    void show();
    void unshow();
    void showManip();
};
#endif // __COMMODITYPROXY_CONSOLE_H
