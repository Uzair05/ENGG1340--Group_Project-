#include <iostream>
#include <string>
#include "RestaurantTables.h"
#include "TableFunctions.h"

#include "TableHandle.h"

using namespace std;


int main(){

  RTables* a = new RTables[getsize()];
  LoadTables(a);

  cout<<a[2].getID()<<endl;

  delete[] a;
  return 0;
}
