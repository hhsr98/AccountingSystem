#ifndef __MULTILISTPROXY_CONSOLE_H
#define __MULTILISTPROXY_CONSOLE_H
#include"ui/MultiListProxy.h"
class PayingEntryProxy_Console;
class MultiListProxy_Console:public MultiListProxy {
	
	using MultiListProxy::_list;

	PayingEntry* getPayingEntryProxy(PayingEntry* entry) {
		//return new PayingEntryProxy_Console(entry);
	}

public:
	using MultiListProxy::MultiListProxy;
	void show();
	void unshow();
	void showManip();

};

#endif