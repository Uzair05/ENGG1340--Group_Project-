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
    foi<<ID<<" "<<tim<<endl;
    foi.close();
  }
}

void time::CancelBooking(string ID,string tim){
  ifstream fin;
  string temp;
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
      iss>>identity>>clock;
      if (!((identity==ID)&&(clock==tim))){
        fout<<identity<<" "<<clock<<endl;
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
  }
}
