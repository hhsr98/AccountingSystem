/*******************************************************
名称：ClassifyProxy.h
作者：钱姿
最后修改：2017-06-21
内容描述：商品分类代理类头文件。该类对象为对商品进行分
          类提供了相应接口。
*******************************************************/
#ifndef __CLASSIFYPROXY_H
#define __CLASSIFYPROXY_H

#include "ui/AbstractProxy.h"
#include "list.h"
#include "Commodity.h"
#include <map>
class ClassifyProxy:public AbstractProxy
{

protected:
    List *root;
    Commodity *com;
    std::map<int,List*> num_list;
    std::map<List*,int> list_num;

    void getListNum();
public:
    ClassifyProxy(List *root_list,Commodity *commo);
    AbstractProxy::state manipulate(std::string order,AbstractProxy *&new_proxy );
};

#endif // __CLASSIFYPROXY_H
