#include <iostream>
#include <cmath>
using namespace std;
#include "5_10.h"

double **mk_mx_q(int rows, int cols)
{
	/*
	function for dynamically allocate matrix arrays
	these matrixes are  n \times m
	the entries are double presision floats
	output: - matrix (A): The pointer to the matrix
	*/
	double **A = new double* [rows];
	for (int i=0; i<rows; i++)
	{
		A[i] = new double [cols];
	}
	return A;
}
void dlt_mx_tq(double **A, int size)
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
void printarray(double **A, int rows, int cols)
{
	/*
	function to print an array
	*/
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << A[i][j] << "\t";
		}
	cout << endl;
	}
}
void row_ex(double **Mx, int row_from, int row_to)
{
  double *tmp = Mx[row_from];
  Mx[row_from] = Mx[row_to];
  Mx[row_to] = tmp;
}
void row_mlt(double **M, int row_mlt, double scalar, int n)
{
  for (int i=0; i<=n; i++)
  {
    M[row_mlt][i] *= scalar;
  }
}
void row_add(double **M, int row_ad_target, int row_ad_misile, double scalar, int n) {
  for (int i=0; i<=n; i++)
  {
    M[row_ad_target][i] += M[row_ad_misile][i] * scalar;
  }
}
void aug_matrix(double **A_start, double *b, double **target_matrix, int size)
{
	for (int i=0; i<size; i++)
	{
		for (int j=0;j<=size;++j)
		{
			if  (j == size)
			{
				target_matrix[i][j] = b[i];
			}
			else
			{
				target_matrix[i][j] = A_start[i][j];
			}
		}
	}
}
void guassian_elimination(double **A, double *b, double *u, int n)
{
  double **target = mk_mx_q(n,(n+1));
  aug_matrix(A, b, target, n);
  for (int i=0; i<n;i++)
  {
    int max_entry;
    max_entry = i;
    for (int j=i+1; j<n;j++)
    {
      if (fabs(target[j][i]) > fabs(target[max_entry][i]))
      {
        max_entry = j;
      }
    }
    if ( max_entry != i)
    {
      row_ex(target, max_entry, i);
    }
    for (int j=i+1;j<n;++j){
      double null_konst = - target[j][i] / target[i][i];
      row_add(target, j, i, null_konst, n);
    }
    if (target[i][i] != 1)
    {
      row_mlt(target, i, (1/target[i][i]), n);
    }
    for (int j=i-1; j>=0; j--)
    {
      row_add(target, j, i, -target[j][i], n);
    }
  }
  for (int i=0;i< n;i++)
  {
    u[i] = target[i][n];
  }
  dlt_mx_tq(target, n);
}
