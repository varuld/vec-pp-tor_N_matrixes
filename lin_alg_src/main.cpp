//#include "io.hpp"
#include "afl3/Vector.hpp"
#include "afl3/Matrix.hpp"
#include "afl3/SparseVector.hpp"
#include <iostream>
#include <string>
#include <utility>

// include from 'Vector.hpp'
#include <vector>
#include <cassert>
#include <cmath>

// include from 'SparseVector.hpp'
#include <cassert>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <typeinfo>

void testing(std::string msg)
{
  std::cout << "---" << '\n';
  std::cout << msg << '\n';
  std::cout << "---" << '\n';
}

void space()
{
  std::cout << "-------" << '\n';
}
void diviede()
{space();}

void test_done()
{
  std::cout << "test done" << '\n';
}

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
    std::cout << "valid double: " << ss << '\n';
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
  testing("Testing Vector");
//  std::cout << "Testing Vector" << '\n';
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

  test_done();
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
  testing("Testing Matrix");
//  std::cout << "Testing Matrix" << '\n';
  Matrix<double> m1 = Matrix<double>(2,2);
  m1.prt_mx();

  double_test(m1(0,0), 0, "mx int");

  m1(0,0) = 1; // T& operator()(int i, int j) testing
  //m1(1,0) = 2;
  //m1(0,1) = 3;
  m1.prt_mx();
  double_test(m1(0,0),1, "assign");
  m1(1,1) = 3;
  m1.prt_mx();
  double_test(m1(1,1),3, "assign");
  m1.prt_mx();

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

  Matrix<double> mx1 = Matrix<double> (3,3);
  mx1.prt_mx();
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      mx1(i,j) = (i+1) * (j+1);
    }
  }
  space();
  mx1.prt_mx();
  space();
  Matrix<double> mx2 = mx1;
  mx2.prt_mx();

  test_done();


}

void run_sp()
{

  testing("Testing SparseVector");
//  std::cout << "Testing SparseVector" << '\n';
  SparseVector<double> sp0 = SparseVector<double>();
  SparseVector<double> lort = SparseVector<double>(10);

  int_test(0, sp0.size(), "Testing sp0 size");
  int_test(10, lort.size(), "Testing 'lort' size");

  std::cout << "--- run_test1 ----" << '\n';

  //std::cout << lort.nonZeroes() << '\n';
  int_test(0, sp0.nonZeroes(), "Testing sp0 nonZero elem's");
  int_test(0, lort.nonZeroes(), "Testing 'lort' nonZero elem's");

  std::cout << "adding values" << '\n';

  lort.setValue(5, 5.5);
  lort.setValue(7, 10.1);
  double_test(5.5, lort.getValue(5), "Testing assignment opr");
  double_test(10.1, lort.getValue(7), "Testing assignment opr");

  std::cout << "--- run_test2 ----" << '\n';

  std::cout << "make 2 new vecs, copy and new-new" << '\n';
  SparseVector<double> sp3 = SparseVector<double>(lort);
  SparseVector<double> sp4 = SparseVector<double>(15);

  double_test(5.5, sp3.getValue(5), "Testing ='s opr");
  double_test(10.1, sp3.getValue(7), "Testing ='s opr");

  int_test(0, sp4.nonZeroes(), "Testing sp4 nonZero elem's");
  int_test(15, sp4.size(), "Testing sp4 size ");

  int_test(2, sp3.nonZeroes(), "Testing sp3&'lort' nonZero elem's");


  space();
  space();
  space();
  lort.printsp();
  sp3.printsp();
  space();
  space();
  space();
  sp3 += sp3;

  /*SparseVector<double> sp9 = SparseVector<double>(10);
  SparseVector<double> spoo = SparseVector<double>(10);
  SparseVector<double> spoo2 = SparseVector<double>(10);
  sp9.setValue(5, 1);
  sp9.setValue(7, 1);
  sp9.setValue(2, 1);
  sp3.setValue(2, 1);

  //sp3 += sp9;
  spoo += spoo2;

  //sp3 += spoo;
*/

  sp3.printsp();
  double_test(11, sp3.getValue(5), "Testing ='s opr");
  double_test(20.2, sp3.getValue(7), "Testing ='s opr");
  space();

  //sp4.printsp();

  testing("-= opr's test");
  //sp3.setValue(5,5.6);
  //sp3.printsp();
  sp3 -= lort;
  double_test(5.5, sp3.getValue(5), "Testing ='s opr");
  double_test(10.1, sp3.getValue(7), "Testing ='s opr");
  //sp3.printsp();

  testing("vec with neg val's");
  SparseVector<double> sp_min = SparseVector<double>(10);
  sp_min.setValue(2, -5.1);
  sp_min.setValue(4, -1.0);
  sp_min.printsp();
  sp_min.setValue(2, 0.1);
  sp_min.printsp();
/*
  testing("+ opr");
  SparseVector<double> sp7 = sp0+lort;
  sp7.printsp();
  SparseVector<double> sp8 = sp4+sp3;
  sp8.printsp();
*/

  testing("- opr");
  SparseVector<int> v0 = SparseVector<int>(10);
  v0.setValue(1,1);
  v0.setValue(3,5);
  v0.printsp();
  SparseVector<int> v1 = SparseVector<int>(10);
  v1.setValue(1,1);
  v1.setValue(4,5);
  v1.setValue(8,6);
  v1.printsp();

  SparseVector<int> v2 = v1-v0;
  v2.printsp();

  v1.setValue(0,1);
  v1.printsp();

  test_done();
}
void run_sp_vec_mx_oprs()
{
  testing("Testing SparseVector, dense vector/matrix ops");

  Matrix<double> mx1 = Matrix<double> (3,3);
  mx1(0,0) = 1;
  mx1(0,1) = 2;
  mx1(0,2) = 3;
  mx1(1,0) = 1;
  mx1(1,1) = 2;
  mx1(1,2) = 3;
  mx1(2,0) = 1;
  mx1(2,1) = 2;
  mx1(2,2) = 3;

  testing("mult 3x3 matrix");
  mx1.prt_mx();

  SparseVector<double> sp1 = SparseVector<double>(2);
  testing("with sparse vector fo size 3");
  sp1.setValue(0,1);
  sp1.setValue(2,1);

  sp1.printsp();

  space();

  testing("column vise mult");
  Vector<double> v1 = sp1 * mx1; // should give vec{2,4,6}
  v1.vectorprint();
  testing("row vise mult");
  Vector<double> v2 = mx1 * sp1;  // should give vec{4,4,4}
  v2.vectorprint();


}

/*
void run_SPVec_Matrix()
{
  testing("vector times matrix opr's");
  Matrix<double> m1 = Matrix<double>(2,2);
  m1(0,0) = 1;  m1(0,1) = 2; m1(1,0) = 3; m1(1,1) = 4;
  SparseVector<double> spv1 = SparseVector<double>(10);
  spv1.setValue(1,5.0);
  spv1.setValue(3,4.5);
  spv1.setValue(7,7.5);
  Vector<double> Mx_Spv_pro = m1*spv1;
  //print_Vector(Mx_Spv_pro);
  Vector<double> Spv_Mx_pro = m1*spv1;
  //print_Vector(Spv_Mx_pro);

  test_done();
}*/

int main()
{
  run_vec();
  run_matrix();
  run_sp();
  run_sp_vec_mx_oprs();

  //run_SPVec_Matrix();

  //int_test()
  //run_vec();
  //run_matrix();
  //run_sp();

  return 0;
}
