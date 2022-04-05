#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>

class ComplexNumber
{
private:
	double mRealPart;
	double mImaginaryPart;
public:

	// constructors
	ComplexNumber();
	ComplexNumber(double x, double y);
	ComplexNumber(double r);
	// not constructors
	ComplexNumber(const ComplexNumber& z);
	ComplexNumber CalculateConjugate() const;
	void SetToConjugate();


	double CalculateModulus() const;
	double CalculateArgument() const;
	ComplexNumber CalculatePower(double n) const;
	ComplexNumber& operator=(const ComplexNumber& z);
	ComplexNumber operator-() const;
	ComplexNumber operator+(const ComplexNumber& z) const;
	ComplexNumber operator-(const ComplexNumber& z) const;
	friend std::ostream& operator<<(std::ostream& output,
		const ComplexNumber& z);

	ComplexNumber operator*(const ComplexNumber& z) const;
	ComplexNumber operator/(const ComplexNumber& z) const;
	void dlt_comp_mx(ComplexNumber **A, int size);

	// 6.1 exe
	double GetImaginaryPart();
	double GetRealPart();

	// 6.2 exe
	friend double ImaginaryPart(const ComplexNumber& z);
	friend double RealPart(const ComplexNumber& z);
};

#endif
