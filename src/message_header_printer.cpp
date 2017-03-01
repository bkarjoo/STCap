#include <iostream>
#include "message_header_printer.h"

using std::cout;
using std::endl;

void message_header_printer::update(shared_ptr<message> mp) {
  cout << endl;
  cout << "first_prefix: " << mp->get_first_prefix() << endl;
  cout << "second_prefix: " << mp->get_second_prefix() << endl;
  cout << "symbol: " << mp->get_symbol() << endl;
  cout << "suffix: " << mp->get_suffix() << endl;
}
