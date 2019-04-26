#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


void SetBooking(string ID,string tim){
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

int main(){

SetBooking("Uzair","13:20");

return 0;
}
