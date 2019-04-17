#ifndef RTables_H
#define RTables_H

#include <string>
#include "TableTop.h"

using namespace std;

class RTables{
private:
  table tab[20];
public:
  string getID(int tablenumber){
    return tab[tablenumber].ID;
  }
  int getNofSeats(int tablenumber){
    return tab[tablenumber].NumberOfSeats;
  }
  bool getIsOccupied(int tablenumber){
    return tab[tablenumber].Occupied;
  }
  void setID(int tablenumber,string s){
    tab[tablenumber].ID=s;
  }
  void setNofSeats(int tablenumber,int n){
    tab[tablenumber].NumberOfSeats=n;
  }
  void toggleOccupied(int tablenumber){
    tab[tablenumber].Occupied=(!(tab[tablenumber].Occupied));
  }
  void setOccupied(int tablenumber,bool b){
    tab[tablenumber].Occupied=b;
  }
};

#endif
