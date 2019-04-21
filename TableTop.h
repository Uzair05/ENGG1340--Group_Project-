#ifndef TableTop_H
#define TableTop_H

#include <iostream>
#include <string>
using namespace std;

struct table
{
  std::string ID="";
  int NumberOfSeats=0;
  bool Occupied=false;
  string BookingTime;
  string SittingTime;
  string Customer;
};

#endif
