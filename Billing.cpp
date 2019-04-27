#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void SwapFunctions();
void SwaptoAllDishes();
int RemovingSameTableIdfromOrder(string tableid);

void InitialiseFiles()
{
    ifstream alldish("alldishesordered.txt");
    ifstream dishes("dishes.txt");
    ofstream fout("alldishesordered.txt",ios::app);

    string name,line;int flag=0,flag1=1;

    while(getline(dishes,name))
    {
      if (flag1!=1)
      alldish.open("alldishesordered.txt");

      flag=0;
      while(getline(alldish,line))
      {
        if(name.substr(0,name.find('-'))==line.substr(0,line.find('-')))
        {
          flag=1;
          break;
        }
      }
      if(flag==0)
      fout<<name.substr(0,name.find('-'))<<"-0"<<endl;

      flag1++;

      alldish.close();
    }
}

void PrintMenu()
{
  ifstream fin("dishes.txt");
  string s;

  if (fin.fail())
  exit(0);

  int number=1;

  while(getline(fin,s))
  {
    cout<<number<<"."<<s<<endl;
    number++;
  }

  fin.close();
}

void AddDish(int n)
{
  int flag=1,flag1=1,flag2=1,price;string line,name,dishname;

  ifstream fin("dishes.txt");
  ifstream alldishfin("alldishesordered.txt");
  ofstream fout("dishes.txt",ios::app);
  ofstream alldish("alldishesordered.txt",ios::app);



  for(int i=1;i<=n;i++)
  {

    if(flag2!=1)
    fin.open("dishes.txt");

    cout<<"Please enter dishname and price. Please make sure that the dishname has no spaces in between."<<endl;
    cin>>dishname;cin>>price;

    while(getline(fin,line))
    {
      if (flag1!=1)
      alldishfin.open("alldishesordered.txt");

      while(getline(alldishfin,name))
      {
        if(name.substr(0,name.find('-'))==dishname)
        {
          flag=0;
          break;
        }
      }
      alldishfin.close();

      if(flag==0)
      break;

      flag1++;
    }

    if (flag==1)
    {
      fout<<dishname<<"-"<<price<<endl;
      alldish<<dishname<<"-"<<"0"<<endl;
      cout<<"Dish added!"<<endl<<endl;
    }

    else
    cout<<"Dish already present!"<<endl<<endl;

    fin.close();flag2++;
  }

  fin.close();
  alldish.close();
  fout.close();
}

void AppendBillingOfTable(string tableid)
{
  string dishname,dish1,dish,cost;int head=13,n,totalcost=0,counter=13,flag=0,flag1=1,flag2=1,flag3=1,tablenotpresent=1;

  ifstream order("order.txt");//takes ordered dishes
  ifstream alldish("dishes.txt");//compares with txt files containing all dishes
  ofstream fout("finalbill.txt");//outputs final bill to txt file

  if(order.fail())
  exit(0);
  if(alldish.fail())
  exit(0);
  if(fout.fail())
  exit(0);


  n=RemovingSameTableIdfromOrder(tableid);

    for(int i=1;i<=n;i++)//getting orders of dishes
    {
      getline(order,dish);
    }
    if(dish.substr(9,3)==tableid)//if table ids match
    {
      fout<<"           Table ID="<<tableid<<endl;
      fout<<"______________________________________"<<endl<<endl;
      fout<<"           Final bill"<<endl<<endl;
      fout<<"**************************************"<<endl<<endl;
      tablenotpresent=0;
    }
    else
    tablenotpresent=1;
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
      fout<<"Total cost= $"<<totalcost<<endl;
    }

    if (tablenotpresent==1)
    cout<<"Table not present"<<endl;

    order.close();
    alldish.close();
    fout.close();

  }



void SwapTemp2toOrder()
{
  ofstream fout("order.txt");
  ifstream fin("temp2.txt");

  string swapline;

  while(getline(fin,swapline))
  {
    fout<<swapline<<endl;
  }

  fin.close();
  fout.close();
}

void MakeOrderUnique(int n)
{
  ifstream fin("order.txt");
  ofstream fout("temp2.txt");

  if(fin.fail() || fout.fail())
  exit(0);

  fin.close();
  ifstream fin2("order.txt");

  string orderline;int count=1;

  while(getline(fin2,orderline))
  {
    cout<<"Orderline: "<<orderline<<endl;
    if(count==n)
    continue;

    else
    fout<<orderline<<endl;

    count++;
  }

  fin2.close();

  SwapTemp2toOrder();
}

int RemovingSameTableIdfromOrder(string tableid)
{
  ifstream order("order.txt");

  string orderline;int flag=1,prev;

  while(getline(order,orderline))
  {
    if(orderline.substr(9,3)==tableid)
    prev=flag;

    flag++;
  }

  //cout<<flag<<endl;
  order.close();

  return prev;
}

void FormingOrder(string tableid)
{
  InitialiseFiles();//adds dishes which arent already in alldishesordered.txt

  ifstream fin("dishes.txt");
  ifstream successdish("alldishesordered.txt");
  ofstream temp("temp.txt");

  RemovingSameTableIdfromOrder(tableid);
  ofstream fout("order.txt",ios::app);

  PrintMenu();

  cout<<endl<<endl<<"Please select dish numbers to make order and type -1 to finish ordering."<<endl<<endl;



  int numberofdish=0,count=1,flag,flag2=1,number;string line;

  if(fin.fail())
  exit(0);
  if (fout.fail())
  exit(0);
  if (successdish.fail())
  exit(0);
  if (temp.fail())
  exit(0);


  int n,num=0;string s;
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
    s=s.substr(0,s.find('-'));//s stores the dish ordered from dishes.txt
    fout<<s<<",";
    //s is working fine
    flag=0;

    while(getline(successdish,line))//increments counter for number of dishes ordered
    {

      if(line.substr(0,line.find('-'))==s)
      {
        temp<<s<<"-"<<"1"<<endl;
        flag=1;
        break;
      }
    }
    successdish.close();
    successdish.open("alldishesordered.txt");

    if(flag==0)
    temp<<s<<"-"<<line.substr(line.find('-')+1,line.length())<<endl;

    cin>>n;

    fin.close();

  }
  fout<<endl;
  cout<<endl<<"Thank you for your order. We will begin service soon!"<<endl<<endl;

  SwapFunctions();

  //closing all files
  fout.close();
  successdish.close();

}

void SwapFunctions()
{
  ifstream alldishes("alldishesordered.txt");
  ifstream temp("temp.txt");
  ofstream swap("swap.txt");

  string line,templine;
  int flag=0,flag1=1,num;

  while(getline(alldishes,line))
  {
    num=stoi(line.substr(line.find('-')+1,line.length()));

    if (flag1!=1)
    temp.open("temp.txt");

    flag=0;
    while(getline(temp,templine))
    {
      if(line.substr(0,line.find('-'))==templine.substr(0,templine.find('-')))
      {
        num+=1;
        flag=1;//when dish names match
      }
    }

    if (flag==0)
    swap<<line<<endl;
    else
    swap<<line.substr(0,line.find('-')+1)<<num<<endl;

    flag1++;

    temp.close();
  }
  SwaptoAllDishes();
  remove("temp.txt");
  remove("swap.txt");

}

void SwaptoAllDishes()
{
  ofstream fout("alldishesordered.txt");
  ifstream fin("swap.txt");

  string swapline;

  while(getline(fin,swapline))
  {
    fout<<swapline<<endl;
  }
}

void PrintContents()
{
  cout<<"1. Add Dishes."<<endl;
  cout<<"2. Order food."<<endl;
  cout<<"3. Show bill."<<endl;
  cout<<"4. Show dish success rate"<<endl<<endl;
  cout<<"Press -1 to exit"<<endl;
  cout<<"Please choose an option"<<endl<<endl;

}

void SuccessRate()
{
  ifstream alldishes("alldishesordered.txt");
  ofstream success("dishsuccess.txt");

  string line,s;double n;
  double totaldishesordered=0.0,dishesordered=0.0;

  while(getline(alldishes,line))
  {
    s=line.substr(line.find('-')+1,line.length());//extracting number of dishes ordered.
    totaldishesordered+=stod(s);
  }

  alldishes.close();
  alldishes.open("alldishesordered.txt");

  while(getline(alldishes,line))
  {
    dishesordered=stod(line.substr(line.find('-')+1,line.length()));
    success<<line.substr(0,line.find('-'))<<"-"<<(double)(dishesordered/totaldishesordered)<<"%"<<endl;
  }
}

int main()
{
  PrintContents();

  int n,price;string name;
  cin>>n;

  while(n!=-1)
  {
    if(n==1)
    {
      system("clear");
      cout<<"Please enter number of dishes to be added"<<endl<<endl;
      cin>>n;
      cout<<endl;
      AddDish(n);
    }
    else if(n==2)
    {
      system("clear");
      cout<<endl;
      FormingOrder("123");
      cout<<endl;
    }
    else if(n==3)
    {
      system("clear");
      AppendBillingOfTable("123");
      cout<<"Your bill is ready!"<<endl;
      cout<<endl;

    }
    else if (n==4)
    {
      system("clear");
      SuccessRate();
      cout<<"Dish success rate can be found in dishsuccess.txt!"<<endl<<endl;
    }
    else
    {
      system("clear");
      cout<<"Wrong choice. Please try again"<<endl;
      cout<<endl;
    }
    PrintContents();
    cin>>n;
  }
  cout<<"Exited successfully!"<<endl;
  remove("temp.txt");
  remove("swap.txt");
  remove("order.txt");
  remove("temp2.txt");
}
