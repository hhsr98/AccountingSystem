/*******************************************************
名称：RootProxy.h
作者：黄松睿
最后修改：2017-06-21
内容描述：商品信息代理类头文件。商品信息代理对象为用户
          查看并修改商品信息提供了接口。
*******************************************************/
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
