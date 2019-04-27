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
  bool getIsOccupied();
  void setID(string s);
  void setNofSeats(int n);
  void toggleOccupied();
  void setOccupied(bool b);

};

class Functions{
public:
  int getsize();
  void LoadTables(RTables a[]);
  void ReSetTables();
  string recommend(RTables a[],int NumberofGuests,string tim /*for time*/ );
  void OccupyTable(RTables a[],string ID,string tim);
  void ReleaseTable(RTables a[],string ID);
  bool CheckAvailability(RTables a[],string ID);
  void BOOK(RTables a[],int NumberofGuests,string tim /*for time*/ );
  void CANCELBooking(string ID,string tim /*for time*/ );
  bool OverTime(string tim);
};

#endif
