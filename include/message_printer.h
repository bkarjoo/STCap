#ifndef MESSAGE_PRINTER_H_
#define MESSAGE_PRINTER_H_

#include "cap_char_receiver_interface.h"

class message_printer : public cap_char_receiver_interface {
public:
  message_printer() {}
  ~message_printer() {}
  void on_header_char(const char&);
  void on_message_char(const char&);
  void on_packet_delimiter(const char&);
  void on_message_delimiter(const char&);
};

#endif // MESSAGE_PRINTER_H_
