#include "asteroid.h"


Asteroid::Asteroid(int r, int m, double v, double a, int x, int y)
{
	radius = r;
	mass = m;
	velocity = v;
	angle = a; 
	currentx = x;
	currenty = y;
	shape.setRadius((float)r);
	shape.setFillColor(Color::White);
}

void Asteroid::NextXY()
{
	currentx += velocity * cos(angle);
	currenty += velocity * sin(angle);
}

CircleShape Asteroid::GetShape()
{
	shape.setPosition(MyMath::MyRound(currentx - radius), MyMath::MyRound(currenty - radius));
	return shape;
}
