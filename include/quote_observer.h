#ifndef QUOTE_OBSERVER_H_
#define QUOTE_OBSERVER_H_
#include <memory>
#include <iostream>
#include <string>
#include "message_subject.h"
#include "message_observer.h"

using std::cout; using std::endl;

class quote_observer : public message_observer {
public:
  quote_observer(shared_ptr<message_subject> model) : message_observer(model) {}
  void update(shared_ptr<message>) {}
  void ping() { count++; }
  void on_trade(const string& timestamp, const string& value) {}
  void on_trade_size(const string& timestamp, const string& value) {}
  void on_bid(const string& timestamp, const string& value) {}
  void on_bid_size(const string& timestamp, const string& value) {}
  void on_ask(const string& timestamp, const string& value) {}
  void on_ask_size(const string& timestamp, const string& value) {}

  int get_count() { return count; }
private:
  int count = 0;
};

#endif
