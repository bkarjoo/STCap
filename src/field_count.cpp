#include "field_count.h"

void field_count::update(shared_ptr<message> mp)
{
  count += mp->get_fields().size();
}
