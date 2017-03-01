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
};

#endif
