#include "ui/AddCommodityProxy.h"

#include<sstream>
using std::istringstream;

AddCommodityProxy::AddCommodityProxy(List *l):com(nullptr),faList(l),is_saved(false)
{
    com=new Commodity;
}
AddCommodityProxy::~AddCommodityProxy()
{
    if(!is_saved)
        delete com;
}
AbstractProxy::state AddCommodityProxy::manipulate(std::string order, AbstractProxy *&new_proxy)
{
    istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;//-r 返回上一级
        if(temp=="-x") return AbstractProxy::quit;//-x 退出系统
        if(temp=="-f") {show(); return AbstractProxy::done;}
        if(temp=="-s")
        {
            if(faList!=nullptr)
            {
                if(faList->addCommodity(com))
                {
                    new_proxy=getCommodityProxy(com);
                    is_saved=true;
                    return AbstractProxy::go_back;
                }
                else
                {
                    return AbstractProxy::fail;
                }
            }
            else
            {
                AbstractProxy::AutoClassiy(com,AbstractProxy::RootDateList);
                new_proxy=getCommodityProxy(com);
                is_saved=true;
                return AbstractProxy::go_back;
            }
        }
        if(temp=="-e") //修改商品信息
        {
            std::string temp1,temp2;
            if(is>>temp1>>temp2)
            {
                if(temp1=="-n")
                {
                    com->setCommodityName(temp2);
                    return AbstractProxy::done;
                }
                if(temp1=="-q")
				{
					double a;
					std::stringstream stream;
					//将string转换成double
					stream<<temp2;
					stream>>a;
					com->setQuantity(a);
					stream.clear();
					return AbstractProxy::done;
				}
				if(temp1=="-m")
				{
					std::string a,b;
					double a1;
					a=temp2.substr(0,temp2.size()-3);//将数字拷贝到a中
					std::stringstream stream;
					stream<<a;
					stream>>a1;//将字符串转化为double类型
					b=temp2.substr(temp2.size()-3,3);
					SingleMoney money(a1,b);//构造单币种金额类的新参数
					com->setUnitPrice(money);//重置
					return AbstractProxy::done;
				}
				if(temp1=="-o")
				{
					double temp;
					std::stringstream stream;
					//将string转换成double
					stream<<temp2;
					stream>>temp;
					com->setDiscount(temp);
					stream.clear();
					return AbstractProxy::done;
				}
				if(temp1=="-d")//输入格式为年月日时，例如2017070718 为2017年7月7日18点
				{
					double y,m,d,h;
					std::string y1,m1,d1,h1;
					y1=temp2.substr(0,4);
					m1=temp2.substr(4,2);
					d1=temp2.substr(6,2);
					h1=temp2.substr(8,2);
					std::stringstream stream;
					//将string转换成double
					stream<<y1;
					stream>>y;
					stream.clear();
					stream<<m1;
					stream>>m;
					stream.clear();
					stream<<d1;
					stream>>d;
					stream.clear();
					stream<<h1;
					stream>>h;
					stream.clear();
					Date date(y,m,d,h);
					com->setDate(date);
					AbstractProxy::AutoClassiy(com,AbstractProxy::RootDateList);
					return AbstractProxy::done;
				}

            }
            return AbstractProxy::fail;
        }
        return AbstractProxy::fail;
    }
    return AbstractProxy::fail;


}
