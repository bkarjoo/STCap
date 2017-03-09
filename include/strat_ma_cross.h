#ifndef STRAT_MA_CROSS_
#define STRAT_MA_CROSS_
#include "strategy.h"

class strat_ma_cross : public strategy {
  // if backtesting enabled and receiving data strategy will generate executions
  bool enable_backtesting = false;
  bool entry();
  bool target();
  bool stop();
};

#endif
