#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Reservation.h"
using namespace std;


int Timer::ConvertTimeInput(string tim){
  string hours,minutes;
  hours=tim.substr(0,tim.find(':'));
  minutes=tim.substr((tim.find(':')+1),tim.length());
  int rslt;
  rslt=(stoi(hours)*60)+stoi(minutes);
  return rslt;
}

string Timer::ConvertInputTime(int tim){
  string hours,minutes;
  if ((tim/60)<10){
    hours+="0";
  }
  hours+=to_string(tim/60);
  if ((tim%60)<10){
    minutes+="0";
  }
  minutes+=to_string(tim%60);
  string reslt;
  reslt=hours+":"+minutes;
  return reslt;
}

void Timer::SetBooking(string ID,string tim){
  ofstream foi;
  foi.open("Bookings.txt",ios::app);
  if (foi.fail()){
    system("clear");
    cout<<"\aUnable to access Bookings.txt"<<endl;
    exit(1);
  }else{
    string CustomerName;
    cout<<"Please enter Customer's Last Name [No spaces must be entered]";
    cin>>CustomerName;
    foi<<CustomerName<<" "<<ID<<" "<<tim<<endl;
    foi.close();
  }
}

void Timer::CancelBooking(string ID,string tim){
  ifstream fin;
  string temp;
  string CustomerName;
  string identity,clock;

  ofstream fout;
  fout.open("Temp.txt");
  if (fout.fail()){
    system("clear");
    cout<<"\aUnable to access Temp.txt"<<endl;
    exit(1);
  }

  fin.open("Bookings.txt");
  if (fin.fail()){
    system("clear");
    cout<<"\aUnable to access Bookings.txt"<<endl;
    exit(1);
  }else{

    while(getline(fin,temp)){
      istringstream iss(temp);
      iss>>CustomerName>>identity>>clock;
      if (!((identity==ID)&&(clock==tim))){
        fout<<CustomerName<<" "<<identity<<" "<<clock<<endl;
        /*transfers everything except item to be deleted*/
      }
    }
    fout.close();
    fin.close();

    ifstream foilin;
    ofstream foilout;
    foilin.open("Temp.txt");
    if (foilin.fail()){
      system("clear");
      cout<<"\aUnable to access Temp.txt"<<endl;
      exit(1);
    }
    foilout.open("Bookings.txt");
    if (foilout.fail()){
      system("clear");
      cout<<"\aUnable to access Bookings.txt"<<endl;
      exit(1);
    }
    while(getline(foilin,temp)){
      foilout<<temp<<endl;
      /*transfers everything into original file.*/
    }
    foilin.close();
    foilout.close();
  }
}

void Timer::CheckOverTime(string tim){

  ifstream fin;
  fin.open("Bookings.txt");
  if (fin.fail()){
    system("clear");
    cout<<"\aUnable to access Bookings.txt"<<endl;
    exit(1);
  }

  string identity,clock;
  string temp;
  string CustomerName;

  while(getline(fin,temp)){
    istringstream iss(temp);
    iss>>CustomerName>>identity>>clock;
    if (ConvertTimeInput(tim)-(ConvertTimeInput(clock))>=45){
      cout<<"\aBooking of "<<CustomerName<<" "<<identity<<" "<<clock<<" is overdue"<<endl;
      cout<<"Do you want to cancel it ? (Y/N)"<<endl;
      char choice;
      cin >> choice;
      if (choice=='Y'){
        CancelBooking(identity,clock);
      }else{
        cout<<"Booking not canceled\n\n"<<endl;
        cout<<"\nPress any button to exit (random character)"<<endl;
        cin>>wait; /*Allows wait for user to see*/
      }
    }
  }
  fin.close();
}

bool Timer::FindTime(string ID,string tim){
  bool rsp=false;
  ifstream fin;
  fin.open("Bookings.txt");
  if (fin.fail()){
    system("clear");
    cout<<"\aUnable to access Bookings.txt"<<endl;
    exit(1);
  }
  string customer,identity,clock;
  string temp;
  int count=0;
  while(getline(fin,temp)){
    istringstream iss(temp);
    iss>>customer>>identity>>clock;
    if (identity==ID){
      count++;
    }
  }
  fin.close();
  if (count>0){
    ifstream foil;
    foil.open("Bookings.txt");
    if (foil.fail()){
      system("clear");
      cout<<"\aUnable to access Bookings.txt"<<endl;
      exit(1);
    }

    int* watch = new int[count];

    int m=0;
    while(getline(foil,temp)){
      istringstream iss(temp);
      iss>>customer>>identity>>clock;
      if (identity==ID){
        watch[m]=ConvertTimeInput(clock);
        m++;
      }
    }
    bool sortz=false;
    int holder=0;
    while(!(sortz)){
      sortz=true;
      for(int i=0;i<(count-1);i++){
        if(watch[i]>watch[i+1]){
          holder=watch[i];
          watch[i]=watch[i+1];
          watch[i+1]=holder;
          sortz=false;
        }
      }
    }
    if ((ConvertTimeInput(tim)-watch[count-1])>=45){
      rsp=true;
    }else if((watch[0]-ConvertTimeInput(tim))>=45){
      rsp=true;
    }else{
      for(int i=0;i<(count-1);i++){
        if (((ConvertTimeInput
          (tim)-watch[i])>=45)&&((watch[i+1]-ConvertTimeInput(tim))>=45)){
          rsp=true;
          break;
        }
      }
    }
    delete[] watch;
  }else{
    rsp=true;
  }
  return rsp;
}
