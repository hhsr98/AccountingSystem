#ifndef __LISTPROXY_CONSOLE_H
#define __LISTPROXY_CONSOLE_H

#include "ui/ListProxy.h"
#include "ui/Console/CommodityProxy_Console.h"
class ListProxy_Console:public ListProxy
{
    using ListProxy::_list;
    ListProxy* getListProxy(List *l)
    {
        return new ListProxy_Console(l);
    }
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
