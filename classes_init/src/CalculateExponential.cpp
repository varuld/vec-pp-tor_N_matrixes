#include "CalculateExponential.hpp"
#include <cmath>
#include <cassert>
/*
double rec_factorial(double n)
{

	if(n > 1)
		return n * rec_factorial(n-1);
	else
		return 1.0;
}

ComplexNumber **Id_matrix(int n)
{

	ComplexNumber **I_mx = mk_mx(n,n);
	for( int i = 0; i < n; ++i )
	{
		for (int j=0;j<n;j++)
		{
			if (i==j){
				I_mx[i][j] = 1.0;}
			else{
				I_mx[i][j] = 0.0;}
		}
	}
	return I_mx;
}


ComplexNumber **comp_mx_mlt(ComplexNumber **A, ComplexNumber **B, int N_A, int N_B)
{

	assert(N_A == N_B);

	ComplexNumber **C = mk_mx(N_A, N_B);

	// i use N_A as the general size var
	for (int i = 0; i<N_A; i++)
		for (int j = 0; j<N_A; j++)
			for (int k = 0; k < N_A; ++k)
				{
					C[i][j] = (A[i][k]) * (B[k][j]);
				}
	return C;
}
ComplexNumber **comp_mx_add(ComplexNumber **A, ComplexNumber **B, int N_A, int N_B)
{

	ComplexNumber **C = mk_mx(N_A, N_B);

	for (int i = 0; i<N_A; i++)
		for (int j = 0; j<N_B; j++)
			{
				C[i][j] = (A[i][j]) + (B[i][j]);
			}
	return C;
}
ComplexNumber **mlt_mx_scalar(ComplexNumber scalar, ComplexNumber **mx, int size)
{

	ComplexNumber **scalar_mx = mk_mx(size, size);
	for (int i=0;i<size;i++)
		for (int j=0;j<size;j++)
		{
			scalar_mx[i][j] = scalar * mx[i][i];
		}

	return scalar_mx;
}
ComplexNumber **matrix_cp(ComplexNumber **A, int rows, int cols)
{
	ComplexNumber **Matrix = mk_mx(rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			Matrix[i][j] = ComplexNumber(A[i][j]);
		}
	}
	return Matrix;
}

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
	ComplexNumber **Id_matrix = Id_matrix(3);
  for (int i=1;i<nMax;i++)
  {
    ComplexNumber **tmp = matrix_cp(A,3,3);
    for (int j=1;j<i;j++)
    {
			if(i==1){ tmp = comp_mx_add(Id_matrix,A,3,3); dlt_comp_mx(Id_matrix,3); }

      // tmp = comp_mx_mlt(tmp,A,3,3);
    }
    double fcaf=( ((double)1) / rec_factorial((double)i));
    tmp = mlt_mx_scalar(fcaf, tmp, 3);
    res = comp_mx_add(res,tmp,3,3);
  }
}
void printMatrix(ComplexNumber **A, int rows, int cols) {
	for (int i=0; i<rows; i++)
	{
		for (size_t j = 0; j < cols; j++) {
			std::cout << A[i][j] << '\t';
		}
		std::cout << '\n';
	}
}
void matrix_add()
{

}
void matrix_div() // gange med resiproc factorial
{

}
void matrix_mult()
{

}
*/
void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res)
{
	ComplexNumber **I[3] {
  new ComplexNumber[3] {1,0,0},
  new ComplexNumber[3] {0,1,0},
  new ComplexNumber[3] {0,0,1}
	};	
}
void printMatrix(ComplexNumber **A, int rows, int cols)
{

}
