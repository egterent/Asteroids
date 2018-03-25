#pragma once
#include "Asteroid.h"

class CollisionCalcs
{
	CollisionCalcs() {};
	~CollisionCalcs() {};
	double CollisionAngle(double x1, double x2, double y1, double y2);
	double AngleOnCollision(double angle, double collisionAngle);
	double collisionTime(int coord1, int coord2, int radius1, int radius2, double velocity1, double velocity2);
	double VelocityX(double velocity, double angle);
	double VelocityY(double velocity, double angle);
	double RadiusX(int radius, double angle);
	double CollisionCoordinate(int currentCoordinate, double velocity, double collisionTime);	
};
