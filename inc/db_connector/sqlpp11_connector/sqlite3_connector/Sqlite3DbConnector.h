#ifndef __SQLITE3DBCONNECTOR_H
#define __SQLITE3DBCONNECTOR_H

#include "inc/db_connector/AbstractDbConnector.h"

#include <sqlpp11/custom_query.h>
#include <sqlpp11/sqlite3/sqlite3.h>
#include <sqlpp11/sqlpp11.h>
#include <sqlite3.h>
#include <vector>

#include "inc/db_connector/sqlpp11_connector/TabCommodity.h"

namespace db_connector
{
    namespace sqlpp11
    {
        namespace sqlite3
        {
            namespace sql = sqlpp::sqlite3;
            using sqlpp11_connector::TabCommodity;
            class DbConnector : public AbstractDbConnector
            {


                sql::connection_config config;
                sql::connection *db;
                std::map<int,Commodity*> CommodityMap;
                std::map<int,Shop*> ShopMap;
                std::map<int,Remark*> RemarkMap;

                const decltype(TabCommodity{}) tab_commodity=TabCommodity{};
                Shop* selectShop(int ShopID);
                Remark* selectRemark(int RemarkID);
                Commodity* selectCommodity(int CommodityID);
            public:
                DbConnector(char *db_path);

                std::vector<Commodity*>* selectCommodityAll();
                std::vector<Commodity*>* selectCommodity(Filter *criteria);
                void saveCommodity(Commodity *commodity);
                void deleteCommodity(Commodity *commodity);
            };
        }
    }
}
#endif // __SQLITE3DBCONNECTOR_H
