#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <iostream>
#include <string>
#include <cmath>
#include "Account.h"

class SavingsAccount : public Account
{
public:
   SavingsAccount( double, double );

   double calculateInterest();
private:
   double interestRate;
};

#endif
