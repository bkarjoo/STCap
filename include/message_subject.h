#ifndef MESSAGE_SUBJECT_H_
#define MESSAGE_SUBJECT_H_

#include <memory>
#include <vector>
#include <message.h>

using std::vector;
using std::shared_ptr;

class message_subject {

    vector < class message_observer * > views;

  public:
    void attach(message_observer *obs) {
        views.push_back(obs);
    }

    void notify(shared_ptr<message>);
};

#endif
