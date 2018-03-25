#include "CollisionsHalper.h"

double CollisionsHalper::CollisionAngle(double x1, double x2, double y1, double y2)
{
	return atan((y2 - y1) / (x2 - x1));
}

double CollisionsHalper::VelocityX(double velocity, double angle)
{
	return velocity * cos(angle);
}

double CollisionsHalper::VelocityY(double velocity, double angle)
{
	return velocity * sin(angle);
}

double CollisionsHalper::RadiusX(int radius, double angle)
{
	return radius * cos(angle);
}
double CollisionsHalper::CollisionCoordinate(double currentCoordinate, double velocity, double collisionTime)
{
	return currentCoordinate + velocity * collisionTime;
}
double CollisionsHalper::Velocity1XAfterCollision(double velocity1, double velocity2, double mass1, double mass2)
{
	return ((mass1 - mass2) * velocity1 + 2 * mass2 * velocity2) / (mass1 + mass2);
}

double CollisionsHalper::Velocity2XAfterCollision(double velocity1, double velocity2, double mass1, double mass2)
{
	return (2 * mass1 * velocity1 - (mass2 - mass1) * velocity1) / (mass1 + mass2);
}

double CollisionsHalper::VelocityAfterCollision(double velocityX, double velocityY)
{
	return sqrt(velocityX * velocityX + velocityY * velocityY);
}

double CollisionsHalper::AngleOnCollision(double angle, double collisionAngle)
{
	return angle - collisionAngle;
}

double CollisionsHalper::AngleAfterCollision(double velocityX, double velocityY)
{
	return atan(velocityY / velocityX);
}

double CollisionsHalper::AngleAfterCollisionForScreen(double angle, double collisionAngle)
{
	return angle + collisionAngle;
}

double CollisionsHalper::CollisionTime(double x1, double x2, double y1, double y2, double radius1, double radius2, double velocityx1, double velocityx2, double velocityy1, double velocityy2)
{
	double t, t1, t2, a, b, c, d;
	double a1, a2, b1, b2;
	a1 = velocityx2 - velocityx1;
	a2 = velocityy2 - velocityy1;
	a = MyMath::A(a1, a2);
	b1 = x2 - x1;
	b2 = y2 - y1;
	b = MyMath::HalfB(a1, a2, b1, b2);
	c = MyMath::C(b1, b2, radius1 + radius2);
	d = MyMath::HalfD(a, b, c);
	if (a != 0)
	{
		t1 = (-1 * b - d) / a;
		t2 = (-1 * b + d) / a;
		if (t1 > 0)
		{
			t = t1;
		}
		else
		{
			t = t2;
		}
	}
	else
	{
		if (b != 0)
		{
			t = -1 * c / (2 * b);
		}
		else
		{
			t = 0;
		}
	}
	return t;
}

double CollisionsHalper::CoordinateWithTime(double x, double velocityx, double collisionTime)
{
	return x + velocityx * collisionTime;
}
