#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "matrix.h"
using namespace std;


    Matrix::Matrix(int Matrix)
        :size(Matrixsize > 0 ? Matrixsize:
              throw invalid_argument("Matrix must be greater than 0")),
          ptr(new int [size])
    {
        for(size_t i=0;i<size;++i)
            ptr[i]=0;
    }


    ostream &operator<<(ostream &output,const matrix &number)
    {
        output<<"\n"<<"("<<number.fristline<<")"<<"\n"
        <<"("<<number.secondline<<")"<<"\n"
        <<"("<<number.thridline<<")"<<"\n";
        return output;
    }

    istream &operator>>(istream &input,matrix &number)
    {
        input.ignore();
        input>>setw(3)>>number.fristline;;
        input.ignore(2);
        input>>setw(3)>>number.secondline;
        input.ignore(2);
        input>>setw(3)>>number.thridline;
        input.ignore();
        return input;
    }


    Matrix::Matrix operator+( const Matrix &, const Matrix & )
    {
        for ( size_t i=0;i<size;++i)
        ptr3[i]=ptr2[i]+ptr3[i];
    }
    Matrix::Matrix operator-( const Matrix &, const Matrix & )
    {
        for ( size_t i=0;i<size;++i)
        ptr3[i]=ptr2[i]-ptr3[i];
    }

    Matrix::Matrix operator/( const Matrix &, const Matrix & )
    {
        for ( size_t i=0;i<size;++i)
        ptr3[i]=ptr2[i]/ptr3[i];
    }

     int &Matrix::Matrix operator*( double, const Matrix & )
     {
         if(subscript<0||subscript>=size)
             throw out_of_rang("Subscript out of range");
         return ptr[subscript];
     }

     int Matrix::Matrix operator*( const Matrix &, double ) const
     {
         if(subscript<0||subscript>=size)
             throw out_of_rang("Subscript out of range");
         return ptr[subscript];
     }
     int Matrix::Matrix operator/( const Matrix &, double )
     {
         if(subscript<0||subscript>=size)
             throw out_of_rang("Subscript out of range");
         return ptr[subscript];
     }


    Matrix( unsigned int r = 0, unsigned int c = 0);
    Matrix( unsigned int r , unsigned int c, double val );
    Matrix( unsigned int n );
    Matrix( const Matrix &rhs );

    ~Matrix();

    Matrix &operator=( const Matrix & );

    double const* operator[]( const unsigned int i ) const
    {
        return mat + i * col;
    }

    double * operator[]( const unsigned int i )
    {
        return mat + i * col;
    }

    unsigned int getRows() const
    {
        return row;
    }

    unsigned int getCols() const
    {
        return col;
    }


};
