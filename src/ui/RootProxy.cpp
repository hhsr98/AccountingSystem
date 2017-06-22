/*******************************************************
名称：RootProxy.cpp
作者：黄松睿
最后修改：2017-06-21
内容描述：根代理类源文件。
*******************************************************/
#include "ui/RootProxy.h"
#include<sstream>
/*
*order格式：
*   -r  返回
*   -x  退出整个系统
*   -f  刷新显示内容
*   -a  进行新商品的添加
*   -d  按日期查看商品
*   -c  按分类查看商品
*/
AbstractProxy::state RootProxy::manipulate(std::string order,AbstractProxy *&new_proxy)
{
    std::istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;
        if(temp=="-x") return AbstractProxy::quit;
        if(temp=="-f") {show(); return AbstractProxy::done;}
        if(temp=="-a") {new_proxy=getAddCommodityProxy();return AbstractProxy::new_proxy;}
        if(temp=="-d") {new_proxy=getListProxy(AbstractProxy::RootDateList);return AbstractProxy::new_proxy;}
        if(temp=="-c") {new_proxy=getListProxy(AbstractProxy::RootClassifyList);return AbstractProxy::new_proxy;}
    }
    return AbstractProxy::fail;

}
