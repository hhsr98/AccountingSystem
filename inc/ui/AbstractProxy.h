#ifndef __ABSTRACTPROXY_H
#define __ABSTRACTPROXY_H


#include<string>
#include "list.h"

class AbstractProxy
{
public:
    static List* RootClassifyList;

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
