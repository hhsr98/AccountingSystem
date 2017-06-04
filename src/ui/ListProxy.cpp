#include "ui/ListProxy.h"
#include<stdio.h>
#include<sstream>
using std::istringstream;
AbstractProxy::state ListProxy::manipulate(std::string order, AbstractProxy *&new_proxy)
{
    istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;//-r 返回上一级
        if(temp=="-x") return AbstractProxy::quit;//-x 退出系统
        if(temp=="-f") {show(); return AbstractProxy::done;}
        if(temp=="-n")
        {
            int i;
            is>>i;
            Commodity *sub_com=_list->getCommodity(i);
            if(sub_com!=nullptr) {new_proxy=getCommodityProxy(sub_com);return AbstractProxy::new_proxy;}
            else return AbstractProxy::fail;
        }
    }
    return AbstractProxy::fail;
}

