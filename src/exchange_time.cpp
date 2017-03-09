#include "exchange_time.h"
#include <iostream>
using std::cout; using std::endl;

using std::stoi;
using std::string;



exchange_time::exchange_time(const string& theTime)
{
  seconds_from_midnight = to_secs_from_midnight(theTime);
}

void exchange_time::set_time(const string& theTime)
{
  seconds_from_midnight = to_secs_from_midnight(theTime);
}

double exchange_time::to_secs_from_midnight(const string& t)  {
  // time must at least be 8 characters long
  // (h)hmmsslll hours,minutes,seconds,milliseconds
  if (t.length() < 8) throw invalid_time_format();
  try {
    string ms = "";
    ms += t[t.length() - 3]; ms += t[t.length() - 2]; ms += t[t.length() - 1];
    milliseconds = stoi(ms);
    string s = "";
    s += t[t.length() - 5]; s += t[t.length() - 4];
    seconds = stoi(s);
    string m = "";
    m += t[t.length() - 7]; m += t[t.length() - 6];
    minutes = stoi(m);
    string h = "";
    if (t.length() == 9) h += t[t.length() - 9];
    h += t[t.length() - 8];
    hours = stoi(h);
    return seconds + minutes * 60.0 + hours * 3600.0 + milliseconds / 1000.0;
  } catch (...) {
    throw invalid_time_format();
    return 0.0;
  }
}


bool exchange_time::operator<(const exchange_time& other) const
{
  return get_seconds_from_midnight() < other.get_seconds_from_midnight();
}

bool exchange_time::operator>(const exchange_time& other) const
{
  return get_seconds_from_midnight() > other.get_seconds_from_midnight();
}

bool exchange_time::operator==(const exchange_time& other) const
{
  return get_seconds_from_midnight() - other.get_seconds_from_midnight() < .00001;
}
