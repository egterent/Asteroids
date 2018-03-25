#pragma once
#include <iostream>
#include "MyMath.h"
#include "WindowSize.h"

namespace CollisionsHalper
{
	double CollisionAngle(double x1, double x2, double y1, double y2);	

	double VelocityX(double velocity, double angle);
	
	double VelocityY(double velocity, double angle);
	
	double RadiusX(int radius, double angle);
	
	double CollisionCoordinate(double currentCoordinate, double velocity, double collisionTime);
	
	double Velocity1XAfterCollision(double velocity1, double velocity2, double mass1, double mass2);
	
	double Velocity2XAfterCollision(double velocity1, double velocity2, double mass1, double mass2);
	
	double VelocityAfterCollision(double velocityX, double velocityY);	
	
	double AngleOnCollision(double angle, double collisionAngle);	

	double AngleAfterCollision(double velocityX, double velocityY);

	double AngleAfterCollisionForScreen(double angle, double collisionAngle);
	
	double CollisionTime(double x1, double x2, double y1, double y2, double radius1, double radius2, double velocityx1, double velocityx2, double velocityy1, double velocityy2);
	
	double CoordinateWithTime(double x, double velocityx, double collisionTime);

};
