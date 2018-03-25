#include "CollisionCalcs.h"

void CollisionCalcs::CalcCollisionCoordinates()
{
	double velocityX1, velocityX2;
	velocityX1 = VelocityX((*asteroid1).GetVelocity, (*asteroid1).GetAngle);
	velocityX2 = VelocityX((*asteroid2).GetVelocity, (*asteroid2).GetAngle);
	collisionTime = 
	collisionX1 = CollisionCoordinate((*asteroid1).GetX, velocityX1);
	collisionX2 = CollisionCoordinate((*asteroid2).GetX, velocityX2);
	collisionY1 = CollisionCoordinate((*asteroid1).GetY, VelocityY((*asteroid1).GetVelocity, (*asteroid1).GetAngle));
	collisionY2 = CollisionCoordinate((*asteroid2).GetY, VelocityY((*asteroid2).GetVelocity, (*asteroid2).GetAngle));
}

double CollisionCalcs::CollisionAngle(double x1, double x2, double y1, double y2)
{
	return atan((y2 - y1) / (x2 - x1));
}

double CollisionCalcs::VelocityX(double velocity, double angle)
{
	return velocity * cos(angle);
}

double CollisionCalcs::VelocityY(double velocity, double angle)
{
	return velocity * sin(angle);
}

double CollisionCalcs::RadiusX(int radius, double angle)
{
	return radius * cos(angle);
}

double CollisionCalcs::CollisionCoordinate(int currentCoordinate, double velocity, double collisionTime)
{
	return currentCoordinate + velocity * collisionTime;
}

double CollisionCalcs::AngleOnCollision(double angle, double collisionAngle)
{	
	return angle - collisionAngle;
}

double CollisionCalcs::collisionTime(int coord1, int coord2, int radius1, int radius2, double velocity1, double velocity2)
{
	return abs((coord1 - radius1) - (coord2 - radius2))
		/ (velocity1 + velocity2);
}
