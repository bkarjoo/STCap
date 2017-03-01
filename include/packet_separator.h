#ifndef PACKET_SEPARATOR_H_
#define PACKET_SEPARATOR_H_

#include <fstream>
#include <string>
#include <vector>
#include "cap_char_receiver_interface.h"

class packet_separator : public cap_char_receiver_interface {
public:
  packet_separator() {};
  ~packet_separator() {};
  void on_header_char(const char&);
  void on_message_char(const char&);
  void on_packet_delimiter(const char&);
  void on_message_delimiter(const char&);
  void set_output_path(std::string op) { outputPath = op; }
private:
  std::string outputPath;
  std::vector<char> packet;
  unsigned int output_count = 0;
};

#endif // PACKET_SEPARATOR_H_
