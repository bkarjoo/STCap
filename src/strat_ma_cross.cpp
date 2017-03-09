#include "strat_ma_cross.h"

bool strat_ma_cross::entry() {
  if (ask - bid < .05)
  {
    if (ask_size > 10 && bid_size > 5) {}
    if (last > 5 && last_size > 100) {}
  }
}

bool strat_ma_cross::target() {

}

bool strat_ma_cross::stop() {

}
