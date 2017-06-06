#include "ui/ClassifyProxy.h"
#include<sstream>
#include<set>
ClassifyProxy::ClassifyProxy(List *root_list,Commodity *commo):root(root_list),com(commo)
{
    getListNum();
}
void ClassifyProxy::getListNum()
{
    num_list.clear();list_num.clear();
    std::set<List*> set_l=root->get_Sublist_All();
    num_list[0]=root;
    list_num[root]=0;
    int i=1;
    for(auto l:set_l)
    {
        num_list[i]=l;
        list_num[l]=i;
        i++;
    }
}
AbstractProxy::state ClassifyProxy::manipulate(std::string order, AbstractProxy *&new_proxy)
{
    std::istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;//-r 返回上一级
        if(temp=="-x") return AbstractProxy::quit;//-x 退出系统
        if(temp=="-f") {show(); return AbstractProxy::done;}
        if(temp=="-a")
        {
            int idx;
            if(is>>idx)
            {
                if(num_list.find(idx)!=num_list.end())
                {
                    num_list[idx]->addCommodity(com);
                    return AbstractProxy::go_back;
                }
                return AbstractProxy::fail;
            }
            return AbstractProxy::fail;
        }
        return AbstractProxy::fail;
    }
    return AbstractProxy::fail;
}
