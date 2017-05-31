#include "../inc/date.h"
#include "../inc/Unit.h"
#include "../inc/Shop.h"
<<<<<<< HEAD
//#include "../inc/Analize.h"
#include"../inc/User.h"
#include"../inc/Display.h"
=======
#include "../inc/Analize.h"
#include "../inc/Shop.h"
>>>>>>> 40f3313747fb26b1e4c5ed73c0e6b3cbd12cc0af
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <time.h>
#include <sstream>
using namespace std;
AnalizeByDate* a;
int main()
{
	ExchangeRate exchange_rate;
	string opr;
	User* user = new User;
	cin >> opr;
	while (opr != "stop")
	{
		if (opr == "add_commodity")
			user->addCommodity();
		else if (opr == "add_list")
			user->addList();
		else if (opr == "add_paying_entry")
		{
			int i;
			cin >> i;
			user->addPayingEntry(i);
		}
		else if (opr == "add_multilist")
			user->addMultiList();
		else if (opr == "show_commodity")
		{
			int i;
			cin >> i;
			user->show("commodity", i);
		}
		else if (opr == "show_list")
		{
			int i;
			cin >> i;
			user->show("list", i);
		}
		cin >> opr;
	}

	system("pause");
	return 0;
}
