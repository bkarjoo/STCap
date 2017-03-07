#include "quote.h"
#include <iostream>

using namespace std;

void quote::on_header_char(const char& c)
{
  packet_header_str += c;
}

void quote::on_message_char(const char& c)
{
  if (!message_header_complete)
    message_header_builder(c);
  else if (is_field_delimiter(c))
    on_field_delimiter(c);
  else
    field_builder(c);
}

void quote::on_packet_delimiter(const char& c)
{
  if (field_exists) finalize_field(); // don't initialize until field delimiter
  if (message_exists) finalize_message(); // don't initialize until message delimiter

  packet_header_str = "";
  packet_header_complete = false;
}

void quote::on_message_delimiter(const char& c)
{
  if (!packet_header_complete) {
    packet_header_complete = true;
    notify_on_packet_header_complete(packet_header_str);
  }
  if (field_exists) finalize_field();
  if (message_exists) finalize_message();
  initialize_message(c);
}

void quote::initialize_message(const char& c)
{
  if (message_exists) reset_message();
  message_delimiter = c;
  message_exists = true;
}

void quote::on_field_delimiter(const char& c)
{
  if (field_exists) {
    if (field_value == "")
      field_exchange_code = c;
    else {
      finalize_field();
      initialize_field(c);
    }
  } else {
    message_header_complete = true;
    initialize_field(c);
  }
}

void quote::finalize_message()
{
  // TODO notify if subscribers
  if (field_exists) finalize_field();
  reset_message();
  message_exists = false;
}

void quote::message_header_builder(const char& c)
{
  if ((int)c >= 97 && (int)c <= 122) {
      if (symbol.length() == 0) first_prefix = c; else on_field_delimiter(c);
  } else {
      symbol += c;
  }
}

void quote::reset_message()
{
  first_prefix = 0;
  message_delimiter = 0;
  symbol = "";
  message_header_complete = false;
}

void quote::initialize_field(const char& c)
{
  if (field_exists) reset_field();
  field_code = c;
  field_exists = true;
}

void quote::finalize_field()
{
  // TOOD notify if field is notifiable
  try {
    //cout << field_code << endl;
    switch (field_code) {
      case 'g':
        if(field_code_value == "77") swap(time_stamp,field_value);
        break;
      case 'f':
        if(field_code_value == "") notify_on_precision(time_stamp,field_value);
        break;
      case 'j':
        notify_on_bid_size(time_stamp, field_value);
        break;
      case 'k':
        notify_on_ask_size(time_stamp, field_value);
        break;
      case 't':
        notify_on_trade(time_stamp, field_value);
        break;
      case 'i':
        notify_on_trade_size(time_stamp, field_value);
        break;
      case 'a':
        notify_on_ask(time_stamp, field_value);
        break;
      case 'b':
        notify_on_bid(time_stamp, field_value);
        break;
    }
  } catch (...) {}
  reset_field();
  field_exists = false;
}

void quote::reset_field()
{
  field_code = 0;
  field_code_value = "";
  field_value = "";
  field_exchange_code = 0;
}

void quote::field_builder(const char& c)
{
  if (c == ',') {
    std::swap(field_value, field_code_value);
  } else
    field_value += c;
}

bool quote::is_field_delimiter(const char& c)
{
  return (c >= 97 && c <=122) || c == 127;
}
