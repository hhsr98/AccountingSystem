#ifndef __ADDCOMMODITYPROXY_CONSOLE_H
#define __ADDCOMMODITYPROXY_CONSOLE_H

#include "ui/AddCommodityProxy.h"

class AddCommodityProxy_Console:public AddCommodityProxy
{
    CommodityProxy* getCommodityProxy(Commodity *commo);
public:
    using AddCommodityProxy::AddCommodityProxy;
    void show();
    void showManip();
    void unshow();
};

#endif // __ADDCOMMODITYPROXY_CONSOLE_H
