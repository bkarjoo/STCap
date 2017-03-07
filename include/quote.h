#ifndef QUOTE_H_
#define QUOTE_H_
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include "cap_char_receiver_interface.h"
#include "message_subject.h"
#include "quote_observer.h"

using std::string;
using std::vector;
using std::shared_ptr;

class quote_observer;

class quote : public cap_char_receiver_interface, public message_subject {
  friend class quote_tests;
public:
  quote() {  }
  ~quote() {}
  void on_header_char(const char&);
  void on_message_char(const char&);
  void on_packet_delimiter(const char&);
  void on_message_delimiter(const char&);


  string packet_header_str = "";
  bool packet_header_complete = false;
  // message
  char first_prefix = 0;
  char message_delimiter = 0;
  string symbol = "";
  bool message_exists = false;
  bool message_header_complete = false;
  void initialize_message(const char&);
  void finalize_message();
  void message_header_builder(const char&);
  void reset_message();

  // field
  char field_code = 0;
  char field_exchange_code = 0;
  string field_code_value = "";
  string field_value = "";
  bool field_exists = false;
  void on_field_delimiter(const char&);
  bool is_field_delimiter(const char&);
  void field_builder(const char&);
  void initialize_field(const char&);
  void finalize_field();
  void reset_field();
  string time_stamp = "";

};

#endif
