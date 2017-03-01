#ifndef CAP_FILE_TEST_HPP_
#define CAP_FILE_TEST_HPP_

#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "cap_file.h"
#include "cap_char_receiver.h"


class CapFileTests: public ::testing::Test {

public:
  cap_file cf;
  cap_char_receiver ccr;
  std::shared_ptr<cap_file> cp;
  std::shared_ptr<cap_char_receiver> ccrp;

  CapFileTests() {
     // initialization code here
     cf.set_full_path("..\\AAPL.CAP");
     ccrp = std::make_shared<cap_char_receiver>(ccr);
     cf.set_client(ccrp);
  }

  void SetUp() {
     // code here will execute just before the test ensues
     cp = std::make_shared<cap_file>(cf);
  }

  void TearDown() {
     // code here will be called just after the test completes
     // ok to through exceptions from here if need be
  }

  ~CapFileTests()  {

  }


  // put in any custom data members that you need
  bool private_is_header_mode(read_mode_type rm) {
    if (rm == read_mode_type::HEADER) return true; else return false;
  }

};

TEST_F(CapFileTests, CapFileInitializationTest) {
  EXPECT_EQ(cp->get_full_path(),"..\\AAPL.CAP");
}

TEST_F(CapFileTests, ReadTest) {
  cp->run(); 
  EXPECT_EQ(ccrp->get_char_count(),65151419);
  EXPECT_EQ(ccrp->get_packet_count(),29635);
  EXPECT_EQ(ccrp->get_message_count(),644533);
}


TEST_F(CapFileTests, ModeEnumTest) {
  read_mode_type rmt = read_mode_type::HEADER;
  bool b = private_is_header_mode(rmt);
  EXPECT_TRUE(b);
}


#endif // CAP_FILE_TEST_HPP_
