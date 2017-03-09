#ifndef QUOTE_OBSERVER_H_
#define QUOTE_OBSERVER_H_
#include <memory>
#include <iostream>
#include <string>
#include "quote_subject.h"
#include "quote_observer_interface.h"


class quote_observer : public quote_observer_interface {
public:
  quote_observer(std::shared_ptr<quote_subject> model) : quote_observer_interface(model) {}
  void update(std::shared_ptr<message>) {}
  void ping(const std::string&) { count++; }
  void on_trade(const std::string& timestamp, const std::string& value) { std::cout << timestamp << ": " << "Trade: " << value << std::endl; }
  void on_trade_size(const std::string& timestamp, const std::string& value) { std::cout << timestamp << ": " << "TradeSize: " << value << std::endl; }
  void on_bid(const std::string& timestamp, const std::string& value) { std::cout << timestamp << ": " << "Bid: " << value << std::endl; }
  void on_bid_size(const std::string& timestamp, const std::string& value) { std::cout << timestamp << ": " << "BidSize: " << value << std::endl; }
  void on_ask(const std::string& timestamp, const std::string& value) { std::cout << timestamp << ": " << "Ask: " << value << std::endl; }
  void on_ask_size(const std::string& timestamp, const std::string& value) { std::cout << timestamp << ": " << "AskSize: " << value << std::endl; }
  void on_precision(const std::string& timestamp, const std::string& value) { std::cout << timestamp << ": " << "Precision: " << value << std::endl; }

  int get_count() { return count; }
private:
  int count = 0;
};

#endif
