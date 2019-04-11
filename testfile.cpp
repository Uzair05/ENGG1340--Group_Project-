#include <iostream>
#include <string>
#include "RestaurantTables.h" /*the double quotation marks makes it serach for header
from within the same directory*/
using namespace std;


int main(){
  RTables FamilyDeli[20];


  /*temporary expo*/
  string id;
  int NumTables;
  bool isOccupied;

  cin>>id>>NumTables>>isOccupied;
  FamilyDeli[14].setID(id);
  FamilyDeli[14].setNofSeats(NumTables);
  FamilyDeli[14].setOccupied(false);
  FamilyDeli[14].toggleOccupied();

  cout<<FamilyDeli[14].getID()<<endl;
  cout<<FamilyDeli[14].getNofSeats()<<endl;
  cout<<FamilyDeli[14].getIsOccupied()<<endl;
  /*temporary expo*/


  return 0;
}
