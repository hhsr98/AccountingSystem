#include "ui/PayingEntryProxy.h"
#include<sstream>
using std::istringstream;
PayingEntryProxy::PayingEntryProxy(Commodity *_com/*,MultiList *l*/):entry(nullptr)//,li(l)
{
    entry=new PayingEntry(_com);
    for(auto p:*AbstractProxy::RootPersonList)
    {
        person_list.push_back(p);
    }
}
/*
*order格式：
*   -r  返回
*   -x  退出整个系统
*   -f  刷新显示内容
*   -a -p <i> <ratio> 添加序号为i的人已付比例为ratio
*   -a -t <i> <ratio> 添加序号为i的人应付比例为ratio
*/
AbstractProxy::state PayingEntryProxy::manipulate(std::string order,AbstractProxy *&new_proxy )
{
    istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;//-r 返回上一级
        if(temp=="-x") return AbstractProxy::quit;//-x 退出系统
        if(temp=="-f") {show(); return AbstractProxy::done;}
        if(temp=="-a")
        {
            int num;
            double rate;
            std::string temp1;
            if(is>>temp1>>num>>rate)
            {
                if(num<person_list.size())
                {
                    if(temp1=="-p")
                    {
                        entry->setRatioPayed(person_list[num],rate);
                        return AbstractProxy::done;
                    }
                    if(temp1=="-t")
                    {
                        entry->setRatioToPay(person_list[num],rate);
                        return AbstractProxy::done;
                    }
                    return AbstractProxy::fail;
                }
                return AbstractProxy::fail;
            }
            return AbstractProxy::fail;
        }
        return AbstractProxy::fail;
    }
    return AbstractProxy::fail;


}
