#ifndef __FILTERPROXY_CONSOLE_H
#define __FILTERPROXY_CONSOLE_H

#include "ui/FilterProxy.h"
#include "ui/Console/ListProxy_Console.h"

class FilterProxy_Console :public FilterProxy
{
    ListProxy* getListProxy(List *l);
public:
    using FilterProxy::FilterProxy;
    void show();
    void unshow();
    void showManip();
};
#endif // __FILTERPROXY_CONSOLE_H
