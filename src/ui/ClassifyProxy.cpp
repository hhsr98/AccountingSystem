/*******************************************************
名称：ClassifyProxy.cpp
作者：钱姿
最后修改：2017-06-21
内容描述：商品分类代理类源文件。
*******************************************************/
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
/*
*order格式：
*   -r  返回
*   -x  退出整个系统
*   -f  刷新显示内容
*   -a  <序号> 添加商品到该序号的分类下
*   -l  <序号> <分类名> 在该序号的分类下新建一分类
*/
AbstractProxy::state ClassifyProxy::manipulate(std::string order, AbstractProxy *&new_proxy)
{
    std::istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;//-r 返回上一级
        if(temp=="-x") return AbstractProxy::quit;//-x 退出系统
        if(temp=="-f") {show(); return AbstractProxy::done;} //刷新
        if(temp=="-a")  //将商品添加进序号为idx的分类中
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
        if(temp=="-l") //在序号为idx的分类下新建名为temp1的分类
        {
            int idx;std::string temp1;
            if(is>>idx>>temp1)
            {
                if(num_list.find(idx)!=num_list.end())
                {
                    List *new_list=new List(nullptr);
                    new_list->setListName(temp1);
                    num_list[idx]->addSublist(new_list);
                    getListNum();
                    show();
                    showManip();
                    return AbstractProxy::done;
                }

            }
        }
        return AbstractProxy::fail;
    }
    return AbstractProxy::fail;
}
