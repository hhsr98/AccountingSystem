#include "ui/ProxyManager.h"

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
int ProxyManager::process(std::string order)
{
    if(!proxy_stack.empty())
    {
        AbstractProxy *new_proxy;
        int re=proxy_stack.back()->manipulate(order,new_proxy);
        switch(re)
        {
        case 0x0:
            return 0x0;
            break;
        case 0x1:
            addProxy(new_proxy);
            return 0x0;
            break;
        case 0x2:
            deleteProxy();
            return 0x0;
            break;
        case 0x3:
            return 0x1;
            break;
        case 0x4:
            return 0x2;
            break;
        }
    }
}
