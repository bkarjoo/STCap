#ifndef MESSAGE_HEADER_PRINTER_H_
#define MESSAGE_HEADER_PRINTER_H_
#include <memory>
#include "message_subject.h"
#include "message_observer.h"


using std::shared_ptr;

class message_subject;

class message_header_printer : public message_observer {
public:
    message_header_printer(shared_ptr<message_subject> model) : message_observer(model) {}
    void update(shared_ptr<message>);
    void ping() {};
    void on_trade(const string& timestamp, const string& value) {}
    void on_trade_size(const string& timestamp, const string& value) {}
    void on_bid(const string& timestamp, const string& value) {}
    void on_bid_size(const string& timestamp, const string& value) {}
    void on_ask(const string& timestamp, const string& value) {}
    void on_ask_size(const string& timestamp, const string& value) {}
};

#endif
