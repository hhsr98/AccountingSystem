#ifndef __CLASSIFYPROXY_CONSOLE_H
#define __CLASSIFYPROXY_CONSOLE_H
#include "ui/ClassifyProxy.h"
class ClassifyProxy_Console:public ClassifyProxy
{
    void showHierarchy(int level,List *l);
public:
    using ClassifyProxy::ClassifyProxy;
    void show();
    void showManip();
    void unshow();
};
#endif // __CLASSIFYPROXY_CONSOLE_H
