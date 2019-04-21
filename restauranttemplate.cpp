#include <iostream>
#include <string>

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
  PresentOption();


  return 0;
}
