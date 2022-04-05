#include <iostream>
#include <cmath>
#include <cassert>
#include <memory>
#include <ostream>

#include "Matrix2x2.hpp"


Matrix2x2::Matrix2x2()
{
	val00 = 0.0;
	val01 = 0.0;
	val10 = 0.0;
	val11 = 0.0;
}
Matrix2x2::Matrix2x2(const Matrix2x2& other)
{
	val00 = other.val00;
	val01 = other.val01;
	val10 = other.val10;
	val11 = other.val11;
}

Matrix2x2::Matrix2x2(double a, double b, double c, double d)
{
  // 3 tries at implementation

  val00 = a;
  val01 = b;
  val10 = c;
  val11 = d;
}

double Matrix2x2::CalcDeterminant() const
{
  double a = Getval00();
	double b = Getval01();
	double c = Getval10();
	double d = Getval11();

  double det = ( ((double)a) * ((double)d)) - (((double)b) * ((double)c) );

	return det;
}


CalcAdjunct Matrix2x2::CalcAdjunct(const Matrix2x2& other) const
{
  Matrix2x2 adj_matrix = Matrix2x2();

	adj_matrix.val00 = Getval11();
	adj_matrix.val01 = - Getval01();
	adj_matrix.val10 = - Getval10();
	adj_matrix.val11 = Getval00();

	return adj_matrix;
}

CalcInverse Matrix2x2::CalcInverse() const
{
  double det = CalcDeterminant();
  assert(det !=0.0);
  Matrix2x2 adj_matrix = CalcAdjunct();
  double inv_scalar = ( ((double)1) / ((double)det) );

  Matrix2x2 B();
	B().val00 = adj_matrix.val00 * (double) inv_scalar;
	B().val11 = adj_matrix.val11 * (double) inv_scalar;
	B().val01 = adj_matrix.val01 * (double) inv_scalar;
	B().val10 = adj_matrix.val10 * (double) inv_scalar;

  return B;
}

// OPERATORS
Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z)
{
	val00 = z.val00;
	val01 = z.val01;
	val10 = z.val10;
	val11 = z.val11;
}
Matrix2x2 Matrix2x2::operator-() const
{
	Matrix2x2 a;
	a().val00 = - val00;
	a().val01 = - val01;
	a().val10 = - val10;
	a().val11 = - val11;

	return a();
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const
{
	Matrix2x2 b();
  b().val00 = val00 + z.val00;
	b().val01 = val01 + z.val01;
	b().val10 = val10 + z.val10;
	b().val11 = val11 + z.val11;

	return b;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const
{
	Matrix2x2 c();
	c.val00 = val00 - z.val00;
	c.val01 = val01 - z.val01;
	c.val10 = val10 - z.val10;
	c.val11 = val11 - z.val11;

	return c;
}

// part 9
void Matrix2x2::MultScalar(double scalar)
{
  // setter function with mutification
  val00 = val00 * scalar;
  val01 = val01 * scalar;
  val10 = val10 * scalar;
  val11 = val11 * scalar;
}

void Matrix2x2::Print() const
{
	std::cout << val00 << '\t'; std::cout << val01 << endl;
	std::cout << val10 << '\t'; std::cout << val11 << endl;
}

//Matrix2x2 A_mx(1,1,3,4)
//A_mx.Print(); //
