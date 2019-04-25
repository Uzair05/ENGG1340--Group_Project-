#ifndef Resrv_H
#define Resrv_H

class time{
public:
int ConvertTimeInput(string time);
/*Accepts a manual input of time in 24 hours format*/
/*convert it into a integer which is munites since 00:00*/
string ConvertInputTime(int time);
/*Accept Integer int minutes since 00:00 */
/*converts it into a string in 24 hour format*/


void SetBooking(string ID,string time);
/*Accepts a manual input of time in 24 hours format*/
/*creates an unsorted list of bookings*/
/*when booking it makes sure to check if it is available at that time*/

void CancelBooking(string ID,string time);
/*Accepts a manual input of time in 24 hours format*/
/*removes the booking from the bookings list*/

void CheckOverTime(string ID,string time);

/*Accepts a manual input of time in 24 hours format*/
};

#endif
