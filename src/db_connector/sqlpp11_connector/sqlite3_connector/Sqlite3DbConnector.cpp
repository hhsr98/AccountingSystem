#include <db_connector/sqlpp11_connector/sqlite3_connector/Sqlite3DbConnector.h>
namespace db_connector
{
    namespace sqlpp11
    {
        namespace sqlite3
        {
            using std::vector;
            using std::map;
            DbConnector::DbConnector(char *db_path):config(),db(nullptr),CommodityMap(),ShopMap(),RemarkMap()
            {
                config.path_to_database=db_path;
                config.flags=SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE;
                config.debug=false;
                db=new sql::connection(config);
            }

            vector<Commodity*>* DbConnector::selectCommodityAll()
            {
                vector<Commodity*>* ivec=new vector<Commodity*>();
                Commodity* com;
                for(const auto& row: (*db)(select(all_of(tab_commodity)).from(tab_commodity).unconditionally()))
                {
                    int id=row.tCommodityID;

                    if(CommodityMap.find(id)==CommodityMap.end())
                    {
                        com=new Commodity(id);
                        ivec->push_back(com);
                        CommodityMap[id]=com;
                        com->setCommodityName(std::string(row.tCommodityName));
                        SingleMoney money(row.tUnitPrice,row.tCurrency);
                        com->setUnitPrice(money);
                        Unit unit((Unit::aUnit)((int)row.tUnit));
                        com->setUnit(unit);
                        Date d(row.tDate);
                        com->setDate(d);
                        //if(!row.tShopID==sqlpp::null)
                        {

                        }
                        com->setQuantity(row.tQuantity);
                        com->setDiscount(row.tDiscount);
                        com->set_unmodified();
                    }
                    else
                    {
                        ivec->push_back(CommodityMap[id]);
                    }

                }
                return ivec;
            }

            vector<Commodity*>* DbConnector::selectCommodity(Filter *criteria)
            {

            }

            void DbConnector::saveCommodity(Commodity *com)
            {
                if(com->is_modified())
                {
                    int id=com->CommodityID();
                    if(CommodityMap.find(id)!=CommodityMap.end())
                    {
                        (*db)(update(tab_commodity).set(tab_commodity.tCommodityName=com->CommodityName(),\
                                              tab_commodity.tUnitPrice=com->UnitPrice().Money(),\
                                              tab_commodity.tCurrency=com->UnitPrice().Currency(),\
                                              tab_commodity.tUnit=(int)(com->Unit().getUnit()),\
                                              tab_commodity.tQuantity=com->Quantity(),\
                                              tab_commodity.tDiscount=com->Discount(),\
                                              tab_commodity.tDate=com->Date().toHour()\
                                            ).where(tab_commodity.tCommodityID.in(id)));
                        com->set_unmodified();
                    }
                    else
                    {
                        com->setCommodityID();
                        (*db)(insert_into(tab_commodity).set(tab_commodity.tCommodityID=com->CommodityID(),\
                                                        tab_commodity.tCommodityName=com->CommodityName(),\
                                                        tab_commodity.tUnitPrice=com->UnitPrice().Money(),\
                                                        tab_commodity.tCurrency=com->UnitPrice().Currency(),\
                                                        tab_commodity.tUnit=(int)(com->Unit().getUnit()),\
                                                        tab_commodity.tQuantity=com->Quantity(),\
                                                        tab_commodity.tDiscount=com->Discount(),\
                                                        tab_commodity.tDate=com->Date().toHour()\
                                                        ));
                        com->set_unmodified();
                        CommodityMap[com->CommodityID()]=com;

                    }
                }
            }

            void DbConnector::deleteCommodity(Commodity *commodity)
            {

            }

            Commodity* DbConnector::selectCommodity(int CommodityID)
            {
                if(CommodityID<0) return nullptr;
                if(CommodityMap.find(CommodityID)!=CommodityMap.end())
                {
                    return CommodityMap[CommodityID];
                }
                else
                {
                    Commodity* com=nullptr;
                    for(const auto& row: (*db)(select(all_of(tab_commodity)).from(tab_commodity).where(tab_commodity.tCommodityID.in(CommodityID))))
                    {
                        com=new Commodity(CommodityID);
                        CommodityMap[CommodityID]=com;
                        com->setCommodityName(std::string(row.tCommodityName));
                        SingleMoney money(row.tUnitPrice,row.tCurrency);
                        com->setUnitPrice(money);
                        Unit unit((Unit::aUnit)((int)row.tUnit));
                        com->setUnit(unit);
                        Date d(row.tDate);
                        com->setDate(d);
                        //if(!row.tShopID==sqlpp::null)
                        {

                        }
                        com->setQuantity(row.tQuantity);
                        com->setDiscount(row.tDiscount);
                        com->set_unmodified();
                    }
                    return com;
                }


            }
            Shop* selectShop(int ShopID)
            {

            }
            Remark* selectRemark(int RemarkID)
            {

            }
        }
    }
}
