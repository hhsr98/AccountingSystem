#include "ui/Console/AddCommodityProxy_Console.h"
#include "ui/Console/CommodityProxy_Console.h"
CommodityProxy* AddCommodityProxy_Console::getCommodityProxy(Commodity* commo)
{
    return new CommodityProxy_Console(commo);
}
void AddCommodityProxy_Console::show()
{
    if(faList!=nullptr) std::cout<<"当前位置:"<<faList->ListName()<<std::endl;
    std::cout<<(*com);
    std::cout<<"-r 返回上一级\t-x退出系统\t-f刷新\n";
    std::cout<<"-s 保存结果并退出编辑\n";
    std::cout<<"-e <指示符> <内容> 编辑商品信息\n";
    std::cout<<"\t<指示符> -n 名称\t-q 数量\t-m 单价\t-o折扣\t-d日期\n";
}
void AddCommodityProxy_Console::showManip()
{

}
void AddCommodityProxy_Console::unshow()
{


}
