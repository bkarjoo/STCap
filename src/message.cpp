#include "message.h"
#include <iostream> // for debuging only

using std::cout;
using std::endl;
using std::make_shared;

void message::add_char(const char& c)
{
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
        symbol += c;
      }
      message_str += c;
    } else if (c == ':') {
      // symbol first char was actually a second prefix
      second_prefix = symbol[0];
      symbol = "";
      message_str += c;
    } else if (is_field_delimiter(c)) {
      on_message_header_complete();
      on_field_delimiter(c);
    } else {
      symbol += c;
      message_str += c;
    }
  } else {
    // collect field information
    if (is_field_delimiter(c)) {
      on_field_delimiter(c);
      previous_char_was_delimiter = true;
    } else {
      // TODO: feed characters to the field so it can construct itself
      fp->add_char(c);
      previous_char_was_delimiter = false;
    }
  }
}

void message::on_message_complete()
{
  if (fp != nullptr) {
    {
      finalize_field();
    }
  }

}

void message::on_message_header_complete()
{
  message_header_complete =  true;

  if (!is_upper_case(symbol.back())
      && symbol.back() != '~') {
    suffix = symbol.back();
    symbol.erase(symbol.end()-1,symbol.end());
  }
}

void message::on_field_delimiter(const char& c)
{
  // complete last field
  if (fp!=nullptr) {
    if (previous_char_was_delimiter) {
      fp->set_exchange_code(c);
    } else {
      finalize_field();
      initialize_field(c);
    }
  } else
    initialize_field(c);
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

  field_name fn = fp->get_field_name();

  // fields.push_back(fp);

  if (
    fn != field_name::g97 &&
    fn != field_name::f15 &&
    fn != field_name::f16 &&
    fn != field_name::f27 &&
    fn != field_name::v &&
    fn != field_name::f32 &&
    fn != field_name::f12 &&
    fn != field_name::f26 &&
    fn != field_name::f23 &&
    fn != field_name::f24 &&
    fn != field_name::n &&
    fn != field_name::f10 &&
    fn != field_name::f19 &&
    fn != field_name::f47
  ) {

    message_str += fp->get_field_str();

    fields.push_back(fp);
  }
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
