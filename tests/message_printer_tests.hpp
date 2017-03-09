#ifndef MESSAGE_PRINTER_TESTS_HPP_
#define MESSAGE_PRINTER_TESTS_HPP_

#include <iostream>
#include "gtest/gtest.h"
#include "message_printer.h"

using std::string;

class message_printer_tests: public ::testing::Test {
public:

  message_printer_tests() {

  }

  void SetUp() {

  }

  void TearDown() {

  }


};

TEST_F(message_printer_tests, test1) {
  message_printer mp;
  mp.on_message_char('g');
  mp.on_message_char('1');
  mp.on_message_char('0');
  char c;
  c = 15;
  mp.on_message_delimiter(c);
  EXPECT_EQ(1,1);
}


#endif
