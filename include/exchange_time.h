#ifndef EXCHANGE_TIME_H_
#define EXCHANGE_TIME_H_
#include <exception>
#include <string>

class invalid_time_format: public std::exception
{
  virtual const char* what() const throw()
  {
    return "8-9 character time format expected: (h)hmmsslll : hours,minutes,seconds,milliseconds.";
  }
};

class exchange_time {
public:
  exchange_time() {}
  exchange_time(const std::string&);
  void set_time(const std::string& theTime);
  unsigned short int get_milliseconds() const { return milliseconds; }
  unsigned short int get_seconds() const  { return seconds; }
  unsigned short int get_minutes() const  { return minutes; }
  unsigned short int get_hours() const  { return hours; }
  double get_seconds_from_midnight() const { return seconds_from_midnight; }
  bool operator<(const exchange_time& other) const;
  bool operator>(const exchange_time& other) const;
  bool operator==(const exchange_time& other) const;
private:
  std::string time_str ="";
  unsigned short int milliseconds = 0;
  unsigned short int seconds = 0;
  unsigned short int minutes = 0;
  unsigned short int hours = 0;
  double seconds_from_midnight = 0.0;
  double to_secs_from_midnight(const std::string&);
};

#endif
