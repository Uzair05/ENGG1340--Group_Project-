#ifndef RTables_H
#define RTables_H

#include <string>
#include "TableTop.h"

using namespace std;

class RTables{
private:
  table tab;
public:
  string getID(){
    return tab.ID;
  }
  int getNofSeats(){
    return tab.NumberOfSeats;
  }
  bool getIsOccupied(){
    return tab.Occupied;
  }
  void setID(string s){
    tab.ID=s;
  }
  void setNofSeats(int n){
    tab.NumberOfSeats=n;
  }
  void toggleOccupied(){
    tab.Occupied=(!(tab.Occupied));
  }
  void setOccupied(bool b){
    tab.Occupied=b;
  }
};

#endif
