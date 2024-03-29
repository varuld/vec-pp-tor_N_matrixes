#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include "5_6.h"
using namespace std;

void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols)
{
	assert(ACols == BRows);

	for (int i = 0; i<ARows ; i++)
	{
		for (int j = 0; j<BCols; j++)
		{
			for (int k = 0; k <ACols; k++)
			{
				res[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}


void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols)
{
	assert(ACols == BRows);

	for (int i = 0; i<BCols; i++)
	{
		for (int j = 0; j<ACols; j++)
		{
				res[i] += B[i][j] * A[j];
		}
	}
}


void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows)
{
	assert(ACols == BRows);

	for (int i = 0; i<ARows; i++)
	{
		for (int j = 0; j<ACols; j++)
		{
				res[i] += A[i][j] * B[j];
		}
	}
}


void Multiply(double **res, double scalar, double **B, int BRows, int BCols)
{
	for (int i=0;i<BRows;i++)
	{
		for (int j=0;j<BCols;j++)
		{
			res[i][j] = B[i][j] * scalar;
		}
	}
}

void Multiply(double **res, double **B, double scalar, int BRows, int BCols)
{
	Multiply(res, scalar, B, BRows, BCols);
}
