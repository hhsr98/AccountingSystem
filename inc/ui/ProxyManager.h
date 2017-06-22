/*******************************************************
名称：ProxyManager.h
作者：黄松睿
最后修改：2017-06-21
内容描述：代理管理类头文件。该类的对象负责管理各代理对
          象间的切换行为。
*******************************************************/
#ifndef __PROXYMANAGER_H
#define __PROXYMANAGER_H

#include<deque>
#include "ui/AbstractProxy.h"

class ProxyManager
{
    std::deque<AbstractProxy*> proxy_stack;
    int max_storing_proxy;      //栈的最大容量
    AbstractProxy *root;        //指向根代理对象
    static const int least_storing_proxy=50;
public:
    ProxyManager():proxy_stack(),max_storing_proxy(),root(nullptr){max_storing_proxy=least_storing_proxy;}
    ProxyManager(int max_return): proxy_stack(),max_storing_proxy(max_return),root(nullptr){}

    void setRootProxy(AbstractProxy *r);

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
