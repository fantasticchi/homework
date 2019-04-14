#include <iostream>
#include <string>
#include <cmath>
#include "Account.h"
using namespace std;

Account::Account( double initialBalance )
{
   if ( initialBalance >= 0)
      balance = initialBalance;
   else
   {
      cout << "Error: Initial balance cannot be used." << endl;
      balance = 0;
   }


void Account::credit( double amount )
{
   balance +=amount;
}


void Account::debit( double amount )
{
   if ( amount > balance )
   {
      cout << "Debit amount bigger than account balance." << endl;
      return 0;
   }
   else
   {
      balance -= amount;
      return 1;
   }
}
