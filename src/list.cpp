/*****************************************************

 名称：list.cpp

 作者：钱姿

 内容描述：实现账单

 版权：这是我们自行完成的程序，没有使用其余来源代码

 *****************************************************/
#include"../inc/list.h"
using namespace std;

//求和
SingleMoney List::Sum() const
{
	int i;
	SingleMoney _sum;
	for (const auto a:vec_commodity)
		_sum+=a->TotalPrice();
	for(const auto a:vec_sublist)
		_sum+=a->Sum();
    return _sum;
}

set<Commodity*> List::get_CommodityList ()const	{
	return vec_commodity;
}

set<List*>List::get_Sublist()const {
	return vec_sublist;
}

//删除商品
void List::deleteCommodity(Commodity *com)
{
    if(vec_commodity.find(com)!=vec_commodity.end())
        vec_commodity.erase(com);
}

//设置筛选
void List::setFilter(const Filter *f)
{
    criteria=f;
    std::vector<Commodity*> del;
    for(const auto r:vec_commodity)
    {
        if(!isValidCommodity(r))
            del.push_back(r);
    }
    for(const auto r:del)
    {
        vec_commodity.erase(r);
    }
}

//获得商品信息
Commodity* List::getCommodity(int i)
{
    int k=0;
    for(auto r:vec_commodity)
    {
        if(k==i) return r;
        k++;
    }
    return nullptr;
}

