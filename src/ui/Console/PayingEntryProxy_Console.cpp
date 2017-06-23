#include "ui/Console/PayingEntryProxy_Console.h"

void PayingEntryProxy_Console::show()
{
    std::cout<<*_com;
    for(int i=0;i<person_list.size();i++)
    {
        std::cout<<"\t"<<i<<"\t"<<person_list[i]->Name()<<std::endl;
    }
}
void PayingEntryProxy_Console::unshow()
{

}
void PayingEntryProxy_Console::showManip()
{
    std::cout<<"-r 返回上一级\t-x退出系统\t-f刷新\n";
    std::cout<<"-a -p <i> <ratio> 添加序号为i的人已付比例为ratio\n";
    std::cout<<"-a -t <i> <ratio> 添加序号为i的人应付比例为ratio\n";
}
