#ifndef __COMMODITYPROXY_H
#define __COMMODITYPROXY_H

#include "ui/AbstractProxy.h"
#include "ui/ClassifyProxy.h"
#include "Commodity.h"

class CommodityProxy : public AbstractProxy
{
protected:
    Commodity *com;
    virtual ClassifyProxy* getClassifyProxy(List *root_list)=0;
public:
    CommodityProxy(Commodity *_com):com(_com){}
    AbstractProxy::state manipulate(std::string order,AbstractProxy *&new_proxy );
};


#endif // __COMMODITYPROXY_H
