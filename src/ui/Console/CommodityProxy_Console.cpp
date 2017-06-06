#include "ui/Console/CommodityProxy_Console.h"
#include "ui/Console/ClassifyProxy_Console.h"
ClassifyProxy* CommodityProxy_Console::getClassifyProxy(List *root_list)
{
    return new ClassifyProxy_Console(root_list,com);
}
void CommodityProxy_Console::show()
{
    std::cout<<(*com);
}
void CommodityProxy_Console::unshow()
{

}
void CommodityProxy_Console::showManip()
{
    std::cout<<"-r 返回上一级\t-x退出系统\t-f刷新\n";
    std::cout<<"-e <指示符> <内容> 修改商品信息\n";
    std::cout<<"\t<指示符> -n 名称\t-q 数量\t-m 单价\t-o折扣\t-d日期\n";


}
