#ifndef CAP_FILE_H_
#define CAP_FILE_H_
/*
 * reads a cap_file
 */
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include "cap_char_receiver_interface.h"

class CapFileTests;
enum class read_mode_type { HEADER, SYMBOL, FIELD };

class cap_file {
  friend class CapFileTests;
public:
  // constructors
  cap_file() {}
  cap_file(std::string);
  // functions
  void run();
  // getters 
  std::string get_full_path() { return fullPath; }
  // setters
  void set_full_path(std::string s) { fullPath = s; }
  void set_client(std::shared_ptr<cap_char_receiver_interface> p) { client_ptr = p;  }
private:
  // constants
  const unsigned short int M11_DELIMITER = 11;
  const unsigned short int M13_DELIMITER = 13;
  const unsigned short int M14_DELIMITER = 14;
  const unsigned short int M15_DELIMITER = 15;
  const unsigned short int PACKET_DELIMITER = 31;
  // variables
  char c = 0;
  std::string fullPath;
  std::shared_ptr<class cap_char_receiver_interface> client_ptr;
  // functions
  bool is_packet_delimiter();
  bool is_message_delimiter();
  bool is_delimiter();
  void process_packet_delimiter();
  void process_message_delimiter();
  void read_packet_header(std::ifstream&);
  void read_message(std::ifstream&);
};

#endif
