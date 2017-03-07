#ifndef QUOTE_OBSERVER_H_
#define QUOTE_OBSERVER_H_
#include <memory>
#include <iostream>
#include <string>
#include "message_subject.h"
#include "message_observer.h"


class quote_observer : public message_observer {
public:
  quote_observer(std::shared_ptr<message_subject> model) : message_observer(model) {}
  void update(std::shared_ptr<message>) {}
  void ping(const std::string&) { count++; }
  void on_trade(const std::string& timestamp, const std::string& value) {}
  void on_trade_size(const std::string& timestamp, const std::string& value) {}
  void on_bid(const std::string& timestamp, const std::string& value) {}
  void on_bid_size(const std::string& timestamp, const std::string& value) {}
  void on_ask(const std::string& timestamp, const std::string& value) {}
  void on_ask_size(const std::string& timestamp, const std::string& value) {}
  void on_precision(const std::string& timestamp, const std::string& value) {}

  int get_count() { return count; }
private:
  int count = 0;
};

#endif
