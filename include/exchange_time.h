#ifndef EXCHANGE_TIME_H_
#define EXCHANGE_TIME_H_

#include <string>

using std::string;

class exchange_time {
public:
  void set(string timestamp);
  unsigned short int get_milliseconds() { return milliseconds; }
  unsigned short int get_seconds() { return seconds; }
  unsigned short int get_minutes() { return minutes; }
  unsigned short int get_hours() { return hours; }
  double seconds_from_midnight() const;
  bool operator<(const exchange_time& other) const;
  bool operator>(const exchange_time& other) const;
  bool operator==(const exchange_time& other) const;
private:
  unsigned short int milliseconds;
  unsigned short int seconds;
  unsigned short int minutes;
  unsigned short int hours;
};

#endif
