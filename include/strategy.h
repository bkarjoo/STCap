#ifndef STRATEGY_H_
#define STRATEGY_H_
#include <memory>
#include <iostream>
#include <string>
#include "message_subject.h"
#include "message_observer.h"
#include "exchange_time.h"

using std::cout; using std::endl;

class strategy : public message_observer {
public:
  strategy();
  strategy(shared_ptr<message_subject> model) : message_observer(model) {}
  void update(shared_ptr<message>) {}
  void ping() { }
  void on_trade(const string& timestamp, const string& value);
  void on_trade_size(const string& timestamp, const string& value);
  void on_bid(const string& timestamp, const string& value);
  void on_bid_size(const string& timestamp, const string& value);
  void on_ask(const string& timestamp, const string& value);
  void on_ask_size(const string& timestamp, const string& value);
  void on_precision(const string& timestamp, const string& value);
  double get_time() { return time.seconds_from_midnight(); }
  double get_trade() { return trade; }
  double get_bid() { return bid; }
  double get_ask() { return ask; }
  double get_trade_size() { return trade_size; }
  double get_bid_size() { return bid_size; }
  double get_ask_size() { return ask_size; }
protected:
  exchange_time   time;
  double          trade;
  unsigned int    trade_size;
  double          bid;
  unsigned int    bid_size;
  double          ask;
  unsigned int    ask_size;
private:
  unsigned short int precision = 4;
  void set_time(const string& timestamp) { time.set(timestamp); }
  void set_trade(const string& value);
  void set_bid(const string& value);
  void set_ask(const string& value);
  void set_trade_size(const string& value);
  void set_bid_size(const string& value);
  void set_ask_size(const string& value);

  double convert_price(const string& value);
  int convert_size(const string& value);
};

#endif
