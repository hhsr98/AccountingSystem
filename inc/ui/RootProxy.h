#ifndef __ROOTPROXY_H
#define __ROOTPROXY_H

#include "ui/AbstractProxy.h"
#include "ui/ListProxy.h"
#include "ui/AddCommodityProxy.h"

class RootProxy:public AbstractProxy
{
    virtual ListProxy* getListProxy(List *l)=0;
    virtual AddCommodityProxy* getAddCommodityProxy()=0;
public:
    RootProxy(){}
    AbstractProxy::state manipulate(std::string order,AbstractProxy *&new_proxy );
};

#endif // __ROOTPROXY_H
