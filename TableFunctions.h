#ifndef TFunctions_H
#define TFunctions_H

#include <iostream>
#include <string>
#include "RestaurantTables.h"
#include "alert_aid.h"
using namespace std;

void OccupyTable(RTables a[],string ID, int size){
  bool failflag=true;
  for(int i=0;i<size;++i){
    if (a[i].getID()==ID){
      failflag=false;
      if (!(a[i].getIsOccupied())){
        a[i].setOccupied(true);
        alert("Table has been occupied","OccupyTable");
        break;
      }else{
        alert("Table is currently occupied","OccupyTable");
        break;
      }
    }
  }
  if (failflag){
    alert("No such table available at this moment","OccupyTable");
  }
}

void ReleaseTable(RTables a[],string ID, int size){
  bool failflag=true;
  for(int i=0;i<size;++i){
    if (a[i].getID()==ID){
      failflag=false;
      if (a[i].getIsOccupied()){
        a[i].toggleOccupied();
        alert("Table has been released","ReleaseTable");
        break;
      }else{
        alert("Table is not Occupied","ReleaseTable");
        break;
      }
    }
  }
  if (failflag){
    alert("No such table available at this moment","ReleaseTable");
  }
}

bool CheckAvailability(RTables a[],string ID, int size){
  bool flag=false;
  for(int i=0;i<size;++i){
    if ((a[i].getID()==ID)&&(!(a[i].getIsOccupied()))){
      flag=true;
    }
  }
  return flag;
}


#endif
