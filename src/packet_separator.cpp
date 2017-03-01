#include "packet_separator.h"

void packet_separator::on_header_char(const char& c) {

  packet.push_back(c);
}

void packet_separator::on_message_char(const char& c) {
  packet.push_back(c);
}

void packet_separator::on_packet_delimiter(const char& c) {
  // write packet vect
  // TODO: if output path is not provided must throw an exception
  if (packet.size() > 0) {
    std::string output_file_name = "output" + std::to_string(output_count++) + ".CAP";
    std::string str(packet.begin(),packet.end());
    std::ofstream of(outputPath + output_file_name);

    of << str;
    packet.clear();
  }
  packet.push_back(c);
}

void packet_separator::on_message_delimiter(const char& c) {
  packet.push_back(c);
}
