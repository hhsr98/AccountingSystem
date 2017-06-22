#ifndef __ADDCOMMODITYPROXY_H
#define __ADDCOMMODITYPROXY_H

#include "ui/AbstractProxy.h"
#include "ui/CommodityProxy.h"
#include "Commodity.h"
#include "list.h"

class AddCommodityProxy :public AbstractProxy
{
    virtual CommodityProxy* getCommodityProxy(Commodity *commo)=0;
protected:
    Commodity *com;
    bool is_saved;
    List* faList;
public:
    AddCommodityProxy(List *l=nullptr);
    AbstractProxy::state manipulate(std::string order,AbstractProxy *&new_proxy);
    ~AddCommodityProxy();
};
#endif // __ADDCOMMODITYPROXY_H
