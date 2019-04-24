#include <iostream>
#include <string>
#include "RestaurantTables.h"
#include "TableFunctions.h"

#include "RecommendTable.h"/*bit of unique*/
#include "TableHandle.h" /*
i cant incorporate it into TableFunctions,
so it'll have to stay here in the
main program*/

using namespace std;

void PresentOption()
{
  system("CLR");
  cout<<endl;
  cout<<"Enter A Single Digit Option"<<endl;
  cout<<endl;
  cout<<"1. Load Tables From Database"<<endl;
  cout<<"2. Seasonal Rarrangement of Tables"<<endl;
  cout<<"3. Find A Suitable Table"<<endl;
  cout<<"4. Book A Table"<<endl;
  cout<<"5. Release A Booking"<<endl;
  cout<<"6. Occupy A Table"<<endl;
  cout<<"7. Append Billing of Table"<<endl; /*To work on*/
  cout<<"8. Print Bill of table"<<endl; /*To work on*/
  cout<<"9. Plot out Monthly success of Dishes"<<endl; /*To work on*/
  cout<<"10. Exit"<<endl<<endl;
  cout<<"******************************************"<<endl;
}


int main()
{
  bool CreateFlag=false;

  //cout<<recommend(a,5,getsize())<<endl;

  int command=0;
  do
  {

    PresentOption();
    cin>>command;

    switch(command)
    {
      case(1):
      RTables* a = new RTables[getsize()];
      CreateFlag=true;
      LoadTables(a);
      break;

      case(2):
      ReSetTables();
      break;

      case(3):
      RecommendTable();
      break;

      case(4):
      OccupyTable();
      break;

      case(5):
      ReleaseTable()
      break;

      case(10):
      cout<<"Exit has been triggered"<<endl;
      if (CreateFlag)
      {
        delete[] a;
      }
      break;

      default:
      cout<<"Incorrect Command"<<endl;
      break;
    }

  }while(command!=10);



  return 0;
}
