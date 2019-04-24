#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void AddDish(string dishname, int price)
{
  ofstream fout("dishes.txt",ios::app);
  fout<<dishname<<" "<<price;
}

void AppendBillingOfTable(string tableid)
{
  string dishname;int counter=13,totalcost=0,cost,count=15;

  ifstream fin("order.txt");//takes ordered dishes
  ifstream alldish("dishes.txt");//compares with txt files containing all dishes
  ofstream fout("finalbill.txt",ios::app);//outputs final bill to txt file

  fout<<"Table ID= "<<tableid<<endl;
  getline(alldish,dish1);//getting name of dish

  while(getline(fin,dish))//getting orders of dishes
  {
    if(dish.substr(10,3)==tableid)
    {
      dish+=" ";
      //dish stores the ordered dish
      //dish1 stores the names of all the dishes

      while(getline(alldish,dish1))
      {
        while(count<=dish.length()-1)
        {
          dishname=dish.substr(counter,dish.find(' ',counter+1)-counter);//gets names of ordered dish
          
          if(dishname==dish1.substr(0,dish1.find(' ')))
          {
            cost=dish1.substr(dish1.find(' ')+1,dish1.length()-dish1.find(' '));
            totalcost+=stoi(cost);
            count=dish.find(' ',count);
            fout<<dishname<<" "<<cost<<endl;
          }

          fout<<"Total cost= "<<totalcost<<endl;
        }
      }
    }
  }
}
