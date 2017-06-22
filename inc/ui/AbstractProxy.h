/*******************************************************
名称：AbstractProxy.h
作者：黄松睿
最后修改：2017-06-21
内容描述：抽象代理类头文件。代理类负责对各个对象的显示、
          操作提示及操作，AbstractProxy为各种代理的抽象
          接口类。
*******************************************************/
#ifndef __ABSTRACTPROXY_H
#define __ABSTRACTPROXY_H


#include<string>
#include "list.h"

class AbstractProxy
{
public:
    static List* RootClassifyList;      //商品分类的根目录
    static List* RootDateList;          //商品按日期查看的根目录

    //将商品按一树形目录进行归类，若一个节点本身符合条件，无子节点或其全部子节点都不符合条件，则将商品归类于该节点。
    static bool AutoClassiy(Commodity *com,List *root);

    //显示被代理对象的内容
    virtual void show()=0;

    //清楚显示内容
    virtual void unshow()=0;

    //显示可以对该对象执行的操作，包含操作提示
    virtual void showManip()=0;

    //执行操作，order为字符串命令
    //返回值：0x0-成功执行了操作
    //        0x1-成功执行了操作，生成一个新的AbstractProxy*置于第二个参数中
    //        0x2-成功执行了操作，并申请将本身销毁
    //        0x3-操作失败
    //        0x4-退出整个系统
    enum state
    {
        done=0x0,
        new_proxy,
        go_back,
        fail,
        quit
    };
    virtual state manipulate(std::string order,AbstractProxy *&new_proxy )=0;


};

#endif // __ABSTRACTPROXY_H
