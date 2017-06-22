#include "../inc/date.h"
#include "../inc/Unit.h"
#include "../inc/Shop.h"

//#include "../inc/Analize.h"
#include"../inc/Display.h"

#include "../inc/Analize.h"
#include "../inc/Shop.h"

//#include "../inc/Analize.h"
#include"../inc/Display.h"

#include "../inc/Analize.h"
#include "../inc/Shop.h"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <time.h>
#include <sstream>
#include "db_connector/sqlpp11_connector/sqlite3_connector/Sqlite3DbConnector.h"
using namespace std;
AnalizeByDate* a;
#ifdef DEBUG1
int main()
{
    db_connector::AbstractDbConnector *db=new db_connector::sqlpp11::sqlite3::DbConnector("DataBase.db");
    vector<Commodity*>* com_list=db->selectCommodityAll();
	ExchangeRate exchange_rate;
	string opr;
	User* user = new User;
	user->addCommVector(com_list);
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
	db->saveCommodity(*com_list);
	system("pause");
	return 0;
}
#endif
