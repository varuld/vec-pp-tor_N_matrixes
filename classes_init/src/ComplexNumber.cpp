#include "ComplexNumber.hpp"
#include <cmath>

double mRealPart;
double mImaginaryPart;
// Override default constructor
ComplexNumber::ComplexNumber()
{
	mRealPart = 0.0;
	mImaginaryPart = 0.0;
}
ComplexNumber::ComplexNumber(double x, double y)
{
	mRealPart = x;
	mImaginaryPart = y;
}
ComplexNumber::ComplexNumber(double r)
{
	mRealPart = r;
	mImaginaryPart = 0.0;
}
// a mehtods not constructor
ComplexNumber ComplexNumber::CalculateConjugate() const
{
	return ComplexNumber(mRealPart, - mImaginaryPart);
}
void ComplexNumber::SetToConjugate() {
	mImaginaryPart = - mImaginaryPart;
}

// Constructor that sets complex number z=x+iy
// copy constructor, bc takes instance of class returns new object
// with same values
ComplexNumber::ComplexNumber(const ComplexNumber& z)
{
	mRealPart = z.mRealPart;
	mImaginaryPart = z.mImaginaryPart;
}

ComplexNumber **mk_mx(int rows=3, int cols=3)
{
	/*
	function for dynamically allocate matrix arrays
	these matrixes are  n \times m
	the entries are double presision floats
	output: - matrix (A): The pointer to the matrix
	*/
	ComplexNumber **A = new ComplexNumber* [rows];
	for (int i=0; i<rows; i++)
	{
		A[i] = new ComplexNumber [cols];
	}
	return A;
}
// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
	return sqrt(mRealPart*mRealPart+
	mImaginaryPart*mImaginaryPart);
}
// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
	return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n
// using De Moivre’s theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
	double modulus = CalculateModulus();
	double argument = CalculateArgument();
	double mod_of_result = pow(modulus, n);
	double arg_of_result = argument*n;
	double real_part = mod_of_result*cos(arg_of_result);
	double imag_part = mod_of_result*sin(arg_of_result);
	ComplexNumber z(real_part, imag_part);
	return z;
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z)
{
	mRealPart = z.mRealPart;
	mImaginaryPart = z.mImaginaryPart;
	return * this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
	ComplexNumber w;
	w.mRealPart = -mRealPart;
	w.mImaginaryPart = -mImaginaryPart;
	return w;
}

// Overloading the binary + operator
ComplexNumber ComplexNumber::
operator+(const ComplexNumber& z) const
{
	ComplexNumber w;
	w.mRealPart = mRealPart + z.mRealPart;
	w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
	return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::
operator-(const ComplexNumber& z) const
{
	ComplexNumber w;
	w.mRealPart = mRealPart - z.mRealPart;
	w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
	return w;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output,
const ComplexNumber& z)
{
	// Format as "(a + bi)" or as "(a - bi)"
	output << "(" << z.mRealPart << " ";
	if (z.mImaginaryPart >= 0.0)
	{
		output << "+ " << z.mImaginaryPart << "i)";
	}
	else
	{
		// z.mImaginaryPart < 0.0
		// Replace + with minus sign
		output << "- " << -z.mImaginaryPart << "i)";
	}
	return output;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& z) const
{
	ComplexNumber w;
	w.mRealPart = z.mRealPart * mRealPart - mImaginaryPart * z.mImaginaryPart;
	w.mImaginaryPart = mRealPart * z.mImaginaryPart + mImaginaryPart * z.mRealPart;
	return w;
}

// 6.1 exe get's real_part
double ComplexNumber::GetRealPart()
{
	return mRealPart;
}
// 6.1 exe get's imag_part
double ComplexNumber::GetImaginaryPart()
{
	return mImaginaryPart;
}
// 6.2 exe
double RealPart(const ComplexNumber& z)
{
	return z.mRealPart;
}
double ImaginaryPart(const ComplexNumber& z)
{
	return z.mImaginaryPart;
}
void dlt_comp_mx(ComplexNumber **A, int size)
{
	/*
	function for dynamically delete mtrix arrays
	*/
	for (int i=0; i<size; i++)
	{
		delete[] A[i];
	}
	delete[] A;
}
