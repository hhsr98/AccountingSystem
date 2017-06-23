#ifndef __PAYINGENTRYPROXY_H
#define __PAYINGENTRYPROXY_H

#include "ui/AbstractProxy.h"
#include "PayingEntry.h"

class PayingEntryProxy: public AbstractProxy
{

protected:
    PayingEntry *entry;
    //MultiList *li;
    std::vector<Person*> person_list;
public:
    PayingEntryProxy(Commodity *_com/*,MultiList *l*/);
    AbstractProxy::state manipulate(std::string order,AbstractProxy *&new_proxy );
};

#endif // __PAYINGENTRYPROXY_H
