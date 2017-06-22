/*******************************************************
名称：AddCommodityProxy.h
作者：钱姿
最后修改：2017-06-21
内容描述：添加商品信息代理类头文件。该类对象为添加商品
          信息的操作提供了相应的接口。
*******************************************************/
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
