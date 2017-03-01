#ifndef FIELD_H_
#define FIELD_H_

#include <vector>
#include "field_type.h"

using std::vector;

class field {
public:
  // constructors
  field(const char& c) : char_code(c) { }
  //field(const char& c1, const char& c2)
  //    : char_code(c1), char_code_prefix(c2) {}
  ~field() {};
  // main interface 
  void add_char(const char&);
  bool is_single_char();
  const char& get_char_code() { return char_code; }
  void on_field_complete();
  int get_char_code_value() { return char_code_value; }
  int get_value() { return value; }
  bool has_char_code_value() { return comma_encountered; }
  unsigned short int get_num_code() { return num_code; }
  char get_char_code_prefix() { return char_code_prefix; }
private:
  // field components
  char char_code_prefix = 0;
  char char_code = 0;
  unsigned short int num_code = 0;
  int value = 0;
  int char_code_value = 0;
  field_type type = field_type::undefined;
  vector<char> all_chars; // FOR TESTING PURPOSES
  // helper vars
  bool comma_encountered = false;
  vector<char> first_value_vector;
  vector<char> second_value_vector;
  // helper function

};

#endif // FIELD_H_
