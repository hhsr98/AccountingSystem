#include "ui/CommodityProxy.h"

#include<sstream>
using std::istringstream;
AbstractProxy::state CommodityProxy::manipulate(std::string order, AbstractProxy *&new_proxy)
{
    istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;//-r 返回上一级
        if(temp=="-x") return AbstractProxy::quit;//-x 退出系统
        if(temp=="-e") //修改商品信息
        {
            std::string temp1,temp2;
            if(is>>temp1>>temp2)
            {
                if(temp1=="-n")
                {com->setCommodityName(temp2);return AbstractProxy::done;}
                if(temp1=="-q")
                {}
            }
            return AbstractProxy::fail;
        }
        return AbstractProxy::fail;
    }
    return AbstractProxy::fail;


}
