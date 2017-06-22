/*******************************************************
���ƣ�ClassifyProxy.h
���ߣ�Ǯ��
����޸ģ�2017-06-21
������������Ʒ���������ͷ�ļ����������Ϊ����Ʒ���з�
          ���ṩ����Ӧ�ӿڡ�
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
