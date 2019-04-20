#include <iostream>
#include <string>
#include "RestaurantTables.h" /*the double quotation marks makes it serach for header
from within the same directory*/
#include "TableFunctions.h"
using namespace std;


int main(){
  RTables FDeli[20];


  /*temporary expo*/
  string id="stove";
  int NumTables;
  bool isOccupied;

  /*set up*/

  for(int i=0;i<20;++i){
    FDeli[i].setID(id);
    FDeli[i].setNofSeats(i);
    FDeli[i].setOccupied(false);
  }

  ReleaseTable(FDeli,"stove",20);
  cout<<FDeli[13].getID()<<" "<<FDeli[13].getNofSeats()<<endl;



  /*temporary expo*/


  return 0;
}
