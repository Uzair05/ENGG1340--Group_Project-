#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


void CancelBooking(string ID,string tim){
  ifstream fin;
  string temp;
  string temp2;
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

int main(){

CancelBooking("Umair","13:00");

return 0;
}
