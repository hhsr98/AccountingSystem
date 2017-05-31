#ifndef __ABSTRACTDBCONNECTOR_H
#define __ABSTRACTDBCONNECTOR_H

#include "Filter.h"
#include "Commodity.h"
#include "Shop.h"
#include "list.h"

namespace db_connector
{

    class AbstractDbConnector
    {
    public:
        virtual std::vector<Commodity*>* selectCommodityAll()=0;
        virtual std::vector<Commodity*>* selectCommodity(Filter* criteria)=0;

        virtual void saveCommodity(Commodity *commodity)=0;

        virtual void saveCommodity(std::vector<Commodity*> &commodity_list)
        {
            for(auto i: commodity_list)
                saveCommodity(i);
        }

        virtual void deleteCommodity(Commodity *commodity)=0;

        virtual void deleteCommodity(std::vector<Commodity*> &commodity_list)
        {
            for(auto i: commodity_list)
                deleteCommodity(i);
        }

    };

}

#endif // __ABSTRACTDBCONNECTOR_H
