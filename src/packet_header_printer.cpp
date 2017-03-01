#include <iostream>
#include "packet_header_printer.h"

using namespace std;



void packet_header_printer::on_header_char(const char& c)
{
  cout << c;
}

void packet_header_printer::on_message_char(const char& c)
{

}

void packet_header_printer::on_packet_delimiter(const char& c)
{
  in_packet = true;
  cout << endl;
}

void packet_header_printer::on_message_delimiter(const char& c)
{
  if (in_packet) cout << endl;
  in_packet = false;
}
