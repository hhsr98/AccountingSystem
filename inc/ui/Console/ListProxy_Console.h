#ifndef __LISTPROXY_CONSOLE_H
#define __LISTPROXY_CONSOLE_H

#include "../ListProxy.h"
#include "../Console/CommodityProxy_Console.h"
class ListProxy_Console:public ListProxy
{
    using ListProxy::_list;

    CommodityProxy* getCommodityProxy(Commodity *com)
    {
        return new CommodityProxy_Console(com);
    }
public:
    using ListProxy::ListProxy;
    void show();
    void unshow();
    void showManip();
};
#endif // __LISTPROXY_CONSOLE_H
