#ifndef Alert_AID_H
#define Alert_AID_H

/*I made this to hadle all our alerts without
needing to continuously refer to the proper 
format*/

#include <string>
#include <iostream>
#include <windows.h>

void alert(string message,string head){
  cout<<"\a";
  ::MessageBox(NULL,message.c_str(),head.c_str(),MB_OK);
}

#endif
