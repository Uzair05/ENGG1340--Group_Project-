#include <iostream>
#include <string>
#include "RestaurantTables.h"


using namespace std;

void PresentOption(){
  system("CLR");
  cout<<"Enter A Single Digit Option"<<endl;
  cout<<"1. Load Tables From Database"<<endl;
  cout<<"2. Seasonal Rarrangement of Tables"<<endl;
  cout<<"3. Find A Suitable Table"<<endl;
  cout<<"4. Book A Table"<<endl;
  cout<<"5. Release A Booking"<<endl;
  cout<<"6. Occupy A Table"<<endl;
  cout<<"7. Append Billing of Table"<<endl; /*To work on*/
  cout<<"8. Print Bill of table"<<endl; /*To work on*/
  cout<<"9. Plot out Monthly success of Dishes"<<endl; /*To work on*/
  cout<<"10. Exit"<<endl;
}


int main(){

Functions deli;
deli.ReSetTables();
RTables* a = new RTables[deli.getsize()];

deli.LoadTables(a);

int guest;
cout<<"How many guest do you expect?"<<endl;
cin>>guest;

string suggest=deli.recommend(a,guest,deli.getsize());

cout<<suggest<<endl;

deli.OccupyTable(a,suggest,deli.getsize());

cout<<a[1].getIsOccupied()<<endl<<endl;

deli.ReleaseTable(a,suggest,deli.getsize());
cout<<a[1].getIsOccupied()<<endl;

delete[] a;
  return 0;
}
