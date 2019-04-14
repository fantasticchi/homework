
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include <cmath>
#include <iostream>
class Account
{
public:
   explicit Account( double );
   void credit( double );
   void debit( double );
   void setBalance( double );
   double getBalance();
private:
   double balance;
};
#endif
