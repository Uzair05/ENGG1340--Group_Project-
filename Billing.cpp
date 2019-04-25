#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void PrintMenu()
{
  ifstream fin("dishes.txt");
  string s;

  if (fin.fail())
  exit(0);

  while(getline(fin,s))
  {
    cout<<s<<endl;
  }

  fin.close();
}

void AddDish(string dishname, int price)
{
  ofstream fout("dishes.txt");

  if (fout.fail())
  exit(0);

  fout<<dishname<<"-"<<price;

  fout.close();
}

void AppendBillingOfTable(string tableid)
{
  string dishname,dish1,dish,cost;int head=13,totalcost=0,counter=13,flag=0,flag2=1;

  ifstream order("order.txt");//takes ordered dishes
  ifstream alldish("dishes.txt");//compares with txt files containing all dishes
  ofstream fout("finalbill.txt");//outputs final bill to txt file

  if(order.fail())
  exit(0);
  if(alldish.fail())
  exit(0);
  if(fout.fail())
  exit(0);



  fout<<"           Table ID="<<tableid<<endl;
  fout<<"______________________________________"<<endl<<endl;
  fout<<"           Final bill"<<endl<<endl;
  fout<<"**************************************"<<endl<<endl;

  while(getline(order,dish))//getting orders of dishes
  {
    if(dish.substr(9,3)==tableid)//if table ids match
    {

      //dish stores the ordered dish
      //dish1 stores the names of all the dishes

      while(getline(alldish,dish1))//takes names of all dishes
      {

        counter=13;flag=0;
        while((counter!=dish.length()-1) && (flag==0))
        {

          if (counter==13)
          dishname=dish.substr(counter,dish.find(',',counter+1)-counter);//gets names of ordered dish
          else
          dishname=dish.substr(counter+1,dish.find(',',counter+2)-counter-1);

          if(dishname==dish1.substr(0,dish1.find('-')))//if dishnames match, calculate cost
          {

            cost=dish1.substr(dish1.find('-')+1,dish1.length()-dish1.find('-')-1);

            totalcost+=stoi(cost);

            //breaks out of all loops if counter is the last comma

            if(counter!=dish.length()-1)
            {
              counter=dish.find(',',counter+1);
            }
            else
            flag=1;

            //appends dishname and cost
            fout<<dishname<<"-"<<cost<<endl;
          }
          else if (counter!=dish.length()-1)
          {
            counter=dish.find(',',counter+1);
          }
          else
          break;
        }

      }
      fout<<endl<<"***********************************"<<endl<<endl;
      fout<<"Total cost= "<<totalcost<<endl;
    }
    else
    continue;

    if(flag==1)
    break;
  }
  order.close();
  alldish.close();
  fout.close();
}

void FormingOrder(string tableid)
{
  ifstream fin("dishes.txt");
  ofstream fout("order.txt");

  PrintMenu();

  cout<<endl<<endl<<"Please select dish numbers to make order and type -1 to finish ordering."<<endl<<endl;

  int numberofdish=0,count=1;

  if(fin.fail())
  exit(0);
  if (fout.fail())
  exit(0);

  int n;string s;
  cin>>n;
  fout<<"Table ID="<<tableid<<" ";
  fin.close();

  //keeps reading orders and outputs them to "order.txt" until user inputs -1
  while(n!=-1)
  {
    fin.open("dishes.txt");
    for(int i=1;i<=n;i++)
    {
      getline(fin,s);
    }
    s=s.substr(0,s.find('-'));
    fout<<s<<",";
    cin>>n;
    fin.close();
  }

  //closing all files
  fin.close();
  fout.close();

}

int main()
{
  FormingOrder("123");
  AppendBillingOfTable("123");
}
