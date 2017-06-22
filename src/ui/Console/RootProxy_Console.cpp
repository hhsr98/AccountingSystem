#include "ui/Console/RootProxy_Console.h"

#include "ui/Console/ListProxy_Console.h"
#include "ui/Console/AddCommodityProxy_Console.h"

AddCommodityProxy* RootProxy_Console::getAddCommodityProxy()
{
    return new AddCommodityProxy_Console;
}
ListProxy* RootProxy_Console::getListProxy(List *l)
{
    return new ListProxy_Console(l);
}
void RootProxy_Console::show()
{

}
void RootProxy_Console::unshow()
{

}
void RootProxy_Console::showManip()
{
    std::cout<<"********************主界面*********************\n";
    std::cout<<"-x 退出系统\n";
    std::cout<<"-c 查看商品分类\n";
    std::cout<<"-d 查看购买日志\n";
    std::cout<<"-a 添加商品\n";
}
