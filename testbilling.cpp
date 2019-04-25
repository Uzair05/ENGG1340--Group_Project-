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
  string dishname,dish1,dish;int counter=13,totalcost=0,cost,count=15,flag=0;

  ifstream fin("order.txt");//takes ordered dishes
  ifstream alldish("dishes.txt");//compares with txt files containing all dishes
  ofstream fout("finalbill.txt");//outputs final bill to txt file

  if(fin.fail())
  exit(0);
  if(alldish.fail())
  exit(0);
  if(fout.fail())
  exit(0);

  fout<<"Table ID= "<<tableid<<endl;
  getline(alldish,dish1);//getting name of dish

  while(getline(fin,dish))//getting orders of dishes
  {
    if(dish.substr(10,3)==tableid)//if table ids match
    {
      dish+=" ";
      //dish stores the ordered dish
      //dish1 stores the names of all the dishes

      while(getline(alldish,dish1))//takes names of all dishes
      {
        while(counter<=dish.length()-1)
        {
          dishname=dish.substr(counter,dish.find(' ',counter+1)-counter);//gets names of ordered dish

          if(dishname==dish1.substr(0,dish1.find(' ')))//if dishnames match calculate cost
          {
            cost=dish1.substr(dish1.find(' ')+1,dish1.length()-dish1.find(' '));
            totalcost+=stoi(cost);

            //breaks out of all loops if counter is the last space
            if(counter!=dish.length()-1)
            counter=dish.find(' ',counter);
            else
            flag=1;

            //appends dishname and cost
            fout<<dishname<<" "<<cost<<endl;
          }

          //appends total cost
          fout<<"Total cost= "<<totalcost<<endl;

          if(flag==1)
          break;
        }
        if(flag==1)
        break;
      }
    }
    if(flag==1)
    break;
  }
}

void FormingOrder(string tableid)
{
  cout<<dishes.txt<<endl<<endl<<"Please select dish numbers to make order and type -1 to finish ordering."<<endl;

  ifstream fin("dishes.txt");
  ofstream fout("order.txt");

  int numberofdish=0,count=1;

  if(fin.fail())
  exit(0);
  if (fout.fail())
  exit(0);

  int n;string s;
  cin>>n;
  fout<<"Table ID="<<tableid<<" ";

  //keeps reading orders and outputs them to "order.txt" until user inputs -1
  while(n!=-1)
  {
    fin.open();
    for(int i=1;i<=n;i++)
    {
      getline(fin,s);
    }
    s=s.substr(0,s.find(' '));
    fout<<s<<" ";
    cin>>n;
    fin.close();
  }
}
