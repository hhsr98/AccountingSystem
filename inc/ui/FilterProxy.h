#ifndef __FILTERPROXY_H
#define __FILTERPROXY_H

#include "ui/AbstractProxy.h"
#include "ui/ListProxy.h"
#include "Filter.h"
#include <memory>
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
