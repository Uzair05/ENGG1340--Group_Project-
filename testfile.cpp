#include <iostream>
#include <string>
#include "TableTop.h" /*the double quotation marks makes it serach for header
from within the same directory*/
using namespace std;


int main(){
  table deli[15]={};
  deli[0].ID = "Mine";
  deli[0].NumberOfSeats=15;
  deli[0].Occupied=true;

  cout<<deli[0].ID<<endl;

  return 0;
}
