#include "ui/Console/ClassifyProxy_Console.h"

void ClassifyProxy_Console::showHierarchy(int level,List *l)
{
    for(int i=1;i<=level;i++) std::cout<<"  ";
    std::cout<<list_num[l]<<"---"<<l->ListName()<<std::endl;
    std::set<List*> sub_l=l->get_Sublist();
    for(auto u: sub_l)
        showHierarchy(level+1,u);
}
void ClassifyProxy_Console::show()
{
    std::cout<<" 待分类商品:"<<std::endl;
    std::cout<<(*com);
    std::cout<<" 分类目录:"<<std::endl;
    showHierarchy(0,root);
}
void ClassifyProxy_Console::unshow()
{

}
void ClassifyProxy_Console::showManip()
{
    std::cout<<"-r 返回上一级\t-x退出系统\t-f刷新\n";
    std::cout<<"-a <序号i> 将商品加入序号为i的类\n";
    std::cout<<"-l <序号i> <名称> 在分类i下新增子分类\n";
}
