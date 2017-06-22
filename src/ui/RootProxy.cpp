#include "ui/RootProxy.h"
#include<sstream>
AbstractProxy::state RootProxy::manipulate(std::string order,AbstractProxy *&new_proxy)
{
    std::istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;//-r 返回上一级
        if(temp=="-x") return AbstractProxy::quit;//-x 退出系统
        if(temp=="-f") {show(); return AbstractProxy::done;}
        if(temp=="-a") {new_proxy=getAddCommodityProxy();return AbstractProxy::new_proxy;}
        if(temp=="-d") {new_proxy=getListProxy(AbstractProxy::RootDateList);return AbstractProxy::new_proxy;}
        if(temp=="-c") {new_proxy=getListProxy(AbstractProxy::RootClassifyList);return AbstractProxy::new_proxy;}
    }
    return AbstractProxy::fail;

}
