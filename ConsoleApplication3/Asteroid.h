#pragma once
#include "MyMath.h"
#include <SFML\Graphics.hpp>


using namespace sf;

class Asteroid
{
private:
	CircleShape shape;
	int radius;
	int mass;
	double velocity;
	double angle;
	double currentx;
	double currenty;
	bool collisionHappens;

public:
	Asteroid(int r, int m, double v, double a, int x, int y);
	double GetX()
	{ return currentx + radius; }
	double GetY()
	{ return currenty - radius; }
	int GetRadius()
	{ return radius; }
	int GetMass()
	{ return mass; }
	double GetVelocity()
	{ return velocity; }
	double GetAngle()
	{ return angle; }
	double GetVelocityX()
	{ return velocity * cos(angle); }
	double GetVelocityY()
	{ return velocity * sin(angle); }
	void SetX(double newX)
	{ currentx = newX - radius; }
	void SetY(double newY)
	{ currenty = newY - radius; }
	void SetVelocity(double newVelocity)
	{ velocity = newVelocity; }
	void SetAngle(double newAngle)
	{ angle = newAngle; }
	void NextXY();
	CircleShape GetShape();
	bool CollisionHappens()
	{ return collisionHappens; }
	void ChangeCollisionState(bool collisionState)
	{ collisionHappens = collisionState; }
};