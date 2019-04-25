#include <iostream>
#include <string>
#include "Reservation.h"
#include <sstream>
using namespace std;

int time::ConvertTimeInput(string time){
  istringstream time;
  int time=0;
  int hours,minutes;
  getline(time,hours,':');
  getline(time,minutes,':');
  time=hours+(minutes*60);
  return time;
}
string time::ConvertInputTime(int time){
  string hours,minutes;
  hours=to_string(time/60);
  minutes=to_string(time%60);
  string reslt;
  reslt=hours+":"+minutes;
  return reslt;
}
