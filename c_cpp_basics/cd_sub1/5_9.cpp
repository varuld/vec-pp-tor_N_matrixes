#include <iostream>
#include "5_9.h"

using namespace std;

double **mk_mx(int rows, int cols)
{
	/*
	function for dynamically allocate matrix arrays
	these matrixes are  n \times n
	the entries are double presision floats
	*/
	double **A = new double* [rows];
	for (int i=0; i<rows; i++)
	{
		A[i] = new double [cols];
	}
	return A;
}


void dlt_mx_t(double **A, int size)
{
	/*
	fruntion for dynamically delete mtrix arrays
	*/
	for (int i=0; i<size; i++)
	{
		delete[] A[i];
	}
	delete[] A;
}

double det_n3(double **A)
{
	double det_3 = 0;
	for (int i=0;i<3;i++)
	{
		det_3 += (A[0][i]*(A[1][(i+1)%3]*A[2][(i+2)%3]-A[1][(i+2)%3]*A[2][(i+1)%3]));
	}
	return det_3;
}

void sub_matrix(double **A_start, double *b, double **target_matrix, int choise)
{
	for (int i=0; i<3; i++)
	{
		for (int j=0;j<3;++j)
		{
			if  (j == choise)
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


void solve3by3(double **A, double *b, double *u)
{
	double det_A = det_n3(A);
	std::cout << det_A << '\n';

	double **tar = mk_mx(3,3);
	for (int i=0;i<3;++i)
	{
		sub_matrix(A, b, tar, i);
		double det = det_n3(tar);
		cout << det << '\n';
		u[i] = det / det_A;
	}
	dlt_mx_t(tar,3);
}
