#ifndef RTables_H
#define RTables_H

#include <string>
#include "TableTop.h"

using namespace std;

class RTables{
private:
  table tab;
public:
  string getID();
  int getNofSeats();
  bool getIsOccupied()
  void setID(string s);
  void setNofSeats(int n);
  void toggleOccupied();
  void setOccupied(bool b);

};

class Functions{
public:
  void LoadTables(RTables a[]);
  int getsize();
  void ReSetTables();
  string recommend(RTables a[],int NumberofGuests, int size);
  void OccupyTable(RTables a[],string ID, int size);
  void ReleaseTable(RTables a[],string ID, int size);
  bool CheckAvailability(RTables a[],string ID, int size);
};

#endif
