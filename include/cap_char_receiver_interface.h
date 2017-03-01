#ifndef CAP_CHAR_RECEIVER_INTERFACE_H_
#define CAP_CHAR_RECEIVER_INTERFACE_H_

class cap_char_receiver_interface {
public:
  cap_char_receiver_interface() {};
  ~cap_char_receiver_interface() {};
  virtual void on_header_char(const char&) = 0;
  virtual void on_message_char(const char&) = 0;
  virtual void on_packet_delimiter(const char&) = 0;
  virtual void on_message_delimiter(const char&) = 0;
};

#endif // CAP_CHAR_RECEIVER_INTERFACE_H_
