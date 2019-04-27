#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


void CancelBooking(string ID,string tim){
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

int ConvertTimeInput(string tim){
  string hours,minutes;
  hours=tim.substr(0,2);
  minutes=tim.substr(3,2);
  int rslt;
  rslt=(stoi(hours)*60)+stoi(minutes);
  return rslt;
}

void CheckOverTime(string tim){
  ifstream fin;
  fin.open("Bookings.txt");
  if (fin.fail()){
    //system("clear");
    cout<<"\aUnable to access Bookings.txt"<<endl;
    exit(1);
  }

  string identity,clock;
  string temp;

  while(getline(fin,temp)){
    istringstream iss(temp);
    iss>>identity>>clock;
    if (ConvertTimeInput(tim)-(ConvertTimeInput(clock))>=45){
      cout<<"\aBooking "<<identity<<" "<<clock<<" is overdue"<<endl;
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
}

int main(){

  CheckOverTime("13:45");

return 0;
}
