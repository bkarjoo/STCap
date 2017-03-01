#include "message_subject.h"
#include "message_observer.h"

void message_subject::notify(shared_ptr<message> msg) {
  // 5. Publisher broadcasts
  for (int i = 0; i < views.size(); i++)
    views[i]->update(msg);
}
