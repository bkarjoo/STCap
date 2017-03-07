#ifndef MESSAGE_TESTS_HPP_
#define MESSAGE_TESTS_HPP_

#include <iostream>
#include "gtest/gtest.h"
#include "message.h"

using std::string;

class message_tests: public ::testing::Test {
public:

  message_tests() {

  }

  void SetUp() {

  }

  void TearDown() {

  }


};

TEST_F(message_tests, simple) {
  string msg_str = "t~f79,20g54,2009f4f78,1252500f77,50f32,44433g77,173713944g97,2207527v-48024589f86,0f16,173713f15,20170131";
  const char t = 15;
  message m(t);
  string str = "";
  str += t;
  string msg_str2 = "t~f79,20g54,2009f4f78,1252500f77,50g77,173713944f86,0";
  str += msg_str2;
  for (auto& a : msg_str) m.add_char(a);
  m.on_message_complete();
  EXPECT_EQ(str,m.to_string());

  msg_str = "~g77,173713263g97,21711196kp1f36,0f16,173713f15,20170131f27,173713f26,20170131";
  msg_str2 = "~g77,173713263kp1f36,0";
  message m2(t);
  str = ""; str += t; str += msg_str2;

  for (auto& a : msg_str) m2.add_char(a);
  m2.on_message_complete();
  EXPECT_EQ(str,m2.to_string());
}

TEST_F(message_tests, tostring2) {
  string msg_str = "~g77,173713263g97,21711196kp1";
  const char t = 15;
  message m(t);
  string str = "";
  str += t;
  string msg_str2 = "~g77,173713263kp1";
  str += msg_str2;
  for (auto& a : msg_str) m.add_char(a);
  m.on_message_complete();
  EXPECT_EQ(str,m.to_string());

}

#endif
