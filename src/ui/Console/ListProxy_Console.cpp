#include "ui/Console/ListProxy_Console.h"
FilterProxy* ListProxy_Console::getFilterProxy(List *l)
{
    return new FilterProxy_Console(l);
}
void ListProxy_Console::show()
{
    std::cout<<"List Name:\t"<<_list->ListName()<<std::endl;
    std::cout<<"Commodities:\n";
    auto ll=_list->get_CommodityList();
    int i=0;
    for(auto com:ll)
    {
        std::cout<<'\t'<<i<<'\t'<<com->CommodityName()<<std::endl;
        i++;
    }
    std::cout<<"Sub Lists:\n";
    auto list_sub=_list->get_Sublist();
    i=0;
    for(auto sub_l:list_sub)
    {
        std::cout<<'\t'<<i<<'\t'<<sub_l->ListName()<<std::endl;
        i++;
    }

}
void ListProxy_Console::unshow()
{

}
void ListProxy_Console::showManip()
{
    std::cout<<"-r 返回上一级\t-x退出系统\t-f刷新\n";
    std::cout<<"-c <序号i> 进入序号为i的商品\n";
    std::cout<<"-l <序号i> 进入序号为i的子账单\n";
    std::cout<<"-d 在该账单下进行筛选\n";
}
