#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Reservation.h"
using namespace std;


int time::ConvertTimeInput(string tim){
  string hours,minutes;
  hours=tim.substr(0,2);
  minutes=tim.substr(3,2);
  int rslt;
  rslt=(stoi(hours)*60)+stoi(minutes);
  return rslt;
}
string time::ConvertInputTime(int tim){
  string hours,minutes;
  hours=to_string(tim/60);
  minutes=to_string(tim%60);
  string reslt;
  reslt=hours+":"+minutes;
  return reslt;
}

void time::SetBooking(string ID,string tim){
  ofstream foi;
  foi.open("Bookings.txt",ios::app);
  if (foi.fail()){
    system("clear");
    cout<<"\aUnable to access Bookings.txt"<<endl;
    exit(1);
  }else{
    foi<<ID<<" "<<tim<<endl;
    foi.close();
  }
}
