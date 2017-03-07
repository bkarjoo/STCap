#ifndef FIELD_FINDER_H_
#define FIELD_FINDER_H_
#include <memory>
#include "message_subject.h"
#include "message_observer.h"

using std::shared_ptr;

struct cnt {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0;
  int f = 0;
  int g = 0;
  int h = 0;
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int m = 0;
  int n = 0;
  int o = 0;
  int p = 0;
  int q = 0;
  int r = 0;
  int s = 0;
  int t = 0;
  int u = 0;
  int v = 0;
  int w = 0;
  int x = 0;
  int y = 0;
  int z = 0;
  int DEL = 0;
  int z237 = 0;
  int z243 = 0;
  int z244 = 0;
  int z245 = 0;
  int z258 = 0;
  int z650 = 0;
  int z941 = 0;
  int z942 = 0;
  int z943 = 0;
  int fcodes[100] = {0};
  int gcodes[100] = {0};
}
;

class field_finder : public message_observer {

public:
  field_finder(shared_ptr<message_subject> model) : message_observer(model) {}
  void update(shared_ptr<message>);
  void ping() {};
  void on_trade(const string& timestamp, const string& value) {}
  void on_trade_size(const string& timestamp, const string& value) {}
  void on_bid(const string& timestamp, const string& value) {}
  void on_bid_size(const string& timestamp, const string& value) {}
  void on_ask(const string& timestamp, const string& value) {}
  void on_ask_size(const string& timestamp, const string& value) {}
  int output_number = 0;
  cnt count;
  void print_counts_to_cout();
};

#endif
