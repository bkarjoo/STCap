#ifndef MESSAGE_OBSERVER_H_
#define MESSAGE_OBSERVER_H_
#include <memory>
#include <message.h>

using std::shared_ptr;

class message_observer {
    shared_ptr<message_subject> model;
    int denom;
  public:
    message_observer(shared_ptr<class message_subject> mod) {
        model = mod;
        model->attach(this);
    }
    virtual void update(shared_ptr<message>) = 0;
  protected:
    shared_ptr<message_subject> getmessage_subject() {
        return model;
    }
};

#endif
