#ifndef MESSAGE_OBSERVER_H_
#define MESSAGE_OBSERVER_H_
#include <memory>
#include <message.h>



class message_observer {
    std::shared_ptr<message_subject> model;

  public:
    message_observer(std::shared_ptr<class message_subject> mod) {
        model = mod;
        model->attach(this);
    }
    virtual void update(std::shared_ptr<message>) = 0;
    virtual void ping() = 0;
    virtual void on_trade(const string& timestamp, const string& value) = 0;
    virtual void on_trade_size(const string& timestamp, const string& value) = 0;
    virtual void on_bid(const string& timestamp, const string& value) = 0;
    virtual void on_bid_size(const string& timestamp, const string& value) = 0;
    virtual void on_ask(const string& timestamp, const string& value) = 0;
    virtual void on_ask_size(const string& timestamp, const string& value) = 0;
    virtual void on_precision(const string& timestamp, const string& value) = 0;
  protected:
    std::shared_ptr<message_subject> getmessage_subject() {
        return model;
    }
};

#endif
