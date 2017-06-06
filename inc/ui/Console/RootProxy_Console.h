#ifndef __ROOTPROXY_CONSOLE_H
#define __ROOTPROXY_CONSOLE_H

#include "ui/RootProxy.h"

class RootProxy_Console : public RootProxy
{
    ListProxy* getListProxy(List *l);
public:
    using RootProxy::RootProxy;
    void show();
    void unshow();
    void showManip();
};
#endif // __ROOTPROXY_CONSOLE_H
