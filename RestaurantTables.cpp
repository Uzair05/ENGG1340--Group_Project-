#include <iostream>
#include <iomanip>
#include <string>
#include "TableTop.h"
#include "RestaurantTables.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

const string FileName = "TableStore.txt";
const string NumberOfTables = "NumberOfTables.txt";




void alert(string message,string head){
  /*handles the alerts*/
  cout<<"\a........................................"<<endl;
  /*separator*/
  cout<<head<<endl;
  /*Topic of message; also acts as a debugging tool*/
  cout<<message<<endl;
  /*actual message body*/
  cout<<"\a........................................"<<endl;
}

string RTables::getID(){
  return tab.ID;}

int RTables::getNofSeats(){
  return tab.NumberOfSeats;}

bool RTables::getIsOccupied(){
  return tab.Occupied;}

void RTables::setID(string s){
  tab.ID=s;}

void RTables::setNofSeats(int n){
  tab.NumberOfSeats=n;}

void RTables::toggleOccupied(){
  tab.Occupied=(!(tab.Occupied));}

void RTables::setOccupied(bool b){
  tab.Occupied=b;}

int Functions::getsize(){
  int temp=0;
  ifstream mop;
  mop.open(NumberOfTables.c_str());
  if (mop.fail()){
    alert("File could not be opened","Table Load");
    exit(1);
  }else{
    mop>>temp;}
  mop.close();
  return temp;}

void Functions::LoadTables(RTables a[]){
  int size = getsize();
  string temp="";
  string value1="";
  int value2=0;

  ifstream foil;
  foil.open(FileName.c_str());

  if (foil.fail()){
    alert("File could not be opened","Table Load");
    exit(1);}
  for(int i=0;i<size;i++){
    foil>>value1;
    foil>>value2;
    a[i].setID(value1);
    a[i].setNofSeats(value2);
    a[i].setOccupied(false);}
  foil.close();}

void Functions::ReSetTables(){
string value1="";
int value2=0;
int i=0;
int num=0;

ofstream foil;
foil.open(FileName.c_str());
if (foil.fail()){
  alert("File could not be opened","Table ReSet");
  exit(1);
}else{
  system("clear");
  cout<<"How many tables do you want to enter?"<<endl;
  cin>>num;
  system("clear");
  for(int i=0;i<num;++i){
    cout<<"Table ID: "<<setfill('0')<<setw(3)<<i;
    value1<<to_string(i);
    cout<<"enter number of seats of table:\t";
    cin>>value2;
    foil<<value1<<" ";
    foil<<setfill('0')<<setw(3)<<value2<<endl;
  }
  system("clear");
}
foil.close();
ofstream foi;
foi.open(NumberOfTables.c_str());
if (foi.fail()){
  alert("File could not be opened","Table ReSet");
  exit(1);
}else{
  foi<<num;
}
foi.close();
}


string Functions::recommend(RTables a[],int NumberofGuests, int size/*holds the total number of tables*/){
  struct MoodyJazz{
    string ID="";
    int seat=0;
  };
  MoodyJazz *pop = new MoodyJazz[size];
  bool flag=false;
  for(int i=0;i<size;++i){
    if ((a[i].getNofSeats()==NumberofGuests)&&(!(a[i].getIsOccupied()))){
      flag=true;
      return a[i].getID();
      break;
    }
}
  int count=0;
  if (!(flag)){
    for(int i=0;i<size;++i){
      if ((a[i].getNofSeats()>=NumberofGuests)&&(!(a[i].getIsOccupied()))){
        pop[count].ID=a[i].getID();
        pop[count].seat=a[i].getNofSeats();
        count+=1;
      }
    }
  }
  if (count==0){
    return "NoTables";
  }else{
    MoodyJazz lowest;
    lowest.ID=pop[0].ID;
    lowest.seat=pop[0].seat;
    for(int i=1;i<count;i++){
      if ((lowest.seat>pop[i].seat)&&(pop[i].seat!=0)){
        lowest.ID=pop[i].ID;
        lowest.seat=pop[i].seat;
      }
    }
    return lowest.ID;
  }
  delete[] pop;
}


void Functions::OccupyTable(RTables a[],string ID, int size){
  bool failflag=true;
  for(int i=0;i<size;++i){
    if (a[i].getID()==ID){
      failflag=false;
      if (!(a[i].getIsOccupied())){
        a[i].setOccupied(true);
        alert("Table has been occupied","OccupyTable");
        break;
      }else{
        alert("Table is currently occupied","OccupyTable");
        break;
      }
    }
  }
  if (failflag){
    alert("No such table available at this moment","OccupyTable");
  }
}

void Functions::ReleaseTable(RTables a[],string ID, int size){
  bool failflag=true;
  for(int i=0;i<size;++i){
    if (a[i].getID()==ID){
      failflag=false;
      if (a[i].getIsOccupied()){
        a[i].toggleOccupied();
        alert("Table has been released","ReleaseTable");
        break;
      }else{
        alert("Table is not Occupied","ReleaseTable");
        break;
      }
    }
  }
  if (failflag){
    alert("No such table available at this moment","ReleaseTable");
  }
}

bool Functions::CheckAvailability(RTables a[],string ID, int size){
  bool flag=false;
  for(int i=0;i<size;++i){
    if ((a[i].getID()==ID)&&(!(a[i].getIsOccupied()))){
      flag=true;
    }
  }
  return flag;
}
