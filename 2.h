#ifndef 2_H_INCLUDED
#define 2_H_INCLUDED
#include<iostream>
class Polynomial
{
public:
    static const int maxTerms;
    friend std::istream &operator>>(std::istream&,Polynomial&);
    friend std::ostream &operater<<(std::ostream&,Polynomial&);

    friend Polynomial operator +(const Polynomial&,const olynomial&);
    friend Polynomial operator -(const Polynomial&,const olynomial&);
    friend Polynomial operator ==(const Polynomial&,const olynomial&);
    friend Polynomial operator *(const Polynomial&,const olynomial&);
    friend Polynomial operator +=(const Polynomial&,const olynomial&);
    friend Polynomial operator -=(const Polynomial&,const olynomial&);
    friend Polynomial operator *=(const Polynomial&,const olynomial&);

    void enterPolynomialTerms();
    void countPolynomial()const;
    int NumberOfPolynomials()const;
    int getPolynomialExponent(int)const;
    int getPolynomialCoefficent(int,int);
    ~Polynomial();

private:
    int numberOfPolynomial;
    int exponents[maxTerms];
    int coefficients[maxTerms];
    static void PolynomialCombine(Ploynomial&);
};


#endif // 2_H_INCLUDED
