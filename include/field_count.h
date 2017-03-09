#ifndef FIELD_COUNT_H_
#define FIELD_COUNT_H_
#include <memory>
#include "quote_subject.h"
#include "quote_observer_interface.h"

class field_count : public quote_observer_interface {
public:
  field_count(shared_ptr<quote_subject> model) : quote_observer_interface(model) {}
  void update(shared_ptr<message>);
  void ping() {};
  void on_trade(const string& timestamp, const string& value) {}
  void on_trade_size(const string& timestamp, const string& value) {}
  void on_bid(const string& timestamp, const string& value) {}
  void on_bid_size(const string& timestamp, const string& value) {}
  void on_ask(const string& timestamp, const string& value) {}
  void on_ask_size(const string& timestamp, const string& value) {}
  void on_precision(const string& timestamp, const string& value) {}
  int get_count() { return count; }
private:
  int count = 0;
};

#endif
