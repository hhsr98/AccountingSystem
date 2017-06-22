/*******************************************************
名称：FilterProxy.cpp
作者：黄松睿
最后修改：2017-06-21
内容描述：商品筛选代理类源文件。
*******************************************************/
#include "ui/FilterProxy.h"
#include<stdio.h>
#include<sstream>
using std::istringstream;
/*
*order格式：
*   -r  返回
*   -x  退出整个系统
*   -f  刷新显示内容
*   -c  根据已有筛选条件生产新账单
*   -a  添加筛选条件
*       -d  <开始日期：yyyymmddhh> <截止日期：yyyymmddhh>
*       -u  <单价下限> <单价上限> <币种>
*       -t  <总结下限> <总价上限> <币种>
*/
AbstractProxy::state FilterProxy::manipulate(std::string order, AbstractProxy *&new_proxy)
{
    istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;//-r 返回上一级
        if(temp=="-x") return AbstractProxy::quit;//-x 退出系统
        if(temp=="-c")
        {
            newList=new List(aFilter,aList);
            new_proxy=getListProxy(newList);
            return AbstractProxy::new_proxy;
        }
        if(temp=="-a")
        {
            std::string temp1,temp2,temp3,temp4;
            is>>temp1;
            if(temp1=="-d")//输入格式为年月日时，例如2017070718 为2017年7月7日18点
            {
                if(is>>temp2>>temp3)
                {
                    double y,m,d,h;
                    std::string y1,m1,d1,h1;

                    y1=temp2.substr(0,4);
                    m1=temp2.substr(4,2);
                    d1=temp2.substr(6,2);
                    h1=temp2.substr(8,2);
                    y=std::stoi(y1);m=std::stoi(m1);d=std::stoi(d1);h=std::stoi(h1);
                    Date date1(y,m,d,h);

                    y1=temp3.substr(0,4);
                    m1=temp3.substr(4,2);
                    d1=temp3.substr(6,2);
                    h1=temp3.substr(8,2);
                    y=std::stoi(y1);m=std::stoi(m1);d=std::stoi(d1);h=std::stoi(h1);
                    Date date2(y,m,d,h);
                    aFilter=new dateFilter(date1,date2,aFilter);
                    return AbstractProxy::done;
                }
                return AbstractProxy::fail;
            }
            if(temp1=="-u")
            {
                if(is>>temp2>>temp3>>temp4)
                {
                    aFilter=new priceFilter(std::stoi(temp2),std::stoi(temp3),temp4,aFilter);
                    return AbstractProxy::done;
                }
                return AbstractProxy::fail;
            }
            if(temp1=="-t")
            {
                if(is>>temp2>>temp3>>temp4)
                {
                    aFilter=new TotalPriceFilter(std::stoi(temp2),std::stoi(temp3),temp4,aFilter);
                    return AbstractProxy::done;
                }
                return AbstractProxy::fail;
            }

        }
        return AbstractProxy::fail;
    }
    return AbstractProxy::fail;
}

