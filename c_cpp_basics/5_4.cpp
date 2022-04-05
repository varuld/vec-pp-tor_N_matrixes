#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

void std_dev(double *A, int N, double sd)
{
	//double sd;

	// double N = sizeof(A)/sizeof(A[0]);

	double agv_sum = 0.0;

	for (int i=0; i<N; i++)
	{
		agv_sum += A[i];
	}

	double avg = ((double)(agv_sum)) / ((double)(N));

	double sig_sum = 0.0;
	double N_1 = N - 1.0;

	for (int j=0; j<N; j++)
	{
		sig_sum += pow( (A[j] - avg), 2);
	}

	sig_sum /= N_1;
	sd = sqrt(sig_sum);
}
double calc_mean(double a[], int length)
{
	double avg_sum = 0.0;
	for (int i=0; i<length; i++)
	{
		avg_sum += a[i];
	}
	return avg_sum / length;
}

double calc_std(double a[], int length)
{
	if (length == 1 )
	{
		return 0;
	}
	double avg = calc_mean(a, length);
	double sig_sum = 0.0;

	for (int i=0;i<length; i++)
	{
		sig_sum += pow((a[i] - avg),2);
	}

	sig_sum /= (length-1);
	return sqrt(sig_sum);

}
