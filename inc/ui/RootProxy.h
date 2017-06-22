/*******************************************************
名称：RootProxy.h
作者：黄松睿
最后修改：2017-06-21
内容描述：根代理类头文件。根代理对象为用户进行各种操作
          的最初入口。
*******************************************************/
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
