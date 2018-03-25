#include "AsteroidsFactory.h"

Asteroid AsteroidsFactory::NewAsteroid(int asteroidType)
{
	int r, m, x, y;
	double v, a;
	
	switch (asteroidType)
	{
	case 0: r = 3 + rand() % 4;
		m = 6;
		break;
	case 1: r = 1 + rand() % 3;
		m = 11;
		break;
	case 2: r = 1 + rand() % 2;
		m = 22;
		break;
	}
	m *= MyMath::MyCube(r);
	CalcVAXY(v, a, x, y);
	return Asteroid(r, m, v, a, x, y);
}

void AsteroidsFactory::CalcVAXY(double &v, double &a, int &x, int &y)
{
	v = (double)(10 + rand() % 20) / 10;
	a = rand() % 360;	
	x = rand() % 2;
	if (x == 0)
	{
		y = rand() % WH;
		if (a > 90 && a < 270)
			x = WL;
	}
	else
	{
		x = rand() % WL;
		if (a > 90 && a < 270)
			y = WH;
		else
			y = 0;
	}
	(double)a *= 0.01745f;
}
