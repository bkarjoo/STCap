#ifndef MESSAGE_INTERPRETER_H_
#define MESSAGE_INTERPRETER_H_
#include <memory>
#include <string>
#include <vector>
#include "cap_char_receiver_interface.h"
#include "message.h"
#include "message_subject.h"
#include "field.h"


class message_interpreter : public cap_char_receiver_interface, public message_subject {
public:
  message_interpreter() {  }
  ~message_interpreter() {}
  void on_header_char(const char&);
  void on_message_char(const char&);
  void on_packet_delimiter(const char&);
  void on_message_delimiter(const char&);
private:
  std::shared_ptr<message> mp = nullptr;
  void initialize_message(const char&);
  void finalize_message();
};

#endif // MESSAGE_INTERPRETER_H_
