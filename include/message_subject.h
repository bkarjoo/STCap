#ifndef MESSAGE_SUBJECT_H_
#define MESSAGE_SUBJECT_H_

#include <memory>
#include <vector>
#include <message.h>

using std::vector;
using std::shared_ptr;

class message_subject {

    vector < class message_observer * > views;
    vector < class message_observer * > trade_viewer;
    vector < class message_observer * > ask_viewer;
    vector < class message_observer * > bid_viewer;
    vector < class message_observer * > trade_size_viewer;
    vector < class message_observer * > ask_size_viewer;
    vector < class message_observer * > bid_size_viewer;

  public:
    void attach(message_observer *obs) {
        views.push_back(obs);
    }

    void attach_trade_viewer(message_observer *obs) {
        trade_viewer.push_back(obs);
    }
    void attach_trade_size_viewer(message_observer *obs) {
        trade_size_viewer.push_back(obs);
    }
    void attach_bid_viewer(message_observer *obs) {
        bid_viewer.push_back(obs);
    }
    void attach_bid_size_viewer(message_observer *obs) {
        bid_size_viewer.push_back(obs);
    }
    void attach_ask_viewer(message_observer *obs) {
        ask_viewer.push_back(obs);
    }
    void attach_ask_size_viewer(message_observer *obs) {
        ask_size_viewer.push_back(obs);
    }


    void notify(shared_ptr<message>);
    void notify2();
    void notify_on_trade(const string& time_stamp, const string& value);
    void notify_on_ask(const string& time_stamp, const string& value);
    void notify_on_bid(const string& time_stamp, const string& value);
    void notify_on_trade_size(const string& time_stamp, const string& value);
    void notify_on_ask_size(const string& time_stamp, const string& value);
    void notify_on_bid_size(const string& time_stamp, const string& value);
};

#endif
