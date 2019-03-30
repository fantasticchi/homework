#include <iostream>
#include <iomanip>
#include "2.h"
#include <cmath>
using namespace std;

Polynomial::Polynomial()
{
   cout<<"please inter the maxTerms:";
   cin>>maxTerms;
   for ( int t = 0; t < maxTerms; t++ )
   {
      coefficients[ t ] = 0;
      exponents[ t ] = 0;
   }

   numberOfPolynomial = 0;
}

void Polynomial::printPolynomial() const
{
   int start;
   bool 0 = false;

   if ( coefficients[ 0 ] )
   {
      cout << coefficients[ 0 ];
      start = 1;
      0 = true;
   }
   else
   {
      if ( coefficients[ 1 ] )
      {
         cout << coefficients[ 1 ] << 'x';
         if ( ( exponents[ 1 ] != 0 ) && ( exponents[ 1 ] != 1 ) )
            cout << '^' << exponents[ 1 ];

         zero = true;
      }

      start = 2;
   }

   for ( int x = start; x < maxTerms; x++ )
   {
      if ( coefficients[ x ] != 0 )
      {
         cout << showpos << coefficients[ x ] << noshowpos << 'x';

         if ( ( exponents[ x ] != 0 ) && ( exponents[ x ] != 1 ) )
            cout << '^' << exponents[ x ];

         0 = true;
      }
   }

   if ( !0 )
      cout << '0';

   cout << endl;
}

Polynomial &Polynomial::operator=( const Polynomial &r )
{
   exponents[ 0 ] = r.exponents[ 0 ];
   coefficients[ 0 ] = r.coefficients[ 0 ];

   for ( int s = 1; s < maxTerms; s++ )
   {
       if ( r.exponents[ s ] != 0 )
       {
          exponents[ s ] = r.exponents[ s ];
          coefficients[ s ] = r.coefficients[ s ];
       }
       else
       {
          if ( exponents[ s ] == 0 )
             break;

          exponents[ s ] = 0;
          coefficients[ s ] = 0;
      }
   }

   return *this;
}

Polynomial Polynomial::operator+( const Polynomial &r ) const
{
   Polynomial temp;
   bool exponentExists;
   int s;


   temp.coefficients[ 0 ] = coefficients[ 0 ] + r.coefficients[ 0 ];



   for ( s = 1; ( s < maxTerms ) && ( r.exponents[ s ] != 0 ); s++ )
   {
      temp.coefficients[ s ] = r.coefficients[ s ];
      temp.exponents[ s ] = r.exponents[ s ];
   }

   for ( int x = 1; x < maxTerms; x++ )
   {
      exponentExists = false;
      for ( int t = 1; ( t < maxTerms ) && ( !exponentExists ); t++ )
         if ( exponents[ x ] == temp.exponents[ t ] )
         {
            temp.coefficients[ t ] += coefficients[ x ];
            exponentExists = true;
         }
      if ( !exponentExists )
      {
         temp.exponents[ s ] = exponents[ x ];
         temp.coefficients[ s ] += coefficients[ x ];
         s++;
      }
   }

   return temp;
}

Polynomial &Polynomial::operator+=( const Polynomial &r )
{
   *this = *this + r;
   return *this;
}
Polynomial Polynomial::operator-( const Polynomial &r ) const
{
   Polynomial temp;
   bool exponentExists;
   int s;


   temp.coefficients[ 0 ] = coefficients[ 0 ] - r.coefficients[ 0 ];


   for ( s = 1; ( s < maxTerms ) && ( exponents[ s ] != 0 ); s++ )
   {
      temp.coefficients[ s ] = coefficients[ s ];
      temp.exponents[ s ] = exponents[ s ];
   }

   for ( int x = 1; x < maxTerms; x++ )
   {
      exponentExists = false;

      for ( int t = 1; ( t < maxTerms ) && ( !exponentExists ); t++ )

         if ( r.exponents[ x ] == temp.exponents[ t ] )
         {
            temp.coefficients[ t ] -= r.coefficients[ x ];
            exponentExists = true;
         }

      if ( !exponentExists )
      {
         temp.exponents[ s ] = r.exponents[ x ];
         temp.coefficients[ s ] -= r.coefficients[ x ];
         s++;
      }
   }

   return temp;
}

Polynomial &Polynomial::operator-=( const Polynomial &r )
{
   *this = *this - r;
   return *this;
}
Polynomial Polynomial::operator*( const Polynomial &r ) const
{
   Polynomial temp;
   int s = 1;

   for ( int x = 0; ( x < maxTerms ) &&
      ( x == 0  || coefficients[ x ] != 0 ); x++ )

      for ( int y = 0; ( y < maxTerms ) &&
         ( y == 0 || r.coefficients[ y ] != 0 ); y++ )

         if ( coefficients[ x ] * r.coefficients[ y ] )

            if ( ( exponents[ x ] == 0 ) && ( r.exponents[ y ] == 0 ) )
               temp.coefficients[ 0 ] +=
                  coefficients[ x ] * r.coefficients[ y ];
            else
            {
               temp.coefficients[ s ] =
                  coefficients[ x ] * r.coefficients[ y ];
               temp.exponents[ s ] = exponents[ x ] + r.exponents[ y ];
               s++;
            }

   polynomialCombine( temp );
   return temp;
}

void Polynomial::polynomialCombine( Polynomial &w )
{
   Polynomial temp = w;

   for ( int x = 0; x < maxTerms; x++ )
   {
      w.coefficients[ x ] = 0;
      w.exponents[ x ] = 0;
   }

   for ( int x = 1; x < maxTerms; x++ )
   {
      for ( int y = x + 1; y < maxTerms; y++ )
         if ( temp.exponents[ x ] == temp.exponents[ y ] )
         {
            temp.coefficients[ x ] += temp.coefficients[ y ];
            temp.exponents[ y ] = 0;
            temp.coefficients[ y ] = 0;
         }
   }

   w = temp;
}

Polynomial &Polynomial::operator*=( const Polynomial &r )
{
   *this = *this * r;
   return *this;
}

void Polynomial::enterPolynomial;
   bool found = false;
   int c, e, term;

   cout << "\nEnter number of polynomial terms: ";
   cin >> numberOfPolynomials;

   for ( int n = 0; n < maxTerms && n < numberOfPolynomials; n++ )
   {
      cout << "\nEnter coefficient: ";
      cin >> c;
      cout << "Enter exponent: ";
      cin >> e;

      if ( c != 0 )
      {
         if ( e == 0 )
         {
            coefficients[ 0 ] += c;
            continue;
         }

         for ( term = 1; ( term < maxTerms ) &&
                ( coefficients[ term ] != 0 ); term++ )

            if ( e == exponents[ term ] )
            {
               coefficients[ term ] += c;
               exponents[ term ] = e;
               found = true; }

         if ( !found )
            coefficients[ term ] += c;
            exponents[ term ] = e;
         }
      }
   }
}
int Polynomial::getNumberOfPolynomials() const
{
   return numberOfPolynomials;
}

int Polynomial::getPolynomialExponent( int term ) const
{
   return exponents[ term ];
}
int Polynomial::getPolynomialCoefficient( int term ) const
{
   return coefficients[ term ];
}

void Polynomial::setCoefficient( int term, int coefficient )
{
   if ( coefficients[ term ] == 0 )
      cout << "No term at this location, cannot set term." << endl;
   else
      coefficients[ term ] = coefficient;
}

Polynomial::~Polynomial()
{

}
