#include <iostream>
#include <iomanip>
#include <string>
#include "TableTop.h"
#include "RestaurantTables.h"
#include "Reservation.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

const string FileName = "TableStore.txt";
const string NumberOfTables = "NumberOfTables.txt";

Timer rsrv;


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
string value2="";
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
    cout<<"Enter Table ID [three characters long]"<<endl;
    cin>>value1;
    if (value1.length()>3){
      value1=value1.substr(0,3);
    }
    cout<<"Enter number of seats of table:\t";
    cin>>value2;
    foil<<value1<<" ";
    foil<<value2<<endl;
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


string Functions::recommend(RTables a[],int NumberofGuests, string tim /*The time the guest wishes to book*/ ){
  string rslt="";
  int size = getsize();
  struct MoodyJazz{
    string ID="";
    int seat=0;
  };
  MoodyJazz *pop = new MoodyJazz[size];
  bool flag=false;
  for(int i=0;i<size;++i){
    if (((a[i].getNofSeats()==NumberofGuests)&&(!(a[i].getIsOccupied())))&&(rsrv.FindTime(a[i].getID(),tim))){
      flag=true;
      rslt=a[i].getID();
      break;
    }
}
  int count=0;
  if (!(flag)){
    for(int i=0;i<size;++i){
      if ((a[i].getNofSeats()>=NumberofGuests)&&(!(a[i].getIsOccupied()))&&(rsrv.FindTime(a[i].getID(),tim))){
        pop[count].ID=a[i].getID();
        pop[count].seat=a[i].getNofSeats();
        count+=1;

      }
    }
  }
  if (count==0){
    return "NoTable"; /*exit clause*/
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
    rslt=lowest.ID;
  }

  delete[] pop;
  return rslt;
}


void Functions::OccupyTable(RTables a[],string ID, string tim /*time table was booked for*/){
  /*assumes table was occupied on time*/
  int size = getsize();
  bool failflag=true;
  for(int i=0;i<size;++i){
    if (a[i].getID()==ID){
      failflag=false;
      if (!(a[i].getIsOccupied())){
        a[i].setOccupied(true);
        /*when a table is seated then it is removed from the bookings*/
        rsrv.CancelBooking(a[i].getID(),tim);
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

void Functions::ReleaseTable(RTables a[],string ID){
  int size = getsize();
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

bool Functions::CheckAvailability(RTables a[],string ID){
  int size=getsize();
  bool flag=false;
  for(int i=0;i<size;++i){
    if ((a[i].getID()==ID)&&(!(a[i].getIsOccupied()))){
      flag=true;
    }
  }
  return flag;
}

void Functions::BOOK(RTables a[],int NumberofGuests,string tim /*for time*/ ){
  int time = rsrv.ConvertTimeInput(tim);
  --time;
  string TableID="";
  do{
    time++;
    TableID=recommend(a,NumberofGuests,rsrv.ConvertInputTime(time));
  }while((TableID=="NoTable")&&(time<=rsrv.ConvertTimeInput("23:59")));
  cout<<"Do you wish to book table: "<<TableID<<" at "<<rsrv.ConvertInputTime(time)<<" (Y/N)"<<endl;
  char choice;
  cin>>choice;
  if (choice=='Y'){
    rsrv.SetBooking(TableID,rsrv.ConvertInputTime(time));
  }
}
void Functions::CANCELBooking(string ID,string tim /*for time*/ ){
  rsrv.CancelBooking(ID,tim);
}

void Functions::OverTime(string tim){
  rsrv.CheckOverTime(tim);
}
