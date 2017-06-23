#ifndef __PROXYMANAGER_H
#define __PROXYMANAGER_H

#include<deque>
#include "AbstractProxy.h"

class ProxyManager
{
    std::deque<AbstractProxy*> proxy_stack;
    int max_storing_proxy;
    static const int least_storing_proxy=50;
public:
    ProxyManager():proxy_stack(),max_storing_proxy(){max_storing_proxy=least_storing_proxy;}
    ProxyManager(int max_return): proxy_stack(),max_storing_proxy(max_return){}

    //向栈中添加一Proxy并进行显示
    void addProxy(AbstractProxy *proxy);

    //弹出栈顶的Proxy并显示新栈顶Proxy
    void deleteProxy();

    //向栈顶Proxy传送指令
    //返回值：0x0 指令执行成功
    //        0x1 指令执行失败
    //        0x2 退出整个系统
    enum state
    {
        success=0x0,
        fail,
        quit
    };
    state process(std::string order);

};
#endif // __PROXYMANAGER_H
