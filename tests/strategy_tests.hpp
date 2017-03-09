#ifndef STRATEGY_TESTS_HPP_
#define STRATEGY_TESTS_HPP_

#include "gtest/gtest.h"
#include "strategy.h"
#include "exchange_time.h"
#include "cap_file.h"
#include "quote.h"
#include <memory>



TEST(strategy_tests, exchange_time)
{
  std::shared_ptr<quote> qp(new quote());
  strategy s(qp);
  s.on_trade("93015123","1235000");
  exchange_time et;
  et.set_time("93015123");
  EXPECT_EQ(s.get_time(),et.get_seconds_from_midnight());
}

TEST(strategy_tests, precision)
{
  std::shared_ptr<quote> qp(new quote());
  strategy s(qp);
  s.on_precision("","1");
  s.on_trade("93015123","1235000");
  EXPECT_EQ(s.get_trade(),123500.00);
  s.on_precision("","2");
  s.on_trade("93015123","1235000");
  EXPECT_EQ(s.get_trade(),12350.00);
  s.on_precision("","3");
  s.on_trade("93015123","1235000");
  EXPECT_EQ(s.get_trade(),1235.00);
  s.on_precision("","4");
  s.on_trade("93015123","1235000");
  EXPECT_EQ(s.get_trade(),123.500);
  s.on_precision("","5");
  s.on_trade("93015123","1235000");
  EXPECT_EQ(s.get_trade(),12.3500);
  s.on_precision("","6");
  s.on_trade("93015123","1235000");
  EXPECT_EQ(s.get_trade(),1.23500);
  s.on_precision("","7");
  s.on_trade("93015123","1235000");
  EXPECT_EQ(s.get_trade(),0.123500);
  s.on_precision("","8");
  s.on_trade("93015123","1235000");
  EXPECT_EQ(s.get_trade(),0.0123500);
  s.on_precision("","9");
  s.on_trade("93015123","1235000");
  EXPECT_EQ(s.get_trade(),0.00123500);
}

TEST(strategy_tests, bidAndAsk)
{
  std::shared_ptr<quote> qp(new quote());
  strategy s(qp);
  s.on_precision("","4");
  s.on_bid("93015123","1235000");
  EXPECT_EQ(s.get_bid(),123.500);
  s.on_ask("93015123","1235000");
  EXPECT_EQ(s.get_ask(),123.500);
}

TEST(strategy_tests, size)
{
  std::shared_ptr<quote> qp(new quote());
  strategy s(qp);
  s.on_bid_size("93015123","1");
  EXPECT_EQ(s.get_bid_size(),100);
  s.on_ask_size("93015123","2");
  EXPECT_EQ(s.get_ask_size(),200);
  s.on_ask_size("93015123","10");
  EXPECT_EQ(s.get_ask_size(),1000);
}

TEST(strategy_tests, timetest) {
  cap_file cf;
  cf.set_full_path("..\\AAPL.CAP");
  std::shared_ptr<quote> qp(new quote());
  cf.set_client(qp);
  strategy s(qp);
  cf.run();
  EXPECT_EQ("1","1");

}

TEST(strategy_tests, testconvertheadertotimestamp)
{
  std::shared_ptr<quote> qp(new quote());
  strategy s(qp);
  ;
  EXPECT_EQ("",s.covert_header_to_timestamp(""));
  EXPECT_EQ("102241000",s.covert_header_to_timestamp("10:22:41"));
  EXPECT_EQ("92241000",s.covert_header_to_timestamp("09:22:41"));
}
#endif
