#ifndef CAP_CHAR_RECEIVER_H_
#define CAP_CHAR_RECEIVER_H_

#include "cap_char_receiver_interface.h"

class cap_char_receiver : public cap_char_receiver_interface {
public:
  cap_char_receiver() {};
  ~cap_char_receiver() {};
  void on_header_char(const char&);
  void on_message_char(const char&);
  void on_packet_delimiter(const char&);
  void on_message_delimiter(const char&);
  int get_char_count() { return char_count; }
  int get_packet_count() { return packet_count; }
  int get_message_count() { return message_count; }

private:
  int char_count = 0;
  int packet_count = 0;
  int message_count = 0;
};

#endif // CAP_CHAR_RECEIVER_H_
