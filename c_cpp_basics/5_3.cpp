#include <iostream>
using namespace std;

void swap_pointer(double *a, double *b)
{
	double p_swp = *a;
	*a = *b;
	*b = p_swp;
}

void swap_ref(double &a, double &b)
{
	double swp = a;
	a = b;
	b = swp;
}
