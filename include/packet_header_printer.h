#ifndef PACKET_HEADER_PRINTER_H_
#define PACKET_HEADER_PRINTER_H_

#include "cap_char_receiver_interface.h"

class packet_header_printer : public cap_char_receiver_interface {
public:
  packet_header_printer() {}
  ~packet_header_printer() {}
  void on_header_char(const char&);
  void on_message_char(const char&);
  void on_packet_delimiter(const char&);
  void on_message_delimiter(const char&);
private:
  bool in_packet = true;
};

#endif // PACKET_HEADER_PRINTER_H_
