#ifndef __COMMODITYPROXY_CONSOLE_H
#define __COMMODITYPROXY_CONSOLE_H

#include "../CommodityProxy.h"
class CommodityProxy_Console:public CommodityProxy
{
    using CommodityProxy::com;
public:
    using CommodityProxy::CommodityProxy;
    void show();
    void unshow();
    void showManip();
};
#endif // __COMMODITYPROXY_CONSOLE_H
