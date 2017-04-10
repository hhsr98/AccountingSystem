//²âÊÔÎÄ¼þ£»
#include<iostream>
#include<string>
#include".../inc/SingleMoney.h"
using namespace std;

int main()
{
	SingleMoney a(234, "CNY"), c(123, "USD"), e(224.23, "JPY"), f(2222, "CAD");
	SingleMoney d = a + c;
	a.showSingleMoney();
	d.showSingleMoney();
	d = a + c + e + f;
	d.showSingleMoney();
	d = a + c - e - f;
	d.showSingleMoney();
	cout << (a < c) << endl;
	//system("pause");
	return 0;
}