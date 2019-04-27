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
  cout<<"7. Billing and Ordering Management"<<endl;
  cout<<"8. Exit"<<endl;
  cin>>choice;
  return choice;
}


int main()
{
  cout<<"Do you wish to Make Seasonal Rarrangement of Tables (Y/N)"<<endl;
  char a;
  cin>>a;

  Functions deli;
  Billing bill;


  if (a=='Y')
  {
    deli.ReSetTables();
    cout<<"Seasonal Arrangment Successful"<<endl;
    cout<<"Please Restart the program\n"<<endl;
    cout<<"Press any button to exit (random character)"<<endl;
    cin>>wait; /*Allows wait for user to see*/

  }
  else if (a=='N')
  {
    int choice;
    char wait;
    RTables* table = new RTables[deli.getsize()];
    deli.LoadTables(table);

    string TableIdentity,Time;
    int NumberofGuests;
    bool mob;
    string tableid;


    do{
    choice = PresentOption();
    switch (choice)
    {
      case 1:
      cout<<"Please enter number of guests"<<endl;
      cin>>NumberofGuests;
      cout<<"Please enter booking time"<<endl;
      cin>>Time;
      cout<<"Recommended Table: "<<deli.recommend(table,NumberofGuests,Time)<<endl;
      cout<<"Press any button to exit (random character)"<<endl;
      cin>>wait; /*Allows wait for user to see*/
      break;
      case 2:
      cout<<"Please enter number of guests"<<endl;
      cin>>NumberofGuests;
      cout<<"Please Enter Time of Booking in HH:MM 24 hour format"<<endl;
      cin>>Time;
      deli.BOOK(table,NumberofGuests,Time);
      break;
      case 3:
      cout<<"please enter table ID"<<endl;
      cin>>TableIdentity;
      cout<<"Please Enter Time of Booking in HH:MM 24 hour format"<<endl;
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
      cout<<"Please Enter Time of Booking in HH:MM 24 hour format"<<endl;
      cin>>Time;
      deli.OccupyTable(table,TableIdentity,Time);
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
      cout<<"Please Enter Current Time in HH:MM 24 hour format"<<endl;
      cin>>Time;
      deli.OverTime(Time);
      break;
      case 7:
      system("clear");

      do
      {
        cout<<"Please enter a table ID"<<endl;
        cin>>tableid;
        for(int i=0;i<deli.getsize();i++)
        {
          if (table[i].getID()==tableid)
          {
            mob=false;
          }
        }
      }while(mob);
      if(mob==false)
      bill.Control(tableid);
      break;

      default:
      break;

    }
  }while((choice<=7)&&(choice>=1));
  delete[] table;
  }

}
