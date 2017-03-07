#include <iostream>
#include "message_constructor.h"


using namespace std;

void message_constructor::on_header_char(const char& c)
{

}

void message_constructor::on_message_char(const char& c)
{
  mp->add_char(c);
}

void message_constructor::on_packet_delimiter(const char& c)
{
  // cout << "\nPacket Delimiter: " << c << endl;
  if (mp != nullptr) {
    finalize_message();
  }
}

void message_constructor::on_message_delimiter(const char& c)
{
  if (mp != nullptr) {
    finalize_message();
  }
  initialize_message(c);
}

void message_constructor::initialize_message(const char& c)
{
  mp = make_shared<message>(c);
}

//
void message_constructor::finalize_message()
{
  if (mp != nullptr) mp->on_message_complete();
  notify(mp);
  mp = nullptr;
}
