
#include <iostream>
#include <iomanip>
#include "math.h"
#include "2.h"

using namespace std;

int main()
{
   Polynomial a, b, c,d;

   a.enterTerms();
   b.enterTerms();
   d = a;
   cout << "First polynomial is:\n";
   a.printPolynomial();
   cout << "Second polynomial is:\n";
   b.printPolynomial();
   cout << "\nAdding the polynomials yields is:\n";
   c = a + b;
   c.printPolynomial();
   cout << "\n+= the polynomials yields is:\n";
   a += b;
   a.printPolynomial();
   cout << "\nSubtracting the polynomials yields is:\n";
   a = d;
   c = a - b;
   c.printPolynomial();
   cout << "\n-= the polynomials yields is \n";
   a -= b;
   a.printPolynomial();
   cout << "\nMultiplying the polynomials yields is\n";
   a = d;
   c = a * b;
   c.printPolynomial();
   cout << "\n*= the polynomials yields is\n"<<endl;
   a *= b;
   a.printPolynomial();

}

