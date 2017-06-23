#include "ListProxy_Console.h"
void ListProxy_Console::show()
{
    std::cout<<"List Name:\t"<<_list->ListName()<<std::endl;
    auto ll=_list->get_CommodityList();
    int i=0;
    for(auto com:ll)
    {
        std::cout<<i<<'\t'<<com->CommodityName()<<std::endl;
        i++;
    }

}
void ListProxy_Console::unshow()
{

}
void ListProxy_Console::showManip()
{
    std::cout<<"-r 返回上一级\t-x退出系统\t-f刷新\n";
    std::cout<<"-n <序号i> 进入序号为i的商品\n";
}
