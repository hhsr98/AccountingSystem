/*
 * Copyright (c) 2013 - 2016, Roland Bock
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//#include "TabSample.h"
//#include <sqlpp11/custom_query.h>
//#include <sqlpp11/sqlite3/sqlite3.h>
//#include <sqlpp11/sqlpp11.h>

#include <cassert>
#include <iostream>
//#include <sqlite3.h>
#include <string>
#include <vector>

#include<db_connector/sqlpp11_connector/sqlite3_connector/Sqlite3DbConnector.h>

#include <Commodity.h>

#include "ui/ProxyManager.h"
#include "ui/Console/CommodityProxy_Console.h"
#include "ui/Console/ListProxy_Console.h"
#include "ui/Console/FilterProxy_Console.h"
SQLPP_ALIAS_PROVIDER(left);
SQLPP_ALIAS_PROVIDER(pragma);
SQLPP_ALIAS_PROVIDER(sub);

namespace sql = sqlpp::sqlite3;
int main()
{
    system("CHCP 65001");
    ExchangeRate ee;
    db_connector::AbstractDbConnector *a=new db_connector::sqlpp11::sqlite3::DbConnector("DataBase.db");
    auto pp=a->selectCommodityAll();
    pp=a->selectCommodityAll();
    Date ndate(2017,8,9,23);
    for(auto ss:(*pp))
    {
        std::cout<<(*ss)<<std::endl;
        //ss->setDate(ndate);
    }
    Filter *fil1=new AllFilter();
    List aaa2(fil1);
    for(auto ss:(*pp))
    {
        aaa2.addCommodity(ss);
    }

//以下为用户交互部分
    std::cout<<std::endl<<std::endl;
    Commodity *comm=pp->back();
    ProxyManager manager;
    AbstractProxy *LLL=new FilterProxy_Console(&aaa2);
    manager.addProxy(LLL);
    std::string temp;
    ProxyManager::state re;
    while(1)
    {
        getline(std::cin,temp);
        re=manager.process(temp);
        if(re==ProxyManager::quit) break;
        if(re==ProxyManager::success) std::cout<<"successfully done\n";
        else if(re==ProxyManager::fail) std::cout<<"fail\n";
    }
    a->saveCommodity(comm);
  /*sql::connection db(config);
  db.execute(R"(CREATE TABLE tab_sample (
		alpha INTEGER PRIMARY KEY,
			beta varchar(255) DEFAULT NULL,
			gamma bool DEFAULT NULL
			))");
  db.execute(R"(CREATE TABLE tab_foo (
		omega bigint(20) DEFAULT NULL
			))");*/
/*
  const auto tab = TabCommodity{};

  // clear the table
  //db(remove_from(tab).unconditionally());

  // explicit all_of(tab)
  for (const auto& row : db(select(all_of(tab)).from(tab).unconditionally()))
  {
      std::cerr<<row.CommodityID<<' '<<row.CommodityName<<' '<<row.UnitPrice<<' '\
      <<row.Currency<<' '<<row.Quantity<<' '<<row.Unit<<std::endl;
    //std::cerr << "row.alpha: " << row.alpha << ", row.beta: " << row.beta << ", row.gamma: " << row.gamma << std::endl;
  };
  std::cerr<<std::endl;
  std::cerr << __FILE__ << ": " << __LINE__ << std::endl;
  // selecting a table implicitly expands to all_of(tab)
  for (const auto& row : db(select(multi_column(tab.CommodityName, tab.CommodityID, tab.UnitPrice).as(left), multi_column(all_of(tab)).as(tab))
              .from(tab)
              .unconditionally()) )
  {
      std::cerr<<row.left.CommodityID<<' '<<row.left.CommodityName<<' '<<row.left.UnitPrice<<' '<<row.TabCommodity.Currency<<std::endl;
   // std::cerr << "row.alpha: " << row.alpha << ", row.beta: " << row.beta << ", row.gamma: " << row.gamma << std::endl;
  };
/*
  db(update(tab).set(tab.Currency="CNY").where(tab.CommodityID.in(1)));
  db(insert_into(tab).set(tab.CommodityName="haha",tab.UnitPrice=38,tab.Currency="USD",tab.Quantity=89,tab.Unit=0x4,tab.RemarkID=0x8,tab.Discount=0.8,tab.CommodityID=sqlpp::default_value));
  for (const auto& row : db(select(all_of(tab)).from(tab).unconditionally()))
  {
      std::cerr<<row.CommodityID<<' '<<row.CommodityName<<' '<<row.UnitPrice<<' '\
      <<row.Currency<<' '<<row.Quantity<<' '<<row.Unit<<std::endl;
    //std::cerr << "row.alpha: " << row.alpha << ", row.beta: " << row.beta << ", row.gamma: " << row.gamma << std::endl;
  };
  system("pause");
  // selecting two multicolumns
 /* for (const auto& row :
       db(select(multi_column(tab.alpha, tab.beta, tab.gamma).as(left), multi_column(all_of(tab)).as(tab))
              .from(tab)
              .unconditionally()))
  {
    std::cerr << "row.left.alpha: " << row.left.alpha << ", row.left.beta: " << row.left.beta
              << ", row.left.gamma: " << row.left.gamma << std::endl;
    std::cerr << "row.tabSample.alpha: " << row.tabSample.alpha << ", row.tabSample.beta: " << row.tabSample.beta
              << ", row.tabSample.gamma: " << row.tabSample.gamma << std::endl;
  };*/
/*
  // insert
  //std::cerr << "no of required columns: " << TabSample::_required_insert_columns::size::value << std::endl;
  db(insert_into(tab).default_values());
  db(insert_into(tab).set(tab.gamma = true));
  auto di = dynamic_insert_into(db, tab).dynamic_set(tab.gamma = true);
  di.insert_list.add(tab.beta = "");
  db(di);

  // update
  db(update(tab).set(tab.gamma = false).where(tab.alpha.in(1)));
  db(update(tab).set(tab.gamma = false).where(tab.alpha.in(sqlpp::value_list(std::vector<int>{1, 2, 3, 4}))));

  // remove
  db(remove_from(tab).where(tab.alpha == tab.alpha + 3));

  auto result = db(select(all_of(tab)).from(tab).unconditionally());
  std::cerr << "Accessing a field directly from the result (using the current row): " << result.begin()->alpha
            << std::endl;
  std::cerr << "Can do that again, no problem: " << result.begin()->alpha << std::endl;

  auto tx = start_transaction(db);
  TabFoo foo;
  for (const auto& row : db(select(all_of(tab), select(max(foo.omega)).from(foo).where(foo.omega > tab.alpha))
                                .from(tab)
                                .unconditionally()))
  {
    int x = row.alpha;
    int a = row.max;
    std::cout << x << ", " << a << std::endl;
  }
  tx.commit();

  for (const auto& row : db(select(tab.alpha).from(tab.join(foo).on(tab.alpha == foo.omega)).unconditionally()))
  {
    std::cerr << row.alpha << std::endl;
  }

  for (const auto& row :
       db(select(tab.alpha).from(tab.left_outer_join(foo).on(tab.alpha == foo.omega)).unconditionally()))
  {
    std::cerr << row.alpha << std::endl;
  }

  auto ps = db.prepare(select(all_of(tab))
                           .from(tab)
                           .where(tab.alpha != parameter(tab.alpha) and tab.beta != parameter(tab.beta) and
                                  tab.gamma != parameter(tab.gamma)));
  ps.params.alpha = 7;
  ps.params.beta = "wurzelbrunft";
  ps.params.gamma = true;
  for (const auto& row : db(ps))
  {
    std::cerr << "bound result: alpha: " << row.alpha << std::endl;
    std::cerr << "bound result: beta: " << row.beta << std::endl;
    std::cerr << "bound result: gamma: " << row.gamma << std::endl;
  }

  std::cerr << "--------" << std::endl;
  ps.params.alpha = sqlpp::eval<sqlpp::integer>(db, "last_insert_rowid()");
  ps.params.gamma = "false";
  for (const auto& row : db(ps))
  {
    std::cerr << "bound result: alpha: " << row.alpha << std::endl;
    std::cerr << "bound result: beta: " << row.beta << std::endl;
    std::cerr << "bound result: gamma: " << row.gamma << std::endl;
  }

  std::cerr << "--------" << std::endl;
  ps.params.beta = "kaesekuchen";
  for (const auto& row : db(ps))
  {
    std::cerr << "bound result: alpha: " << row.alpha << std::endl;
    std::cerr << "bound result: beta: " << row.beta << std::endl;
    std::cerr << "bound result: gamma: " << row.gamma << std::endl;
  }

  auto pi = db.prepare(insert_into(tab).set(tab.beta = parameter(tab.beta), tab.gamma = true));
  pi.params.beta = "prepared cake";
  std::cerr << "Inserted: " << db(pi) << std::endl;

  auto pu = db.prepare(update(tab).set(tab.gamma = parameter(tab.gamma)).where(tab.beta == "prepared cake"));
  pu.params.gamma = false;
  std::cerr << "Updated: " << db(pu) << std::endl;

  auto pr = db.prepare(remove_from(tab).where(tab.beta != parameter(tab.beta)));
  pr.params.beta = "prepared cake";
  std::cerr << "Deleted lines: " << db(pr) << std::endl;

  // Check that a prepared select is default-constructible
  {
    auto s = select(all_of(tab))
                 .from(tab)
                 .where((tab.beta.like(parameter(tab.beta)) and tab.alpha == parameter(tab.alpha)) or
                        tab.gamma != parameter(tab.gamma));
    using P = decltype(db.prepare(s));
    P p;  // You must not use this one yet!
    p = db.prepare(s);
  }

  auto i = db(sqlpp::sqlite3::insert_or_replace_into(tab).set(tab.beta = "test", tab.gamma = true));
  std::cerr << i << std::endl;

  i = db(sqlpp::sqlite3::insert_or_ignore_into(tab).set(tab.beta = "test", tab.gamma = true));
  std::cerr << i << std::endl;

  assert(db(select(count(tab.alpha)).from(tab).unconditionally()).begin()->count);
  assert(
      db(select(all_of(tab)).from(tab).where(tab.alpha.not_in(select(tab.alpha).from(tab).unconditionally()))).empty());

  auto x = custom_query(sqlpp::verbatim("PRAGMA user_version = "), 1);
  db(x);
  int pragmaValue =
      db(custom_query(sqlpp::verbatim("PRAGMA user_version")).with_result_type_of(select(sqlpp::value(1).as(pragma))))
          .front()
          .pragma;
  std::cerr << pragmaValue << std::endl;

  // Testing sub select tables and unconditional joins
  const auto subQuery = select(tab.alpha).from(tab).unconditionally().as(sub);
  for (const auto& row : db(select(subQuery.alpha).from(subQuery).unconditionally()))
  {
    std::cerr << row.alpha;
  }

  for (const auto& row : db(select(subQuery.alpha).from(tab.inner_join(subQuery).unconditionally()).unconditionally()))
  {
    std::cerr << row.alpha;
  }*/

  return 0;
}
