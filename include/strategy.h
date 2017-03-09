#ifndef STRATEGY_H_
#define STRATEGY_H_
#include <memory>
#include <iostream>
#include <string>
#include "quote_subject.h"
#include "quote_observer_interface.h"
#include "exchange_time.h"

using std::cout; using std::endl;

class strategy : public quote_observer_interface {
public:
  strategy();
  strategy(shared_ptr<quote_subject> model) : quote_observer_interface(model) {}
  void update(shared_ptr<message>) {}
  void ping(const string& packet_header);
  void on_last(const string& timestamp, const string& value);
  void on_last_size(const string& timestamp, const string& value);
  void on_bid(const string& timestamp, const string& value);
  void on_bid_size(const string& timestamp, const string& value);
  void on_ask(const string& timestamp, const string& value);
  void on_ask_size(const string& timestamp, const string& value);
  void on_precision(const string& timestamp, const string& value);
  double get_time() { return time.get_seconds_from_midnight(); }
  double get_last() { return last; }
  double get_bid() { return bid; }
  double get_ask() { return ask; }
  double get_last_size() { return last_size; }
  double get_bid_size() { return bid_size; }
  double get_ask_size() { return ask_size; }
  std::string covert_header_to_timestamp(const string&);
protected:
  exchange_time   time;
  double          last;
  unsigned int    last_size;
  double          bid;
  unsigned int    bid_size;
  double          ask;
  unsigned int    ask_size;
private:
  unsigned short int precision = 4;
  void set_time(const string& timestamp) { time.set_time(timestamp); }
  void set_last(const string&);
  void set_bid(const string&);
  void set_ask(const string&);
  void set_last_size(const string&);
  void set_bid_size(const string&);
  void set_ask_size(const string&);

  double convert_price(const string&);
  int convert_size(const string&);

};

#endif
