#ifndef EXCHANGE_TIME_HPP_
#define EXCHANGE_TIME_HPP_

#include <iostream>
#include "gtest/gtest.h"
#include "exchange_time.h"

using std::string;

class exchange_time_test: public ::testing::Test {
public:

  exchange_time_test() {

  }

  void SetUp() {

  }

  void TearDown() {

  }


};

TEST_F(exchange_time_test, convert_time) {
  exchange_time et;
  et.set("93500123");
  EXPECT_EQ(et.get_milliseconds(),123);
  EXPECT_EQ(et.get_seconds(),0);
  EXPECT_EQ(et.get_minutes(),35);
  EXPECT_EQ(et.get_hours(),9);
  et.set("143503123");
  EXPECT_EQ(et.get_milliseconds(),123);
  EXPECT_EQ(et.get_seconds(),3);
  EXPECT_EQ(et.get_minutes(),35);
  EXPECT_EQ(et.get_hours(),14);
}

TEST_F(exchange_time_test, seconds_from_midnight) {
  exchange_time et;
  et.set("00000001");
  EXPECT_EQ(et.seconds_from_midnight(),0.001);
  et.set("93500123");
  EXPECT_EQ(et.seconds_from_midnight(),34500.123);
}

TEST_F(exchange_time_test, comparison) {
  exchange_time et1, et2;
  et1.set("00000001");
  et2.set("93500123");
  EXPECT_TRUE(et2 > et1);
  EXPECT_TRUE(et1 < et2);
  EXPECT_TRUE(et2 == et2);
}


#endif
