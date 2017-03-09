#ifndef QUOTE_OBSERVER_INTERFACE_H_
#define QUOTE_OBSERVER_INTERFACE_H_
#include <memory>
#include <message.h>



class quote_observer_interface {
    std::shared_ptr<quote_subject> model;

  public:
    quote_observer_interface(std::shared_ptr<class quote_subject> mod) {
        model = mod;
        model->attach(this);
    }
    virtual void update(std::shared_ptr<message>) = 0;
    virtual void ping(const string& packet_header) = 0;
    virtual void on_trade(const string& timestamp, const string& value) = 0;
    virtual void on_trade_size(const string& timestamp, const string& value) = 0;
    virtual void on_bid(const string& timestamp, const string& value) = 0;
    virtual void on_bid_size(const string& timestamp, const string& value) = 0;
    virtual void on_ask(const string& timestamp, const string& value) = 0;
    virtual void on_ask_size(const string& timestamp, const string& value) = 0;
    virtual void on_precision(const string& timestamp, const string& value) = 0;
  protected:
    std::shared_ptr<quote_subject> getmessage_subject() {
        return model;
    }
};

#endif
