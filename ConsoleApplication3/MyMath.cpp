#include "MyMath.h"

float MyMath::MyRound(double x)
{
	return ((x - floor(x)) * 10) < 5 ? (float)((int)floor(x)) : (float)((int)ceil(x));
}

double MyMath::MySqr(double x)
{
	double s = x;
	s *= x;
	return s;
}

int MyMath::MyCube(int x)
{
	int s = x;
	s *= x;
	s *= x;
	return s;
}

double MyMath::A(double a1, double a2)
{
	return MySqr(a1) + MySqr(a2);
}

double MyMath::HalfB(double a1, double a2, double b1, double b2)
{
	return a1 * b1 + a2 * b2;
}

double MyMath::C(double b1, double b2, double c1)
{
	return b1 * b2 - c1;
}

double MyMath::HalfD(double a, double b, double c)
{
	return sqrt(MySqr(b) - a * c);
}
