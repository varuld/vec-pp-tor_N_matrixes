//#include "io.hpp"
#include "sub_files/vector.hpp"
#include "sub_files/Matrix.hpp"
#include "sub_files/SparseVector.hpp"
#include <iostream>
#include <string>
#include <utility>


void vec_test(Vector<double> v, double v1, double v2, double v3, std::string ss)
{
  bool valid = (v[0] == v1 && v[1] == v2 && v[2] == v3);
  if (valid)
  {
    std::cout << "vec value valid: " << ss << '\n';
  }
  else
  {
    std::cout << "invalid" << '\n';
    std::cout << ss << '\n';
    std::cout << "expeted" << '\n';
    std::cout << v1 << " " << v2 << " " << v3 << '\n';
    std::cout << "got" << '\n';
    std::cout << v[0] << " " << v[1] << " " << v[2] << '\n';
  }
}

/*
void sp_vec_test(SparseVector<double> sp_v, unsigned int ix1, double val1, unsigned int ix2, double val2, std::string ss)
{
  bool valid = (sp_v.indexNonZero(0) == ix1 && sp_v.valueNonZero(0)  == val1 && sp_v.indexNonZero(1) == ix2 && sp_v.valueNonZero(1)  == val2);
  if (valid)
  {
    std::cout << "vec value valid: " << ss << '\n';
  }
  else
  {
    std::cout << "invalid" << '\n';
    std::cout << ss << '\n';
    std::cout << "expeted" << '\n';
    std::cout << val1 << "@" << ix1 << "and" << val2 << "@" << ix2 << '\n';
    std::cout << "got" << '\n';
    std::cout << sp_v.valueNonZero(0) << "@" << sp_v.indexNonZero(0) << "and" << sp_v.valueNonZero(1) << "@" << sp_v.indexNonZero(1) << '\n';
  }
}
*/
// void vektor_test(Vector <double> v, )

void v2t(Vector<double> v, double v1, double v2, std::string ss)
{
  bool valid = (v[0] == v1 && v[1] == v2);
  if (valid)
  {
    std::cout << "valid: " << ss << '\n';
  }
  else
  {
    std::cout << "invalid" << '\n';
    std::cout << ss << '\n';
    std::cout << "expeted" << '\n';
    std::cout << v1 << " " << v2 <<  '\n';
    std::cout << "got" << '\n';
    std::cout << v[0] << " " << v[1] << '\n';
  }
}

void int_test(int exp, int act, std::string ss)
{
  bool valid = (exp==act);
  if (valid)
  {
    std::cout << "valid int: " << ss << '\n';
  }
  else
  {
    std::cout << "invalid" << '\n';
    std::cout << ss << '\n';
    std::cout << "expeted" << '\n';
    std::cout << exp << '\n';
    std::cout << "got" << '\n';
    std::cout << act << '\n';
  }
}
void double_test(double exp, double act, std::string ss)
{
  bool valid = (exp==act);
  if (valid)
  {
    std::cout << "valid: " << ss << '\n';
  }
  else
  {
    std::cout << "invalid" << '\n';
    std::cout << ss << '\n';
    std::cout << "expeted" << '\n';
    std::cout << exp << '\n';
    std::cout << "got" << '\n';
    std::cout << act << '\n';
  }
}

void run_vec()
{
  Vector<double> a = Vector<double>(3);
  vec_test(a, 0,0,0,"exists test");

  for (int i = 0 ; i <3; i++)
  {
    a[i] = i+1;
  }

  vec_test(a, 1,2,3,"input test");
  int_test(a.size(),3, "size test");

  Vector<double> b = Vector<double>(a);
  vec_test(b, 1,2,3,"copy test");
  b[1] = 1;
  vec_test(a, 1,2,3,"cp1 test");
  vec_test(b, 1,1,3,"cp2 test");
  a = b;
  vec_test(a, 1,1,3,"assign1 test");
  vec_test(b, 1,1,3,"assign2 test");
  double_test(a[0], 1, "vlue test");
  Vector<double> c = a*2;
  vec_test(c, 2,2,6, "scalar opr");
  Vector<double> d = a-b;
  vec_test(d,0,0,0,"minus opr");
  Vector<double> e = a+b;
  vec_test(e,2,2,6,"plus opr");
  e[0] = a[0];

  double_test(e[0],1,"val assign test");
  e[0] =2;
  e[1] = 2;
  e[2] = 1;
  double cn = e.CalculateNorm();
  double_test(3,cn,"norm opr");
  a = -a;
  vec_test(a,-1,-1,-3,"unary opr");
}


void mx_test(Vector<double> v, double v1, double v2, double v3, std::string ss)
{
  bool valid = (v[0] == v1 && v[1] == v2 && v[2] == v3);
  if (valid)
  {
    std::cout << "valid" << '\n';
  }
  else
  {
    std::cout << "invalid" << '\n';
    std::cout << ss << '\n';
    std::cout << "got" << '\n';
    std::cout << v1 << " " << v2 << " " << v3 << '\n';
  }
}


void run_matrix()
{
  Matrix<double> m1 = Matrix<double>(2,2);

  double_test(m1(0,0), 0, "mx int");

  m1(0,0) = 1; // T& operator()(int i, int j) testing
  double_test(m1(0,0),1, "assign");
  m1(1,1) = 3;
  double_test(m1(1,1),3, "assign");

  int rows = m1.GetNumberOfRows();
  int cols = m1.GetNumberOfColumns();
  int_test(rows, 2, "rows");
  int_test(cols, 2, "cols");

  Matrix<double> m2 = Matrix<double>(m1);
  double_test(m2(1,0), 0, "copy opr");

  Matrix<double> m3 = m1 -m2;
  double_test(m3(0,1),0, "mx minus");
  Matrix<double> m4 = m1 + m2;
  double_test(m4(0,0),0," plus opr");

  Matrix<double> m5 = -m4;
  double_test(m5(0,0),0," unary opr");
  Matrix<double> m6 = m4 * 2;
  double_test(m6(0,0),0," times opr");

  // vector matrix mult opr
  Vector<double> r = Vector<double>(2);
  r[0] = 2;
  r[1] = 3;
  Vector<double> res = r * m1;
  Vector<double> m_res = m1 * r;
  v2t(res, 2,9, "mvult1 opr");
  v2t(m_res,2,9, "m2 opr");


}


void space()
{
  std::cout << "-------" << '\n';
}
void diviede()
{space();}
void run_sp()
{
  SparseVector<double> sp0 = SparseVector<double>();
  sp0.printsp();
  SparseVector<double> sp1 = SparseVector<double>();
  sp1.setValue(5,5.5);
  sp1.printsp();
//  sp0.getValue(0);
  //sp_vec_test(sp0,0,0.0,0,0.0, "sp_vec exists");
/*
  SparseVector<int> sp1 = SparseVector<int>(1);
  SparseVector<double> sp2 = SparseVector<double>(9);
  sp2.setValue(2,2);
  sp2.setValue(6, 3.1);
  sp_vec_test(sp2, 2,2,6,3.1, "SparseVector test"); // sp_vec, indx, val, indx, val, string
  sp2.printsp();
  */
  /*
  space();
  std::cout << "test getValue" << '\n';
  space();
  std::cout << sp2.getValue(6) << '\n';
  std::cout << sp2.getValue(3) << '\n';
  space();
  std::cout << "testing getIndex" << '\n';
  std::cout << sp2.getIndex(6) << '\n'; // should return 3
  std::cout << sp2.getIndex(5) << '\n'; // should return -1
  space();
  std::cout << "test size and nonZeroes" << '\n';
  std::cout <<  sp0.size() << std::endl;
  std::cout << sp1.nonZeroes() << std::endl;
  sp0.printsp();
  sp1.printsp();
  // test on vector with stuff in it
  std::cout <<  sp2.size() << std::endl;
  std::cout << sp2.nonZeroes() << std::endl;
  std::cout << sp2.indexNonZero(1) << '\n';
  std::cout << sp2.valueNonZero(1) << '\n';
  space();
  std::cout << "test copy contstructor" << '\n';
  SparseVector<int> sp4 = SparseVector<int>(sp2); // testing copy constructor
  sp4.printsp();
  space();
  sp4.printsp();
  sp4 -= sp2;
  sp4.printsp();
  diviede();
  */
}

int main()
{
  run_vec();
  run_matrix();
  run_sp();

  //int_test()
  //run_vec();
  //run_matrix();
  //run_sp();

  return 0;
}
