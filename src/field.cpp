#include "field.h"
#include <string>
#include <iostream> // for testing
using std::string;
using std::cout;
using std::endl;

void field::add_char(const char& c)
{
  // field delimiter set at constructor
  /* field grammar :
   * field delimiter may be one or two chars (set by constructor)
   * field delimiter is followed by one or two values
   * if it's followed by two values it's separated by a comma
   */
   if (c == ',') {
      comma_encountered = true;
   } else if (!comma_encountered) {
      first_value_vector.push_back(c);
   } else {
      second_value_vector.push_back(c);
   }
}

bool field::is_single_char()
{
  return char_code_prefix == 0 && num_code == 0 && value == 0;
}

void field::on_field_complete()
{
  if (first_value_vector.size() == 0 && second_value_vector.size() == 0) return;
  string first_value_str, second_value_str;
  if (first_value_vector.size() > 0) {
    first_value_str.assign(first_value_vector.begin(), first_value_vector.end());
  }
  if (second_value_vector.size() > 0) {
    second_value_str.assign(second_value_vector.begin(), second_value_vector.end());
  }
  if (comma_encountered) {
    // second value is real value
    if (first_value_str != "") char_code_value = stoi(first_value_str);
    if (second_value_str != "") value = stoi(second_value_str);
  } else {
    if (first_value_str != "") value = stoi(first_value_str);
  }
}
