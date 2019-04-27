#include <iostream>
#include <string>
#include "RestaurantTables.h"
#include "Reservation.h"
#include "billing.h"


using namespace std;

int PresentOption()
{
  int choice;
  system("clear");
  cout<<"Enter A Single Digit Option"<<endl;
  cout<<"1. Find A Suitable Table"<<endl;
  cout<<"2. Book A Table"<<endl;
  cout<<"3. Release A Booking"<<endl;
  cout<<"4. Occupy A Table"<<endl;
  cout<<"5. Release A Table"<<endl;
  cout<<"6. Check for Overtime"<<endl;
  cout<<"9. Exit"<<endl;
  cin>>choice;
  return choice;
}


int main()
{
  cout<<"Do you wish to Make Seasonal Rarrangement of Tables (Y/N)"<<endl;
  char a;
  cin>>a;

  Functions deli;



  if (a=='Y')
  {
    deli.ReSetTables();
  }
  else if (a=='N')
  {
    int choice;
    choice = PresentOption();
    RTables* table = new RTables[deli.getsize()];
    deli.LoadTables(table);

    string TableIdentity,Time;
    int NumberofGuests;
    int mob


    switch(choice)
    {
      case 1:
      cout<<"Please enter number of guests"<<endl;
      cin>>NumberOfGuests;
      cout<<"Please enter booking time"<<endl;
      cin>>Time;
      cout<<"Recommended Table: "<<deli.recommend(table,NumberofGuests,Time)<<endl;
      break;
      case 2:
      cout<<"Please enter number of guests"<<endl;
      cin>>NumberOfGuests;
      cout<<"Please enter booking time"<<endl;
      cin>>Time;
      deli.BOOK(table,NumberOfGuests,Time);
      break;
      case 3:
      mob=true;
      do{
        cout<<"please enter table ID"<<endl;
        cin>>TableIdentity;
        if (!(mob)){
          cout<<"Error: ID not found, please enter valid ID"<<endl;
        }
        mob=false;
        for(int i=0;i<deli.getsize();i++){
          if (table[i].getID()==TableIdentity){
            mob=true;
          }
        }
      }while(!(mob));
      cout<<"Please Enter Time"<<endl;
      cin>>Time;
      deli.CANCELBooking(TableIdentity,Time);
      break;
      case 4:
      mob=true;
      do{
        cout<<"please enter table ID"<<endl;
        cin>>TableIdentity;
        if (!(mob)){
          cout<<"Error: ID not found, please enter valid ID"<<endl;
        }
        mob=false;
        for(int i=0;i<deli.getsize();i++){
          if (table[i].getID()==TableIdentity){
            mob=true;
          }
        }
      }while(!(mob));
      deli.OccupyTable(table,TableIdentity);
      break;
      case 5:
      mob=true;
      do{
        cout<<"please enter table ID"<<endl;
        cin>>TableIdentity;
        if (!(mob)){
          cout<<"Error: ID not found, please enter valid ID"<<endl;
        }
        mob=false;
        for(int i=0;i<deli.getsize();i++){
          if (table[i].getID()==TableIdentity){
            mob=true;
          }
        }
      }while(!(mob));
      deli.ReleaseTable(table,TableIdentity);
      break;
      case 6:
      cout<<"Please Enter Current time (HH:MM)"<<endl;
      cin>>Time;
      deli.CheckOverTime(Time);
      break;


    }
    delete[] table;
  }

}
