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
  //cout<<"1. Load Tables From Database"<<endl;
  //cout<<"2. Seasonal Rarrangement of Tables"<<endl;
  cout<<"1. Find A Suitable Table"<<endl;
  cout<<"2. Book A Table"<<endl;
  cout<<"3. Release A Booking"<<endl;
  cout<<"4. Occupy A Table"<<endl;
  cout<<"5. Release A Table"<<endl;
  cout<<"6. Billing and Ordering Management"<<endl;
  cout<<"7. Exit"<<endl;
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
  }
  else if (a=='N')
  {
    int choice;
    choice = PresentOption();
    RTables* table = new RTables[deli.getsize()];
    deli.LoadTables(table);
    switch(choice)
    {
        case 6:
        {
          string tableid;
          system("clear");
          bool mob = true;
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
        }

        case 7:
        {
            cout<<"Exited successfully"<<endl<<endl;
            exit(0);
        }
    }
    delete[] table;
  }

}
