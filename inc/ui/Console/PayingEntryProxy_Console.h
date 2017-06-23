#ifndef __PAYINGENTRYPROXY_CONSOLE_H
#define __PAYINGENTRYPROXY_CONSOLE_H
#include "ui/PayingEntryProxy.h"

class PayingEntryProxy_Console : public PayingEntryProxy
{
public:
    using PayingEntryProxy::PayingEntryProxy;
    void show();
    void unshow();
    void showManip();
};
#endif // __PAYINGENTRYPROXY_CONSOLE_H
