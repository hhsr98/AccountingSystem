#include "ui/CommodityProxy.h"

#include<sstream>
using std::istringstream;
AbstractProxy::state CommodityProxy::manipulate(std::string order, AbstractProxy *&new_proxy)
{
    istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;//-r ������һ��
        if(temp=="-x") return AbstractProxy::quit;//-x �˳�ϵͳ
        if(temp=="-e") //�޸���Ʒ��Ϣ
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
