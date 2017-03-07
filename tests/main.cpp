#include "gtest/gtest.h"
//#include "cap_file_test.hpp"
#include "field_tests.hpp"
#include "exchange_time_test.hpp"
#include "message_tests.hpp"
//#include "quote_tests.hpp"
#include "strategy_tests.hpp"

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
