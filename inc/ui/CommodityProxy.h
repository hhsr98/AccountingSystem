#ifndef __COMMODITYPROXY_H
#define __COMMODITYPROXY_H

#include "AbstractProxy.h"
#include "../Commodity.h"

class CommodityProxy : public AbstractProxy
{
protected:
    Commodity *com;
public:
    CommodityProxy(Commodity *_com):com(_com){}
    AbstractProxy::state manipulate(std::string order,AbstractProxy *&new_proxy );
};


#endif // __COMMODITYPROXY_H
