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
    std::cout<<"-r ������һ��\t-x�˳�ϵͳ\t-fˢ��\n";
    std::cout<<"-n <���i> �������Ϊi�ĸ�����Ŀ\n";
	std::cout<<"-s ��ʾ������䷽��\n";
	std::cout<<"-p <����A> ��ʾ������A��֧���������\n";
}