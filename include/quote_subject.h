#ifndef QUOTE_SUBJECT_H_
#define QUOTE_SUBJECT_H_

#include <memory>
#include <vector>
#include <message.h>

using std::vector;
using std::shared_ptr;

class quote_subject {

    vector < class quote_observer_interface * > views;
    vector < class quote_observer_interface * > trade_viewer;
    vector < class quote_observer_interface * > ask_viewer;
    vector < class quote_observer_interface * > bid_viewer;
    vector < class quote_observer_interface * > trade_size_viewer;
    vector < class quote_observer_interface * > ask_size_viewer;
    vector < class quote_observer_interface * > bid_size_viewer;

  public:
    void attach(quote_observer_interface *obs) {
        views.push_back(obs);
    }

    void attach_trade_viewer(quote_observer_interface *obs) {
        trade_viewer.push_back(obs);
    }
    void attach_trade_size_viewer(quote_observer_interface *obs) {
        trade_size_viewer.push_back(obs);
    }
    void attach_bid_viewer(quote_observer_interface *obs) {
        bid_viewer.push_back(obs);
    }
    void attach_bid_size_viewer(quote_observer_interface *obs) {
        bid_size_viewer.push_back(obs);
    }
    void attach_ask_viewer(quote_observer_interface *obs) {
        ask_viewer.push_back(obs);
    }
    void attach_ask_size_viewer(quote_observer_interface *obs) {
        ask_size_viewer.push_back(obs);
    }

    void notify(shared_ptr<message>);
    void notify_on_packet_header_complete(const string&);
    void notify_on_trade(const string& time_stamp, const string& value);
    void notify_on_ask(const string& time_stamp, const string& value);
    void notify_on_bid(const string& time_stamp, const string& value);
    void notify_on_trade_size(const string& time_stamp, const string& value);
    void notify_on_ask_size(const string& time_stamp, const string& value);
    void notify_on_bid_size(const string& time_stamp, const string& value);
    void notify_on_precision(const string& time_stamp, const string& value);
};

#endif
