#include <iostream>
#include <string>
#include "RestaurantTables.h"
#include "TableFunctions.h"
#include "RecommendTable.h"

#include "TableHandle.h"

using namespace std;


int main(){
  ReSetTables();
  RTables* a = new RTables[getsize()];
  LoadTables(a);

  cout<<recommend(a,5,getsize())<<endl;



  delete[] a;
  return 0;
}
