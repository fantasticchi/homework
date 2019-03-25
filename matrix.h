#include <iostream>

class Matrix
{
	friend std::istream &operator>>( std::istream &, Matrix & );
	friend std::ostream &operator<<( std::ostream &, const Matrix & );

	friend Matrix operator+( const Matrix &, const Matrix & );
	friend Matrix operator-( const Matrix &, const Matrix & );
	friend Matrix operator*( const Matrix &, const Matrix & );

	friend Matrix operator*( double, const Matrix & );
	friend Matrix operator*( const Matrix &, double );
	friend Matrix operator/( const Matrix &, double );

public:

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

private:
	unsigned int row, col;
	double *mat;
};

