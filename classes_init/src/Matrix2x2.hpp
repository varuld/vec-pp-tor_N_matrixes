#ifndef SUBMISSION_MATRIX2X2_HPP
#define SUBMISSION_MATRIX2X2_HPP

#include <iostream>

class Matrix2x2 {
private :
  double val00; // first row , first column
  double val01; // first row, second column
  double val10; // second row , first colum
  double val11; // second row , second column

public :
  // CONSTRUCTORS:
  Matrix2x2(); // 6.2.1
  // Copy constructor
  Matrix2x2(const Matrix2x2& other); // 6.2.2
  // constructor specifies 4 entries ()
  Matrix2x2(double a, double b, double c, double d); // 6.2.3

  // METHODS:
  double CalcDeterminant() const; // 6.2.4
  Matrix2x2 CalcInverse() const; // 6.2.5
  Matrix2x2 CalcAdjunct() const;

  // OPERATORS
  Matrix2x2& operator=(const Matrix2x2& z);
  Matrix2x2 operator-() const;
  Matrix2x2 operator+(const Matrix2x2& z) const;
  Matrix2x2 operator-(const Matrix2x2& z) const;

  // setter function with mutification
  void MultScalar(double scalar);

  // getter's
  double Getval00() const {return val00;}
  double Getval01() const {return val01;}
  double Getval10() const {return val10;}
  double Getval11() const {return val11;}

  // non mandatory
  void Print() const;

/*
  friend double val00(const Matrix2x2& other);
  friend double val01(const Matrix2x2& other);
  friend double val10(const Matrix2x2& other);
  friend double val11(const Matrix2x2& other);
*/

};
#endif /* SUBMISSION MATRIX2X2 HPP */
