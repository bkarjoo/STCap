#include "exchange_time.h"

using std::stoi;

void exchange_time::set(string timestamp)
{
    char ms1, ms2, ms3, s1, s2, m1, m2, h1 = 0, h2;
    if (timestamp.length() > 2) {
    ms3 = timestamp.back();
    timestamp.erase(timestamp.end()-1,timestamp.end());
    ms2 = timestamp.back();
    timestamp.erase(timestamp.end()-1,timestamp.end());
    ms1 = timestamp.back();
    timestamp.erase(timestamp.end()-1,timestamp.end());
      if (timestamp.length() > 1) {
        s2 = timestamp.back();
        timestamp.erase(timestamp.end()-1,timestamp.end());
        s1 = timestamp.back();
        timestamp.erase(timestamp.end()-1,timestamp.end());
        if (timestamp.length() > 1) {
          m2 = timestamp.back();
          timestamp.erase(timestamp.end()-1,timestamp.end());
          m1 = timestamp.back();
          timestamp.erase(timestamp.end()-1,timestamp.end());
          if (timestamp.length() > 0) {
            h2 = timestamp.back();
            timestamp.erase(timestamp.end()-1,timestamp.end());
            if (timestamp.length() > 0) {
              h1 = timestamp.back();
              timestamp.erase(timestamp.end()-1,timestamp.end());
            }
            string ms = ""; ms += ms1; ms += ms2; ms += ms3;
            milliseconds = stoi(ms);
            string s = ""; s+= s1; s += s2;
            seconds = stoi(s);
            string m = ""; m += m1; m += m2;
            minutes = stoi(m);
            string h = ""; if (h1 != 0) h += h1; h += h2;
            hours = stoi(h);
          }
        }
      }
    }
}

double exchange_time::seconds_from_midnight() const {
  return seconds + minutes * 60.0 + hours * 3600.0 + milliseconds / 1000.0;
}

bool exchange_time::operator<(const exchange_time& other) const
{
  return seconds_from_midnight() < other.seconds_from_midnight();
}

bool exchange_time::operator>(const exchange_time& other) const
{
  return seconds_from_midnight() > other.seconds_from_midnight();
}

bool exchange_time::operator==(const exchange_time& other) const
{
  return seconds_from_midnight() - other.seconds_from_midnight() < .00001;
}
