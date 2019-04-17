#include <iostream>
#include <windows.h>

using namespace std;

int main(){
  cout<<"\a";
  ::MessageBox(NULL,"Occupied","Vacancy",MB_OK);

  return 0;
}
