#ifndef Resrv_H
#define Resrv_H

class time{
public:
int ConvertTimeInput(string tim);
/*Accepts a manual input of time in 24 hours format*/
/*convert it into a integer which is munites since 00:00*/
string ConvertInputTime(int tim);
/*Accept Integer int minutes since 00:00 */
/*converts it into a string in 24 hour format*/


void SetBooking(string ID,string tim);
/*Accepts a manual input of time in 24 hours format*/
/*creates an unsorted list of bookings*/
/*when booking it makes sure to check if it is available at that time*/

void CancelBooking(string ID,string tim);
/*Accepts a manual input of time in 24 hours format*/
/*removes the booking from the bookings list*/

void CheckOverTime(string ID,string tim);

/*Accepts a manual input of time in 24 hours format*/

bool FindTime(string ID,string tim);
/*Accepts ID and time of booking and checks if it is possible within that time space*/
/*only sends true if it doesnt overlap 45 minuts with other bookings*/

/*This needs to be appended to recommend function*/
};



#endif
