#include "cap_file.h"
#include <iostream>

using namespace std;

cap_file::cap_file(std::string pfullPath)
{
  fullPath = pfullPath;
}

// reads the file character by character
void cap_file::run()
{
  ifstream fs(fullPath);
  fs.get(c);
  while (true) {
    if (is_packet_delimiter()) {
      process_packet_delimiter();
      read_packet_header(fs);
    } else if (is_message_delimiter()) {
      process_message_delimiter();
      read_message(fs);
    } else {
      process_packet_delimiter();
      break;
    }
  }
}

void cap_file::process_packet_delimiter()
{
  client_ptr->on_packet_delimiter(c);
}

void cap_file::process_message_delimiter()
{
  client_ptr->on_message_delimiter(c);
}

void cap_file::read_packet_header(ifstream& fs)
{
  while (fs.get(c)) {
    if (is_message_delimiter())
      return;
    else {
      client_ptr->on_header_char(c);
    }
  }
  c = 0;
}

void cap_file::read_message(ifstream& fs)
{
  while (fs.get(c)) {
    if (is_delimiter())
      return;
    else {
      client_ptr->on_message_char(c);
    }
  }
  c = 0;
}

bool cap_file::is_delimiter()
{
  return (is_packet_delimiter() || is_message_delimiter());
}

bool cap_file::is_packet_delimiter()
{
  return ((int)c == PACKET_DELIMITER);
}

bool cap_file::is_message_delimiter()
{
  return ((int)c == M11_DELIMITER || (int)c == M13_DELIMITER
    || (int)c == M14_DELIMITER || (int)c == M15_DELIMITER);
}
