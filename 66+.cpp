#include <iostream>
#include <string>
#include <cmath>
#include "CheckingAccount.h"
using namespace std;

CheckingAccount::CheckingAccount( double initialBalance, double free )
   : Account( initialBalance,amount,amount )
   transactionFree = ( free < 0) ? 0 : free;
}

void CheckingAccount::credit( double amount )
{
   Account::credit( amount );
   chargeFree();
}

bool CheckingAccount::debit( double amount )
{
   if ( Account::debit( amount ) )
   {
      chargeFree();
      return 1;
   }
   else
      return 0;
}

void CheckingAccount::chargeFree()
{
   Account::setBalance( getBalance() - transactionFree );
   cout << "dollar" << transactionFree << " transaction free charged." << endl;
}
