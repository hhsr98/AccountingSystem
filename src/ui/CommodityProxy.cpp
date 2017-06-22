/*******************************************************
���ƣ�CommodityProxy.cpp
���ߣ�Ǯ��
����޸ģ�2017-06-21
������������Ʒ��Ϣ������Դ�ļ���
*******************************************************/
#include "ui/CommodityProxy.h"
#include<stdio.h>
#include<sstream>
using std::istringstream;
/*
*order��ʽ��
*   -r  ����
*   -x  �˳�����ϵͳ
*   -f  ˢ����ʾ����
*   -c  ������Ʒ����
*   -e  �޸���Ʒ����
*       -n <����>
*       -q <����>
*       -m <���>
*       -o <�ۿ�>
*       -d <���ڣ�yyyymmddhh>
*/
AbstractProxy::state CommodityProxy::manipulate(std::string order, AbstractProxy *&new_proxy)
{
    istringstream is(order);
    std::string temp;
    if(is>>temp)
    {
        if(temp=="-r") return AbstractProxy::go_back;//-r ������һ��
        if(temp=="-x") return AbstractProxy::quit;//-x �˳�ϵͳ
        if(temp=="-f") {show(); return AbstractProxy::done;}
        if(temp=="-c") {new_proxy=getClassifyProxy(AbstractProxy::RootClassifyList);return AbstractProxy::new_proxy;}
        if(temp=="-e") //�޸���Ʒ��Ϣ
        {
            std::string temp1,temp2;
            if(is>>temp1>>temp2)
            {
                if(temp1=="-n")
                {
                    com->setCommodityName(temp2);
                    return AbstractProxy::done;
                }
                if(temp1=="-q")
				{
					double a;
					std::stringstream stream;
					//��stringת����double
					stream<<temp2;
					stream>>a;
					com->setQuantity(a);
					stream.clear();
					return AbstractProxy::done;
				}
				if(temp1=="-m")
				{
					std::string a,b;
					double a1;
					a=temp2.substr(0,temp2.size()-3);//�����ֿ�����a��
					std::stringstream stream;
					stream<<a;
					stream>>a1;//���ַ���ת��Ϊdouble����
					b=temp2.substr(temp2.size()-3,3);
					SingleMoney money(a1,b);//���쵥���ֽ������²���
					com->setUnitPrice(money);//����
					return AbstractProxy::done;
				}
				if(temp1=="-o")
				{
					double temp;
					std::stringstream stream;
					//��stringת����double
					stream<<temp2;
					stream>>temp;
					com->setDiscount(temp);
					stream.clear();
					return AbstractProxy::done;
				}
				if(temp1=="-d")//�����ʽΪ������ʱ������2017070718 Ϊ2017��7��7��18��
				{
					double y,m,d,h;
					std::string y1,m1,d1,h1;
					y1=temp2.substr(0,4);
					m1=temp2.substr(4,2);
					d1=temp2.substr(6,2);
					h1=temp2.substr(8,2);
					std::stringstream stream;
					//��stringת����double
					stream<<y1;
					stream>>y;
					stream.clear();
					stream<<m1;
					stream>>m;
					stream.clear();
					stream<<d1;
					stream>>d;
					stream.clear();
					stream<<h1;
					stream>>h;
					stream.clear();
					Date date(y,m,d,h);
					com->setDate(date);
					AbstractProxy::AutoClassiy(com,AbstractProxy::RootDateList);
					return AbstractProxy::done;
				}

            }
            return AbstractProxy::fail;
        }
        return AbstractProxy::fail;
    }
    return AbstractProxy::fail;


}
