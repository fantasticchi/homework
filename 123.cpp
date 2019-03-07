#include<iomanip>
#include"12.h"
using namespace std;

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
