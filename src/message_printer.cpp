#include <iostream>
#include "message_printer.h"

using namespace std;

void message_printer::on_header_char(const char& c)
{
  cout << c;
}

void message_printer::on_message_char(const char& c)
{
  cout << c;
}

void message_printer::on_packet_delimiter(const char& c)
{
  cout << endl;
}

void message_printer::on_message_delimiter(const char& c)
{
  cout << endl << c << " (" << ((int)c) << ")" << endl;
}
