#include "ProxyManager.h"
void ProxyManager::addProxy(AbstractProxy *proxy)
{
    if(!proxy_stack.empty()) proxy_stack.back()->unshow();
    proxy_stack.push_back(proxy);
    if(proxy_stack.size()>max_storing_proxy) proxy_stack.pop_front();
    proxy_stack.back()->show();
    proxy_stack.back()->showManip();
}
void ProxyManager::deleteProxy()
{
    if(!proxy_stack.empty())
    {
        proxy_stack.back()->unshow();
        proxy_stack.pop_back();
        if(!proxy_stack.empty()) {proxy_stack.back()->show();proxy_stack.back()->showManip();}
    }

}
ProxyManager::state ProxyManager::process(std::string order)
{
    if(!proxy_stack.empty())
    {
        AbstractProxy *new_proxy;
        AbstractProxy::state re=proxy_stack.back()->manipulate(order,new_proxy);
        switch(re)
        {
        case AbstractProxy::done:
            return success;
            break;
        case AbstractProxy::new_proxy:
            addProxy(new_proxy);
            return success;
            break;
        case AbstractProxy::go_back:
            deleteProxy();
            return success;
            break;
        case AbstractProxy::fail:
            return fail;
            break;
        case AbstractProxy::quit:
            return quit;
            break;
        }
    }
}
