#include<iostream>
#include<cmath>
#include "2_6.h"
using namespace std;

double df(double x)
{
	return 3.0*pow(x,2) + exp(x);
}
double f(double x)
{
	return pow(x,3) + exp(x) - 5.0;
}


double newton_Raphson(double initialGuess, double epsilon = 1.0e-6)
{
	double x_0 = initialGuess;
	double x_n = x_0 - f(x_0) / df(x_0);

	while ( fabs(x_n - x_0) >= epsilon)
	{
		x_0 = x_n;
		x_n = x_0 - f(x_0) / df(x_0);
	}
	// cout << "value is " << x << endl;
	return x_n;
}
