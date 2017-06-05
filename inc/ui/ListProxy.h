#ifndef __LISTPROXY_H
#define __LISTPROXY_H

#include "ui/AbstractProxy.h"
#include "ui/CommodityProxy.h"
#include "ui/FilterProxy.h"
#include "list.h"

class FilterProxy;

class ListProxy : public AbstractProxy
{
    virtual CommodityProxy* getCommodityProxy(Commodity *com)=0;
    virtual ListProxy* getListProxy(List *l)=0;
    virtual FilterProxy* getFilterProxy(List *l)=0;
protected:
    List *_list;
public:
    ListProxy(List *l):_list(l){}
    AbstractProxy::state manipulate(std::string order,AbstractProxy *&new_proxy );
};
#endif // __LISTPROXY_H
