#include "message.h"
#include <iostream> // for debuging only

using std::cout;
using std::endl;
using std::make_shared;

void message::add_char(const char& c)
{
  message_vector.push_back(c);
  /* symbol grammar:
   * message_delimiter stored when on_message_delimiter
   * first prefix : first message char and lower case
   * second prefix : the letter before a ':' if one exists
   * symbol everything before first delimiter that's not prefix or suffix or ':'
   * suffix : a character that is not alphabet
   * end of symbol : when first field is encountered
   */
  if (!message_header_complete) {
    if (is_first_char) {
      is_first_char = false;
      if (is_lower_case(c)) {
        first_prefix = c;
      } else {
        symbol_vector.push_back(c);
      }
    } else if (c == ':') {
      // symbol first char was actually a second prefix
      second_prefix = symbol_vector[0];
      symbol_vector.clear();
    } else if (is_field_delimiter(c)) {
      on_message_header_complete();
      on_field_delimiter(c);
    } else {
      symbol_vector.push_back(c);
    }
  } else {
    // collect field information
    if (is_field_delimiter(c)) {
      on_field_delimiter(c);
    } else {
      // TODO: feed characters to the field so it can construct itself
      fp->add_char(c);
    }
  }
}

void message::on_message_complete()
{
  if (fp != nullptr) {
    {
      finalize_field();
      fp = nullptr;
    }
  }
  for (auto& a : message_vector) cout << a;
  cout << endl;
}

void message::on_message_header_complete()
{
  message_header_complete =  true;

  if (!is_upper_case(symbol_vector[symbol_vector.size() - 1])
      && symbol_vector[symbol_vector.size() - 1] != '~') {
    suffix = symbol_vector[symbol_vector.size() - 1];
    symbol_vector.pop_back();
  }

  symbol.assign(symbol_vector.begin(),symbol_vector.end());
}

void message::on_field_delimiter(const char& c)
{
  // complete last field
  if (fp!=nullptr) {
    finalize_field();
    if (fp->is_single_char()) {
      // c is actually message first prefix
      if (first_prefix != 0) {
        cout << "ERROR message.cpp, first_prefix: " << first_prefix << endl;
      }
      first_prefix = c;
      // continue using same field
    } else {
      finalize_field();
      initialize_field(c);
    }
  } else {
    initialize_field(c);
  }
}

void message::initialize_field(const char& c)
{
  fp = make_shared<field>(c);
}

// void message::initialize_field(const char& c1, const char& c2)
// {
//   fp = make_shared<field>(c1,c2);
// }

void message::finalize_field()
{
  fp->on_field_complete();
  // TODO : instead of using this pointer request a pointer from the class
  // TODO : the field class has created a specialized version of itself and returns its pointer
  fields.push_back(fp);
}

bool message::is_field_delimiter(const char& c)
{
  return (c >= 97 && c <= 122) || ((int)c == 127);
}

bool message::is_lower_case(const char& c)
{
  return (c >= 97 && c <= 122);
}

bool message::is_upper_case(const char& c)
{
  return (c >= 65 && c <= 90);
}
