#include <iostream>
#include <memory>
#include "message_observer.h"

using std::cout;
using std::shared_ptr;

class Divmessage_observer: public message_observer {
  public:
    Divmessage_observer(shared_ptr<message_subject> mod): message_observer(mod){}
    void update(shared_ptr<message>) {

    }
};
