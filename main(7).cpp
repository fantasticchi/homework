#include <iostream>
#include <string>
#include <cmath>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

int main()
{
   Account account1( 16 );
   SavingsAccount account2( 22, 0.04 );
   CheckingAccount account3( 66, 2);

   cout << fixed << setprecision( 3);

   cout << "\naccount1 balance: dollar" << account1.getBalance() << endl;
   cout << "\naccount2 balance: dollar" << account2.getBalance() << endl;
   cout << "\naccount3 balance: dollar" << account3.getBalance() << endl;

   cout << "\nAttempting to debit $15from account1." << endl;
   account1.debit( 15 );
   cout << "\nAttempting to debit $29from account2." << endl;
   account2.debit( 29 );
   cout << "\nAttempting to debit $60 from account3." << endl;
   account3.debit( 60 );

   cout << "\naccount1 balance: dollar" << account1.getBalance() << endl;
   cout << "\naccount2 balance: dollar" << account2.getBalance() << endl;
   cout << "\naccount3 balance: dollar" << account3.getBalance() << endl;

   cout << "\nCrediting $55 to account1." << endl;
   account1.credit( 55 );
   cout << "\nCrediting $75 to account2." << endl;
   account2.credit( 75 );
   cout << "\nCrediting $15 to account3." << endl;
   account3.credit( 15 );

   cout << "\naccount1 balance: dollar" << account1.getBalance() << endl;
   cout << "\naccount2 balance: dollar" << account2.getBalance() << endl;
   cout << "\naccount3 balance: dollar" << account3.getBalance() << endl;

   double interest = account2.calculateInterest();
   cout << "\nAdding dollar" << interest<< " interest to account2;"
      << endl;
   account2.credit( interest );

   cout << "\nNew account2 balance: dollar;" << account2.getBalance() << endl;
}
