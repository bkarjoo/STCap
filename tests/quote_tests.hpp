#ifndef QUOTE_TESTS_HPP_
#define QUOTE_TESTS_HPP_

#include <iostream>
#include <memory>
#include "gtest/gtest.h"
#include "cap_file.h"
#include "cap_char_receiver.h"
#include "quote.h"

class quote_tests: public ::testing::Test {

public:

  quote_tests() {
     // initialization code here

  }

  void SetUp() {
     // code here will execute just before the test ensues
  }

  void TearDown() {
     // code here will be called just after the test completes
     // ok to through exceptions from here if need be
  }

  ~quote_tests()  {

  }

};


TEST_F(quote_tests, test1) {
  cap_file cf;
  cf.set_full_path("..\\AAPL.CAP");
  shared_ptr<quote> qp(new quote());
  cf.set_client(qp);
  cf.run();
  EXPECT_EQ("1","1");

}

TEST_F(quote_tests, precision)
{
  string message = "t~f4t1211650i-125f79,6g54,60000";
  quote q;
  q.on_message_delimiter(message[0]);
  for (int i = 1; i < 5; ++i) q.on_message_char(message[i]);
  EXPECT_EQ(q.field_code, 'f');
  EXPECT_EQ(q.field_code_value, "");
  EXPECT_EQ(q.field_value, "4");
}

TEST_F(quote_tests, test2) {
  string packet = "11:58:36 t~g77,115835199f97,9786509kt8f16,115835";
  packet += "f15,20170131f27,115835f26,20170131t~f79,9g54,60009f4f78,1211650";
  packet += "f77,75f12,15717145f32,15270g77,115835537g97,822778v-15888603";
  packet += "f86,1f16,115835f15,20170131t~f4t1211650i-125f79,6g54,60000f12,15717270";
  packet += "f28,1210564f32,15271g77,115835022g97,822779v-15888728n-4650f86,1";
  packet += "f16,115835f15,20170131f24,115835f23,20170131f10,-0.38d~f79,9g54,9";
  packet += "f4f78,1211675f77,60f12,15717330f32,2221681g77,115835296g97,822788";
  packet += "v-15888788f86,0f16,115835f15,20170131~g77,115835193g97,9786736kt9";
  packet += "f16,115835f15,20170131f27,115835f26,20170131~g77,115835606g97,9786742";
  packet += "kt8f16,115835f15,20170131f27,115835f26,20170131~g77,115835488g97,9786750";
  packet += "kt9f16,115835f15,20170131f27,115835f26,20170131~g77,115835187g97,9786752";
  packet += "kt8f16,115835f15,20170131f27,115835f26,20170131~g77,115835645g97,9786765";
  packet += "jp6f16,115835f15,20170131f27,115835f26,20170131~g77,115835733g97,9786766";
  packet += "jp5f16,115835f15,20170131f27,115835f26,20170131~g77,115835525g97,9786767kt9f16,115835f15,20170131f27,115835f26,20170131~g77,115835457g97,9786768kt10f16,115835f15,20170131f27,115835f26,20170131~g77,115835644g97,9786770kt9f16,115835f15,20170131f27,115835f26,20170131~g77,115835150g97,9786772kt10f16,115835f15,20170131f27,115835f26,20170131b~f4t1211600i1f79,6g54,60000f12,15717430f28,1210564f32,4409g77,115835847g97,822790v-15888888n-4700f86,1f16,115835f15,20170131f24,115835f23,20170131f10,-0.39j~f4t1211600i1f79,6g54,60000f12,15717530f28,1210564f32,3583g77,115835247g97,822791v-15888988n-4700f86,1f16,115835f15,20170131f24,115835f23,20170131f10,-0.39j~f79,9g54,60009f4f78,1211600f77,90f12,15717620f32,3584g77,115835198g97,822792v-15889078f86,1f16,115835f15,20170131k~f79,9g54,60009f4f78,1211600f77,10f12,15717630f32,8773g77,115835076g97,822793v-15889088f86,1f16,115835f15,20170131";

  quote q;
  q.on_packet_delimiter(packet[0]);
  // give it packet header
  for (int i = 1; i < 10; ++i) q.on_header_char(packet[i]);
  EXPECT_EQ(q.packet_header_str,"11:58:36 ");
  // give it message delimiter
  q.on_message_delimiter(packet[10]);
  EXPECT_EQ(q.packet_header_str,"11:58:36 ");
  EXPECT_EQ(q.message_delimiter,packet[10]);
  // give it message header
  q.on_message_char(packet[11]); q.on_message_char(packet[12]);
  EXPECT_EQ(q.packet_header_str,"11:58:36 ");
  // and the first field so that messaged header turns complete
  q.on_message_char(packet[13]);
  EXPECT_TRUE(q.message_header_complete);
  EXPECT_EQ(q.first_prefix, 't');
  EXPECT_EQ(q.symbol, "~");
  EXPECT_EQ(q.field_code, 'g');
  for (int i = 14; i <= 25; ++i) q.on_message_char(packet[i]);
  EXPECT_EQ(q.field_code_value, "77");
  EXPECT_EQ(q.field_value, "115835199");
  EXPECT_EQ(q.packet_header_str,"11:58:36 ");
  q.on_message_char(packet[26]);
  EXPECT_EQ(q.field_code, 'f');
  for (int i = 27; i <= 36; i++) q.on_message_char(packet[i]);
  EXPECT_EQ(q.field_code_value, "97");
  EXPECT_EQ(q.field_value, "9786509");
  q.on_message_char(packet[37]);
  EXPECT_EQ(q.field_code, 'k');
  EXPECT_EQ(q.field_value, "");
  q.on_message_char(packet[38]);
  EXPECT_EQ(q.packet_header_str,"11:58:36 ");
  EXPECT_EQ(q.field_code, 'k');
  q.on_message_char(packet[39]);
  EXPECT_EQ(q.field_value, "8");
  for (int i = 40; i <= 49; ++i) q.on_message_char(packet[i]);
  EXPECT_EQ(q.field_code, 'f');
  EXPECT_EQ(q.field_code_value, "16");
  EXPECT_EQ(q.field_value, "115835");
  EXPECT_EQ(q.packet_header_str,"11:58:36 ");
  // now run to the end of the message and see if the last field is good
  // 84 is new message
  for (int i = 50; i <= 84; ++i) q.on_message_char(packet[i]);
  EXPECT_EQ(q.message_delimiter, 15);

}

TEST_F(quote_tests, packet_delimiter_test) {
  // 1. last message of the packet is caught with all its field_exists
  // 2. the header of the new packet is caught
  // 3. the first message of the packet is caught
  // 4. the second message of the packet is caught
  // -- feed it up to the header of packet two
  quote q;
  string packet1 = "11:58:36 ~g77,115835199g97,9786509kt8f16,115835f15,20170131";
  packet1 += "f27,115835f26,20170131t~f79,9g54,60009f4f78,1211650f77,75f12,15717145";
  //130
  packet1 += "f32,15270g77,115835537g97,822778v-15888603f86,1f16,115835f15,20170131t~";
  //203
  packet1 += "f4t1211650i-125f79,6g54,60000f12,15717270f28,1210564f32,15271g77,115835022";
  packet1 += "g97,822779v-15888728n-4650f86,1f16,115835f15,20170131f24,115835f23,20170131";
  packet1 += "f10,-0.38d~f79,9g54,9f4f78,1211675f77,60f12,15717330f32,2221681g77,115835296";
  packet1 += "g97,822788v-15888788f86,0f16,115835f15,20170131~g77,115835193g97,9786736kt9f";
  packet1 += "16,115835f15,20170131f27,115835f26,20170131~g77,115835606g97,9786742kt8f16,11";
  packet1 += "5835f15,20170131f27,115835f26,20170131~g77,115835488g97,9786750kt9f16,115835f";
  packet1 += "15,20170131f27,115835f26,20170131~g77,115835187g97,9786752kt8f16,115835f15,20";
  packet1 += "170131f27,115835f26,20170131~g77,115835645g97,9786765jp6f16,115835f15,20170131";
  packet1 += "f27,115835f26,20170131~g77,115835733g97,9786766jp5f16,115835f15,20170131f27,11";
  packet1 += "5835f26,20170131~g77,115835525g97,9786767kt9f16,115835f15,20170131f27,115835f26";
  packet1 += ",20170131~g77,115835457g97,9786768kt10f16,115835f15,20170131f27,115835f26,20170";
  packet1 += "131~g77,115835644g97,9786770kt9f16,115835f15,20170131f27,115835f26,20170131~g77,";
  packet1 += "115835150g97,9786772kt10f16,115835f15,20170131f27,115835f26,20170131b~f4t1211600";
  packet1 += "i1f79,6g54,60000f12,15717430f28,1210564f32,4409g77,115835847g97,822790v-15888888n-4700f86,1f";
  packet1 += "16,115835f15,20170131f24,115835f23,20170131f10,-0.39j~f4t1211600i1f79,6g54,60000f12,15717530f";
  packet1 += "28,1210564f32,3583g77,115835247g97,822791v-15888988n-4700f86,1f16,115835f15,20170131f24,1158";
  packet1 += "35f23,20170131f10,-0.39j~f79,9g54,60009f4f78,1211600f77,90f12,15717620f32,3584g77,115835198";
  packet1 += "g97,822792v-15889078f86,1f16,115835f15,20170131k~f79,9g54,60009f4f78,1211600f77,10f12,1571763";
  packet1 += "0f32,8773g77,115835076g97,822793v-15889088f86,1f16,115835f15,20170131";
  q.on_packet_delimiter(packet1[0]);
  for (int i = 0+1; i < 10; i++) q.on_header_char(packet1[i]);
  EXPECT_EQ(q.packet_header_str, "11:58:36 ");
  q.on_message_delimiter(packet1[10]);
  for (int i = 10+1; i < 83; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[83]);
  for (int i = 83+1; i < 200; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[200]);
  for (int i = 200+1; i < 361; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[361]);
  for (int i = 361+1; i < 476; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[476]);
  for (int i = 476+1; i < 549; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[549]);
  for (int i = 549+1; i < 622; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[622]);
  for (int i = 622+1; i < 695; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[695]);
  for (int i = 695+1; i < 768; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[768]);
  for (int i = 768+1; i < 841; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[841]);
  for (int i = 841+1; i < 987; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[987]);
  for (int i = 987+1; i < 1061; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[1061]);
  for (int i = 1061+1; i < 1134; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[1134]);
  for (int i = 1134+1; i < 1208; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[1208]);
  for (int i = 1208+1; i < 1365; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[1365]);
  for (int i = 1365+1; i < 1522; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[1522]);
  for (int i = 1522+1; i < 1522; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[1522]);
  for (int i = 1522+1; i < 1638; i++) q.on_message_char(packet1[i]);
  q.on_message_delimiter(packet1[1638]);
  for (int i = 1638+1; i < 1754; i++) q.on_message_char(packet1[i]);

  EXPECT_EQ(q.packet_header_str, "11:58:36 ");
  string packet2 = "11:58:37 d~f4t1211685i11f79,0g54,0f12,15718730f28,1210564f32,2221781g77,115836928g97,822814v-15890188n-4615f86,0f16,115836f15,20170131f24,115836f23,20170131f10,-0.38~g77,115836729g97,9787212jz6f16,115836f15,20170131f27,115836f26,20170131~g77,115836158g97,9787214kt9f16,115836f15,20170131f27,115836f26,20170131~g77,115836788g97,9787221jz7f16,115836f15,20170131f27,115836f26,20170131~g77,115837676g97,9787292kt8f16,115837f15,20170131f27,115837f26,20170131~g77,115837147g97,9787293jp7f16,115837f15,20170131f27,115837f26,20170131~g77,115837376g97,9787295jz6f16,115837f15,20170131f27,115837f26,20170131~g77,115837482g97,9787344kt9f16,115837f15,20170131f27,115837f26,20170131~g77,115837918g97,9787346kt8f16,115837f15,20170131f27,115837f26,20170131";
  q.on_packet_delimiter(packet2[0]);

  EXPECT_EQ(q.packet_header_str, "");
  EXPECT_FALSE(q.message_exists);
  EXPECT_FALSE(q.field_exists);
  EXPECT_EQ(q.first_prefix,0);
  EXPECT_EQ(q.message_delimiter,0);
  EXPECT_EQ(q.symbol,"");
  EXPECT_FALSE(q.message_header_complete);
  EXPECT_EQ(q.field_code,0);
  EXPECT_EQ(q.field_exchange_code,0);
  EXPECT_EQ(q.field_code_value,"");
  EXPECT_EQ(q.field_value,"");
}

TEST_F(quote_tests, field_delim) {
  quote q;
  EXPECT_TRUE(q.is_field_delimiter('i'));
}



#endif // QUOTE_TESTS_HPP_
