#include <iostream>
#include "message_header_printer.h"

using std::cout;
using std::endl;

void message_header_printer::update(shared_ptr<message> mp) {
  cout << endl;
  cout << mp->to_string();
}
