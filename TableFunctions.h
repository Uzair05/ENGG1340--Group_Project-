#ifndef RTables_H
#define RTables_H

#include <iostream>
#include <string>
#include "RestaurantTables.h"
#include "TableTop.h"

using namespace std;

void RTables::OccupyTable()
{
  string id;
  int tablenumber;

  cin>>id;//inputting table id
  cin>>tablenumber;//inputting table number; table numbers start with 0

  setID(tablenumber,id);//setting table id as inputted id

  if(getNofSeats(getID)<=setNofSeats && getIsOccupied(getID)==0) //if number of seats required is less than or equal to the seats of that table and if it is not occupied.
  tab[tablenumber].Occupied=true; //set occupied to true if table is available

  else

  AlertBox("No such table available at this moment");
  //give an alert if table is not available
}

void RTables::ReleaseTable()
{
  int tablenumber;
  cin>>tablenumber;//inputting table number; table numbers start with 0

  tab[tablenumber].Occupied=false; //setting occupied counter to 0 to release table

}

int RTables::CheckAvailability()
{
  int tablenumber;//inputting table number; table numbers start with 0
  cin>>tablenumber;

  if (tab[tablenumber].Occupied==false)
  return 0; //if table is not occupied.

  return 1; //if table is occupied.
}

#endif
