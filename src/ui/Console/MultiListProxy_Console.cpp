#include "ui/Console/MultiListProxy_Console.h"
void MultiListProxy_Console::show()
{
	std::cout<<"MultiList Name:\t"<<_list->get_name()<<std::endl;
	auto ml=_list->get_vec_entry();
	int num=_list->get_num();
	for(int i=0;i<num;i++)
	{
		std::cout<<i<<'\t'<<ml[i]->get_Commodity()->CommodityName()<<std::endl;
	}

}
void MultiListProxy_Console::unshow()
{

}

void MultiListProxy_Console::showManip()
{

    std::cout<<"-r 返回上一级\t-x退出系统\t-f刷新\n";
    std::cout<<"-n <序号i> 进入序号为i的付款条目\n";
	std::cout<<"-s 显示付款分配方案\n";
	std::cout<<"-p <姓名A> 显示参与者A的支付结余情况\n";
}
