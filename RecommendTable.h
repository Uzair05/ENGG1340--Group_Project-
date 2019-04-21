#ifndef Recommend_H
#define Recommend_H

#include "RestaurantTables.h"
#include <string>

/*This function is a little weird
first it assumes all the tables are in an array format
the array is passed to the function along with its size and he number of NumberofGuests

since i am not using a list or tuple datatype i cannot pass multiple options of tables
it'll just pass the first table it finds suitable

two rounds. First it'll try to find a table with perfect number of seats
should that fail then it tries to look for the table with a little bit more.

i.e. 5 people can be seated on a 6 seater table. etc.
*/

/*currently working on a method to reduce overflow*/

struct MoodyJazz
{
  string ID="";
  int seat=0;
};


string recommend(RTables a[],int NumberofGuests, int size/*holds the total number of tables*/)
{
  MoodyJazz *pop = new MoodyJazz[size];//creates arrays for each table holding the id and seats
  bool flag=false;
  for(int i=0;i<size;++i)
  {
    if ((a[i].getNofSeats()==NumberofGuests)&&(!(a[i].getIsOccupied())))
    {
      flag=true;
      return a[i].getID();
      break;
    }
  }
  int count=0;
  if (!(flag))
  {
    for(int i=0;i<size;++i)
    {
      if ((a[i].getNofSeats()>=NumberofGuests)&&(!(a[i].getIsOccupied())))
      {
        pop[count].ID=a[i].getID();
        pop[count].seat=a[i].getNofSeats();
        count+=1;
      }
    }
  }

  if (count==0)
  {
    return "NoTables";
  }
  else
  {
    MoodyJazz lowest;
    lowest.ID=pop[0].ID;
    lowest.seat=pop[0].seat;
    for(int i=1;i<count;i++)
    {
      if ((lowest.seat>pop[i].seat)&&(pop[i].seat!=0))
      {
        lowest.ID=pop[i].ID;
        lowest.seat=pop[i].seat;
      }
    }
    return lowest.ID;
  }
  delete[] pop;
}


#endif
