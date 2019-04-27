#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Reservation.h"
using namespace std;


int time::ConvertTimeInput(string tim){
  string hours,minutes;
  hours=tim.substr(0,2);
  minutes=tim.substr(3,2);
  int rslt;
  rslt=(stoi(hours)*60)+stoi(minutes);
  return rslt;
}

string time::ConvertInputTime(int tim){
  string hours,minutes;
  hours=to_string(tim/60);
  minutes=to_string(tim%60);
  string reslt;
  reslt=hours+":"+minutes;
  return reslt;
}

void time::SetBooking(string ID,string tim){
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

void time::CancelBooking(string ID,string tim){
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

void time::CheckOverTime(string tim){

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
      }
    }
  }
  fin.close();
}

bool time::FindTime(string ID,string tim){
  bool response=false;/*
  holds the valuse which is to be returned*/

  string CustomerName,identity,clock;
  string temp=""; /*temporary value holder*/
  int counter=0; /*counts number of positive hits*/

  struct MoodyJazz{
    /*allows for easier sorting*/
    string CustomerName;
    string identity;
    int watch;
  };

  ifstream fin;
  fin.open("Bookings.txt");
  if (fin.fail()){
    system("clear");
    cout<<"\aUnable to access Bookings.txt"<<endl;
    exit(1);
  }
  while(getline(fin,temp)){
    istringstream iss(temp);
    iss>>CustomerName>>identity>>clock;
    if (identity==ID){
      counter+=1;
    }
  }
  fin.close();


  MoodyJazz data[32];

  ifstream foilin;
  foilin.open("Bookings.txt");
  if (foilin.fail()){
    system("clear");
    cout<<"\aUnable to access Bookings.txt"<<endl;
    exit(1);
  }else{
    int m=-1;
    while(getline(fin,temp)){
      m+=1;
      istringstream iss(temp);
      iss>>CustomerName>>identity>>clock;
      data[m].CustomerName=CustomerName;
      data[m].identity=identity;
      data[m].watch = ConvertTimeInput(clock);
    }
    bool IsStorted =false;
    while(!(IsStorted)){
      /*bubble sort*/
      IsStorted=true;
      for(int i=0;i<(counter-1);i++){
        if (data[m].watch>data[m+1].watch){
          IsStorted=false;
          MoodyJazz temp;
          temp.CustomerName=data[m].CustomerName;
          temp.identity=data[m].identity;
          temp.watch=data[m].watch;
          data[m].CustomerName=data[m+1].CustomerName;
          data[m].identity=data[m+1].identity;
          data[m].watch=data[m+1].watch;
          data[m+1].CustomerName=temp.CustomerName;
          data[m+1].identity=temp.identity;
          data[m+1].watch=temp.watch;
          /*switches values*/
        }
      }
    }
    if ((ConvertTimeInput(tim)-data[counter-1].watch)>=45){
      response=true;
    }else if((data[0].watch-ConvertTimeInput(tim))>=45){
      response=true;
    }else{
      for(int i=0;i<(counter-1);++i){
        if (((data[i].watch-data[i+1].watch)>=(45*2))&&((ConvertTimeInput(tim)-data[i].watch)>=45)){
          return true;
          /*this point can be modified for another function*/
        }
      }
    }
  }
  foilin.close();
  return response;
}
