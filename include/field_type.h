
/*
 * jk // j best_bid_size k DirectEdge x
 * kb // k ask_size b NASDAQ BX
 * kt // k ask_size t NASDAQ Regional
 * kz // k ask_size z NASDAQ BATS
 * -f12 session volume - int
 * -f15 activity_date
 * -f16 activity_time
 * -f26 quote_date
 * -f27 quote_time
 * f28 VWAP
 * -f32 unique_trade_id
 * f77 trade_condition_size - int
 * f78 trade_condition_price - int preceded by precision (f?)
 * f79 trade_condition_type, SCond bate type,
       0 regular_trade
       9 odd_lot_trade
 * -f86 trade_through_exempt
 * -f87 original_trade_trade_through_exempt - 1 means exempt 0 means not exempt
 * g54 extended_trade_condition
       0 - regular_trade
       9 - odd_lot_trade
 * g77 time_stamp
 * g97 trade_part_open -
 * g99 exchange_sequence - useful for consolidating tapes in pair strategies
 * i trade_size
 * -c change
 * t trade
 * -v trade_volume (followed by '-') cumulative - int more than session

 */
enum class field_type {
  undefined,
  activity_date,
  activity_time,
  time_stamp,
  exchange_sequence
};
