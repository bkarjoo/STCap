#ifndef FIELD_H_
#define FIELD_H_

#include <string>
#include "field_name.h"
#include "field_value_type.h"

using std::string;

class field {
public:
  // constructors
  field(const char& c) : char_code(c) { }
  ~field() {};
  // main interface
  void add_char(const char&);
  void on_field_complete();
  bool is_single_char();
  //
  const char& get_char_code() { return char_code; }
  int get_char_code_value() { return char_code_value; }
  bool has_char_code_value() { return comma_encountered; }
  string get_value() { return value; }
  field_name get_field_name() { return get_all_field_name(char_code, char_code_value); }
  const string& get_field_str();
  const char& get_exchange_code() { return exchange_code; }
  void set_exchange_code(const char& c) { exchange_code = c; }
private:
  // field components
  char char_code = 0;
  int char_code_value = 0;
  string value = "";
  string all_chars;
  char exchange_code = 0;
  // helper vars
  bool comma_encountered = false;
  string first_value_str;
  string second_value_str;
  // helper function
  field_name get_all_field_name(const char&, const int&) const;
  field_name get_f_field_name(const int&) const;
  field_name get_g_field_name(const int&) const;
};

#endif // FIELD_H_
