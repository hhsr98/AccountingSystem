#ifndef __LISTPROXY_H
#define __LISTPROXY)H

#include "ui/AbstractProxy.h"
#include "ui/CommodityProxy.h"
#include "list.h"
class ListProxy : public AbstractProxy
{
    virtual CommodityProxy* getCommodityProxy(Commodity *com)=0;
protected:
    List *_list;
public:
    ListProxy(List *l):_list(l){}
    AbstractProxy::state manipulate(std::string order,AbstractProxy *&new_proxy );
};
#endif // __LISTPROXY_H
