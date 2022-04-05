#include <iostream>
#include "src/ComplexNumber.cpp"
#include "src/CalculateExponential.cpp"
#include "src/CalculateExponential.hpp"
#include "src/Matrix2x2.cpp"
#include "src/Exercise82.hpp"

void run_compnum()
{
  ComplexNumber myComplexNumber = ComplexNumber(1,3);
  ComplexNumber b = ComplexNumber(12,3);
  std::cout << b.GetRealPart() << '\n';

  // bc friend func no need for tell location of ImaginaryPart
  std::cout << ImaginaryPart(myComplexNumber) << '\n';
  std::cout << RealPart(b) << '\n';

  ComplexNumber c = ComplexNumber(b);


  std::cout << "--" << '\n';
  std::cout << c << '\n';

  ComplexNumber v = c.CalculateConjugate();
  std::cout << v << '\n';
  v.SetToConjugate();

  std::cout << v << '\n';
}

void run_calc_exp() {
  ComplexNumber **A = mk_mx(3,3);
  A[0][0] = ComplexNumber(3.0,2.0); A[0][1] = ComplexNumber(1.0,2.0); A[0][2] = ComplexNumber(3.0,4.5);
	A[1][0] = ComplexNumber(2.1,4.5); A[1][1] = ComplexNumber(1.0,1.0); A[1][2] = ComplexNumber(1.0,2.0);
	A[2][0] = ComplexNumber(1.0,1.0); A[2][1] = ComplexNumber(2.1,4.5); A[2][2] = ComplexNumber(2.2,3.2);

  ComplexNumber **exp_of_A = mk_mx(3,3);

  CalculateExponential(A, 10, exp_of_A);

  printMatrix(exp_of_A,3,3);
}

void run_62()
{
  Matrix2x2 m1 = Matrix2x2(1,2,4,5);
  m1.Print();
}

void run_82();
{
  int a = 2; int b = -4;
  double c = 2.5; double d = -1.0;

  A=CalcAbs<int>(a); B=CalcAbs<int>(b); C=CalcAbs<double>(c); D=CalcAbs<double>(d);

  std::cout << A << ',' << B << ',' << C << ',' << D << ',' << '\n';
}

int main()
{
  run_compnum();
  run_calc_exp();
  run_82();


  return 0;
}
