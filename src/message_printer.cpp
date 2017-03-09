#include <iostream>
#include "message_printer.h"

using namespace std;

void message_printer::on_header_char(const char& c)
{
}

void message_printer::on_message_char(const char& c)
{
  msg_str += c;
  if (c == 'g')
    g_field_encountered = true;
  else if (g_field_encountered) {
    if (((c >= 97 and c <= 122) || c == ',')) {
      g_field_encountered = false;
      if (g_field_str == "10") print_message = true;
      g_field_str = "";
    } else {
      g_field_str += c;
      if (g_field_str == "10") print_message = true;
    }
  }
}

void message_printer::on_packet_delimiter(const char& c)
{
  if (print_message) cout << msg_str;
  msg_str = "";
  g_field_encountered = false;
  g_field_str = "";
}

void message_printer::on_message_delimiter(const char& c)
{
  if (print_message) cout << msg_str;
  msg_str = "";
  g_field_encountered = false;
  g_field_str = "";
}
