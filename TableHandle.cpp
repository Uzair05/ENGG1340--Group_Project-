#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "RestaurantTables.h"
#include "alert_aid.h"
using namespace std;

const string FileName = "TableStore.txt";
const string NumberOfTables = "NumberOfTables.txt";

int getsize()
{
  int temp=0;
  ifstream mop;
  mop.open(NumberOfTables.c_str());
  if (mop.fail())
  {
    alert("File could not be opened","Table Load");
    exit(1);
  }
  else
  {
    mop>>temp;
  }

  mop.close();
  return temp;
}

void LoadTables(RTables a[])
{
  int size = getsize();
  string temp="";
  string value1="";
  int value2=0;

  ifstream foil;
  foil.open(FileName.c_str());

  if (foil.fail())
  {
    alert("File could not be opened","Table Load");
    exit(1);
  }

  for(int i=0;i<size;i++)
  {
    foil>>value1;
    foil>>value2;
    a[i].setID(value1);
    a[i].setNofSeats(value2);
    a[i].setOccupied(false);
  }

  foil.close();

}

void ReSetTables()
{
  string value1="";
  int value2=0;
  int i=0;
  int num=0;

  ofstream foil;
  foil.open(FileName.c_str());
  if (foil.fail())
  {
    alert("File could not be opened","Table ReSet");
    exit(1);
  }
  else
  {
    system("CLS");
    cout<<"How many tables do you want to enter?"<<endl;
    cin>>num;
    system("CLS");
    for(int i=0;i<num;++i){
      cout<<"enter table ID:\t";
      cin>>value1;
      cout<<"enter number of seats of table:\t";
      cin>>value2;
      foil<<value1<<" "<<value2<<endl;
    }
    system("CLS");
  }
  foil.close();
  ofstream foi;
  foi.open(NumberOfTables.c_str());
  if (foi.fail()){
    alert("File could not be opened","Table ReSet");
    exit(1);
  }
  else
  {
    foi<<num;
  }
  foi.close();
}
