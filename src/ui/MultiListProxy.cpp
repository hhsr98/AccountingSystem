﻿#include "MultiListProxy.h"
#include<stdio.h>
#include<sstream>
using std::istringstream;
using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;
AbstractProxy::state MultiListProxy::manipulate(std::string order, AbstractProxy *&new_proxy)
{
    istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;//-r 返回上一级
        if(temp=="-x") return AbstractProxy::quit;//-x 退出系统
        if(temp=="-f") {show(); return AbstractProxy::done;}//刷新
        if(temp=="-n")
        {
            int i;
            is>>i;
			PayingEntry *entry=_list->get_vec_entry()[i];
			if(entry!=nullptr) {/*new_proxy=getPayingEntryProxy(entry);return AbstractProxy::new_proxy;*/}
            else return AbstractProxy::fail;
        }
		if(temp=="-s")//-s 解决方案
		{
            map<vector<string>,double> to_pay=_list->get_how_to_pay();
			if(to_pay.size()!=0)
			{
			map<vector<string>,double>::iterator iter;
			for(iter=to_pay.begin();iter!=to_pay.end();iter++) 
			{
				if(iter->second>0)
					cout<<iter->first[0]<<"支付给"<<iter->first[1]<<iter->second<<endl;
				if(iter->second<0)
					cout<<iter->first[1]<<"支付给"<<iter->first[0]<<iter->second<<endl;
			}
			return AbstractProxy::done;
			}
			else 
				return AbstractProxy::fail;
		}
		if(temp=="-p")//-p 查询需支付多少或者被支付多少
		{
			string name;
			is>>name;
			map<string,double> to_pay=_list->getperson_topaycopy();
			if(to_pay.size()!=0)
			{
			if(to_pay[name]<0)
				cout<<name<<"需要被支付"<<to_pay[name]<<endl;
			if(to_pay[name]>0)
				cout<<name<<"需要支付"<<to_pay[name]<<endl;
			else
				cout<<name<<"收支平衡"<<endl;
			return AbstractProxy::done;
			}
			else return AbstractProxy::fail;
		}
    }
    return AbstractProxy::fail;
}
