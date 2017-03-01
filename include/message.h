#ifndef MESSAGE_H
#define MESSAGE_H
#include <memory>
#include <string>
#include <vector>
#include "field.h"

using std::string;
using std::shared_ptr;
using std::vector;

class message {
public:
  message(char c) { message_delimiter = c; };
  ~message() {};
  // for efficiency chars are passed directly to message, which constructs itself
  void add_char(const char&);
  void on_message_complete();
  // symbol is set externally in the case of symbol file
  void set_symbol(string symb) { symbol = symb; }
  // getters : TODO complete getters for fields and message type enum is missing
  string get_symbol() { return symbol; }
  const char& get_first_prefix() { return first_prefix; }
  const char& get_second_prefix() { return second_prefix; }
  const char& get_suffix() { return suffix; }
private:
  // message components
  char first_prefix = 0;
  char second_prefix = 0;
  char suffix = 0;
  char message_delimiter = 0;
  string symbol;
  vector<shared_ptr<field>> fields;
  // helper vars
  bool is_first_char = true;
  bool message_header_complete = false;
  std::shared_ptr<field> fp = nullptr;
  std::vector<char> symbol_vector;
  std::vector<char> message_vector; // for testing only
  // helper functions
  void on_message_header_complete();
  void on_field_delimiter(const char&);
  void initialize_field(const char&);
  // TODO : the double var field constructor is a misunderstanding
  // TODO : second par is actually a message first_prefix
  // void initialize_field(const char&, const char&);
  void finalize_field();
  bool is_field_delimiter(const char&);
  bool is_lower_case(const char&);
  bool is_upper_case(const char&);
};
#endif // MESSAGE_H
