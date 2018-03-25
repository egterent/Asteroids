#pragma once
#include "Asteroid.h"
#include "MyMath.h"
#include "WindowSize.h"

class AsteroidsFactory
{
public:
	Asteroid NewAsteroid(int asteroidType);

private:	
	void CalcVAXY(double &v, double &a, int &x, int &y);
};
