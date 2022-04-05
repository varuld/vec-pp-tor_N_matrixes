//#include "io.hpp"
#include "sub_files/vector.hpp"
#include "sub_files/Matrix.hpp"
#include "sub_files/SparseVector.hpp"
#include <iostream>
#include <string>
#include <utility>

void testing(std::string msg)
{
  std::cout << "---" << '\n';
  std::cout << msg << '\n';
  std::cout << "---" << '\n';
}

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

  test_done();

}


void space()
{
  std::cout << "-------" << '\n';
}
void diviede()
{space();}
void run_sp()
{
  testing("Testing SparseVector");
//  std::cout << "Testing SparseVector" << '\n';
  SparseVector<double> sp0 = SparseVector<double>();
  SparseVector<double> lort = SparseVector<double>(10);

  std::cout << "--- run_test1 ----" << '\n';

  std::cout << lort.nonZeroes() << '\n';

  //unsigned int sp0_size{ sp0.size() };
  //unsigned int lort_size{ lort.size()};
  //int_test(10, lort_size, "size of sp_vec 'lort'");
  //int_test(0, sp0_size, "size of sp_vec 'sp0'");

  std::cout << "add values" << '\n';

  lort.setValue(5, 5.5);
  lort.setValue(7, 10.1);

  std::cout << "--- run_test2 ----" << '\n';

  std::cout << "is? " << lort.getValue(5) << '\n';

  lort.printsp();
  std::cout << "make 2 new vecs, copy and new-new" << '\n';
  SparseVector<double> sp3 = SparseVector<double>(lort);
  SparseVector<double> sp4 = SparseVector<double>(15);

  sp3.printsp();
  sp4.printsp();

  std::cout << "Sizes is; " << sp0.size() << "," << lort.size() << "," << sp3.size() << "," << sp4.size() << '\n';

  std::cout << "Non-zeroes is ; " << sp0.nonZeroes() << "," << lort.nonZeroes() << "," << sp3.nonZeroes() << "," << sp4.nonZeroes() << '\n';

  std::cout << "Index of first stored; " << lort.indexNonZero(0) << '\n';
  std::cout << "Value of first stored; " << lort.valueNonZero(0) << '\n';

  testing("+= opr's test");
  sp4 += lort;
  sp4.printsp();
  testing("-= opr's test");
  sp3.setValue(5,5.6);
  sp3.printsp();
  sp3 -= lort;
  sp3.printsp();

  testing("vec with neg val's");
  SparseVector<double> sp_min = SparseVector<double>(10);
  sp_min.setValue(2, -5.1);
  sp_min.setValue(4, -1.0);
  sp_min.printsp();
  sp_min.setValue(2, 0.1);
  sp_min.printsp();

  testing("+ opr");
  SparseVector<double> sp7 = sp0+lort;
  sp7.printsp();
  SparseVector<double> sp8 = sp4+sp3;
  sp8.printsp();

  testing("- opr");
  SparseVector<int> v0 = SparseVector<int>(10);
  v0.setValue(1,1);
  v0.setValue(3,5);
  v0.printsp();
  SparseVector<int> v1 = SparseVector<int>(11);
  v1.setValue(1,1);
  v1.setValue(4,5);
  v1.setValue(8,6);
  v1.printsp();

  SparseVector<int> v2 = v1-v0;
  v2.printsp();

  test_done();
}

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
}

int main()
{
  run_vec();
  run_matrix();
  run_sp();

  run_SPVec_Matrix();

  //int_test()
  //run_vec();
  //run_matrix();
  //run_sp();

  return 0;
}
