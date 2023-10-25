// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;
double S0(const int i, const int N)
{
	double s = 0;
	for (int k = i; k <= N; k++)
	{
		s += sin(1. * k) / (1 + cos(1. * k));
	}
	return s;
}
double S1(const int i, const int N, const int k)
{
	if (k > N)
		return 0;
	else
		return sin(1. * k) / (1 + cos(1. * k)) + S1(i, N, k + 1);
}
double S2(const int i, const int N, const int k)
{
	if (k < i)
		return 0;
	else
		return sin(1. * k) / (1 + cos(1. * k)) + S2(i, N, k - 1);
}
double S3(const int i, const int N, const int k, double t)
{
	t = t + sin(1. * k) / (1 + cos(1. * k));
	if (k >= N)
		return t;
	else
		return S3(i, N, k + 1, t);
}
double S4(const int i, const int N, const int k, double t)
{
	t = t + sin(1. * k) / (1 + cos(1. * k));
	if (k <= i)
		return t;
	else
		return S4(i, N, k - 1, t);
}
int main()
{
	int i = 1, N;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0(i, N) << endl;
	cout << "(rec up ++) S1 = " << S1(i, N, i) << endl;
	cout << "(rec up --) S2 = " << S2(i, N, N) << endl;
	cout << "(rec down ++) S3 = " << S3(i, N, i, 0) << endl;
	cout << "(rec down --) S4 = " << S4(i, N, N, 0) << endl;
	return 0;
}