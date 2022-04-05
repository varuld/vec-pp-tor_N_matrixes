#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include "3_3.h"
using namespace std;

void implicit_Euler(int n)
{
	double N = n - 1;
	double h =  1/N;
	double *y = new double[n]; // liste
	y[0] = 1;
	double x = 0;

	ofstream write_file;
	write_file.open("xy.dat");
	assert(write_file.is_open());

	write_file << x << "," << y[0] << endl;

	for (int i=1; i<n; i++)
	{
		x = i*h;
		y[i] = y[i-1] / (h + 1.0);
		write_file << x << "," << y[i] << endl;
	}
	write_file.close();

	delete[] y;
}
