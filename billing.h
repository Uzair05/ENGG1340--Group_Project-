#ifndef Billing_H
#define Billing_H

#include <iostream>
#include <string>

using namespace std;

class Billing
{
  public:
    void InitialiseFiles();
    void PrintMenu();
    void AddDish(int n);
    void AppendBillingOfTable(string tableid);
    void SwapTemp2toOrder();
    void MakeOrderUnique(int n);
    int RemovingSameTableIdfromOrder(string tableid);
    void FormingOrder(string tableid);
    void SwapFunctions();
    void SwaptoAllDishes();
    void PrintContents();
    void SuccessRate();
    void Control(string tableid);
};
