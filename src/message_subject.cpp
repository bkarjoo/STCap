#include "message_subject.h"
#include "message_observer.h"

void message_subject::notify(shared_ptr<message> msg) {
  // 5. Publisher broadcasts
  for (int i = 0; i < views.size(); i++)
    views[i]->update(msg);
}

void message_subject::notify2() {
  for (int i = 0; i < views.size(); i++)
    views[i]->ping();
}

void message_subject::notify_on_trade(const string& time_stamp, const string& value)
{
  for (int i = 0; i < trade_viewer.size(); i++)
    trade_viewer[i]->on_trade(time_stamp, value);
}

void message_subject::notify_on_ask(const string& time_stamp, const string& value)
{
  for (int i = 0; i < ask_viewer.size(); i++)
    ask_viewer[i]->on_ask(time_stamp, value);
}

void message_subject::notify_on_bid(const string& time_stamp, const string& value)
{
  for (int i = 0; i < bid_viewer.size(); i++)
    bid_viewer[i]->on_bid(time_stamp, value);
}

void message_subject::notify_on_trade_size(const string& time_stamp, const string& value)
{
  for (int i = 0; i < trade_size_viewer.size(); i++)
    trade_size_viewer[i]->on_trade_size(time_stamp, value);
}

void message_subject::notify_on_ask_size(const string& time_stamp, const string& value)
{
  for (int i = 0; i < ask_size_viewer.size(); i++)
    ask_size_viewer[i]->on_ask_size(time_stamp, value);
}

void message_subject::notify_on_bid_size(const string& time_stamp, const string& value)
{
  for (int i = 0; i < bid_size_viewer.size(); i++)
    bid_size_viewer[i]->on_bid_size(time_stamp, value);
}
