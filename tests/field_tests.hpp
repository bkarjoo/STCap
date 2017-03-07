#ifndef FIELD_TESTS_HPP_
#define FIELD_TESTS_HPP_

#include <iostream>
#include "gtest/gtest.h"
#include "field.h"
//#include "field_name.h"

using std::string;

class field_tests: public ::testing::Test {
public:

  field_tests() {

  }

  void SetUp() {

  }

  void TearDown() {

  }


};

TEST_F(field_tests, simpleField) {
  field f('f');
  f.add_char('4');
  f.on_field_complete();
  EXPECT_EQ(f.get_value(),"4");
}


TEST_F(field_tests, simpleField2) {
  field f('t');
  string s = "1209900";
  for (auto& a : s) f.add_char(a);
  f.on_field_complete();
  EXPECT_EQ(f.get_value(),"1209900");
}

TEST_F(field_tests, complexField1) {
  field f('g');
  string s = "77,102452956";
  for (auto& a : s) f.add_char(a);
  f.on_field_complete();
  EXPECT_EQ(f.get_value(),"102452956");
  EXPECT_EQ(f.get_char_code_value(),77);
}

TEST_F(field_tests, switchFunctions) {
  field f('f'); f.add_char('1');
  f.on_field_complete();
  EXPECT_EQ(field_name::f,f.get_field_name());
  field f2('f'); f2.add_char('1');f2.add_char('0');f2.add_char(',');f2.add_char('0');
  f2.on_field_complete();
  EXPECT_EQ(field_name::f10,f2.get_field_name());
  field g('g'); g.add_char('1');
  g.on_field_complete();
  EXPECT_EQ(field_name::g,g.get_field_name());
  field g2('g'); g2.add_char('1');g2.add_char('0');g2.add_char(',');g2.add_char('0');
  g2.on_field_complete();
  EXPECT_EQ(field_name::g10,g2.get_field_name());
}

TEST_F(field_tests, tostring) {
  field f('f'); f.add_char('2');f.add_char('7');f.add_char(',');f.add_char('1');
  f.add_char('1');f.add_char('5');f.add_char('8');f.add_char('3');f.add_char('5');
  f.set_exchange_code('k');
  f.on_field_complete();
  EXPECT_EQ(f.get_field_str(),"fk27,115835");
  EXPECT_EQ(f.get_field_name(),field_name::f27);
}

TEST_F(field_tests, tostring2) {
  field f('g'); f.add_char('7');f.add_char('7');f.add_char(',');f.add_char('1');
  f.add_char('1');f.add_char('5');f.add_char('8');f.add_char('3');f.add_char('5');
  f.add_char('1');f.add_char('9');f.add_char('3');
  f.on_field_complete();
  EXPECT_EQ(f.get_field_str(),"g77,115835193");
}



TEST_F(field_tests, kp1) {
  field f('k');
  f.set_exchange_code('p');
  f.add_char('1');
  f.on_field_complete();
  EXPECT_EQ(f.get_field_str(),"kp1");
}

#endif
