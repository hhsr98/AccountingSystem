/*******************************************************
名称：AbstractProxy.cpp
作者：黄松睿
最后修改：2017-06-21
内容描述：抽象代理类源文件。
*******************************************************/
#include "ui/AbstractProxy.h"
#include <set>
List* AbstractProxy::RootClassifyList=nullptr;
List* AbstractProxy::RootDateList=nullptr;
bool AbstractProxy::AutoClassiy(Commodity *com,List *root)
{
    bool is_in=true;
    if(!root->isValidCommodity(com)) return false;
    std::set<List*> sub_l=root->get_Sublist();
    for(auto l:sub_l)
    {
        if(AutoClassiy(com,l))
            is_in=false;
    }
    if(is_in)
    {
        root->addCommodity(com);
    }
    return true;
}
