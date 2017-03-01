#include "cap_char_receiver.h"

void cap_char_receiver::on_header_char(const char& c) {
  char_count++;
}

void cap_char_receiver::on_message_char(const char& c) {
  char_count++;
}

void cap_char_receiver::on_packet_delimiter(const char& c) {
  char_count++;
  packet_count++;
}

void cap_char_receiver::on_message_delimiter(const char& c) {
  char_count++;
  message_count++;
}
