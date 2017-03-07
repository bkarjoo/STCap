#include "strategy.h"

void strategy::on_trade(const string& timestamp, const string& value)
{
  set_time(timestamp);
  set_trade(value);
}

void strategy::on_trade_size(const string& timestamp, const string& value)
{
  set_time(timestamp);
  set_trade_size(value) ;
}

void strategy::on_bid(const string& timestamp, const string& value)
{
  set_time(timestamp);
  set_bid(value);
}

void strategy::on_bid_size(const string& timestamp, const string& value)
{
  set_time(timestamp);
  set_bid_size(value);
}

void strategy::on_ask(const string& timestamp, const string& value)
{
  set_time(timestamp);
  set_ask(value);
}

void strategy::on_ask_size(const string& timestamp, const string& value)
{
  set_time(timestamp);
  set_ask_size(value);
}

void strategy::on_precision(const string& timestamp, const string& value)
{
  try {
    precision = stoi(value);
  } catch (...) {

  }
}

double strategy::convert_price(const string& value)
{
  try {
    int i = stoi(value);
    int divisor;
    switch (precision) {
      case 4:
        divisor = 10000;
        break;
      case 3:
        divisor = 1000;
        break;
      case 5:
        divisor = 100000;
        break;
      case 6:
        divisor = 1000000;
        break;
      case 7:
        divisor = 10000000;
        break;
      case 2:
        divisor = 100;
        break;
      case 8:
        divisor = 100000000;
        break;
      case 9:
        divisor = 1000000000;
        break;
      case 1:
        divisor = 10;
        break;
    }
    double d = i / (double)divisor;
    return d;
  } catch (...) {
    return 0;
  }


}

void strategy::set_trade(const string& value)
{
  double val = convert_price(value);
  if (val != 0) trade = val;
}

void strategy::set_bid(const string& value)
{
  double val = convert_price(value);
  if (val != 0) bid = val;
}

void strategy::set_ask(const string& value)
{
  double val = convert_price(value);
  if (val != 0) ask = val;
}

void strategy::set_trade_size(const string& value)
{
  int val = convert_size(value);
  if (val != 0) trade_size = val * 100;
}

void strategy::set_bid_size(const string& value)
{
  int val = convert_size(value);
  if (val != 0) bid_size = val * 100;
}

void strategy::set_ask_size(const string& value)
{
  int val = convert_size(value);
  if (val != 0) ask_size = val * 100;
}

int strategy::convert_size(const string& value)
{
  try {
    int i = stoi(value);
    return i;
  } catch (...) {
    return 0;
  }
}
