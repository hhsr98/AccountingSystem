#ifndef __MULTILISTPROXY_H
#define __MULTILISTPROXY_H

#include "AbstractProxy.h"
#include "../MultiList.h"
class PayingEntryProxy;
class MultiListProxy:public AbstractProxy {
	virtual PayingEntry* getPayingEntryProxy(PayingEntry* entry)=0;
protected:
	MultiList *_list;
public:
	MultiListProxy(MultiList* m):_list(m){}
	AbstractProxy::state manipulate(std::string order,AbstractProxy*&new_proxy);
};
#endif
