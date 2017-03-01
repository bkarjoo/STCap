#include <iostream>
#include <memory>

using std::cout;
using std::shared_ptr;

class Modmessage_observer: public message_observer {
  public:
    Modmessage_observer(shared_ptr<message_subject> mod): message_observer(mod){}
    void update(shared_ptr<message>) {

    }
};
