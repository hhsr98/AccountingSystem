#include "ui/Console/FilterProxy_Console.h"
#include "ui/Console/ListProxy_Console.h"

ListProxy* FilterProxy_Console::getListProxy(List *l)
{
    return new ListProxy_Console(l);
}
void FilterProxy_Console::show()
{

}
void FilterProxy_Console::unshow()
{

}
void FilterProxy_Console::showManip()
{
    std::cout<<"-r 返回上一级\t-x退出系统\t-f刷新\n";
    std::cout<<"-c 进行筛选\n";
    std::cout<<"-a <指示符> <内容> 添加筛选条件\n";
    std::cout<<"\t<指示符> <内容>\n";
    std::cout<<"\t-d yyyymmddhh yyyymmddhh 时间范围\n";
    std::cout<<"\t-u x y currency 单价范围\n";
    std::cout<<"\t-t x y currency 总价范围\n";
}
