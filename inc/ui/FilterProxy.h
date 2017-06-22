/*******************************************************
名称：FilterProxy.h
作者：黄松睿
最后修改：2017-06-21
内容描述：商品筛选代理类头文件。该类对象提供了对某一账
          单下的商品进行筛选并返回一新账单的接口。
*******************************************************/
#ifndef __FILTERPROXY_H
#define __FILTERPROXY_H

#include "ui/AbstractProxy.h"
#include "ui/ListProxy.h"
#include "Filter.h"

class ListProxy;

class FilterProxy:public AbstractProxy
{
protected:
    Filter *aFilter;
    List *aList,*newList;
    virtual ListProxy* getListProxy(List *l)=0;
public:
    FilterProxy(List *_list):aList(_list),aFilter(nullptr),newList(nullptr){}
    AbstractProxy::state manipulate(std::string order,AbstractProxy *&new_proxy );
    virtual ~FilterProxy()
    {
        if(aFilter) delete aFilter;
        if(newList) delete newList;
    }
};
#endif // __FILTERPROXY_H
