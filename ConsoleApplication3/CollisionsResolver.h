#pragma once
#include <iostream>
#include "Asteroid.h"
#include <stdlib.h>
#include <list>

using namespace std;

struct CollisionInfo
{
	Asteroid *Asteroid;
	float CollisionTime;
};

class CollisionsResolver
{
private:
	list<Asteroid> currentAsteroids;
	double collisionAngle;
	double collisionTime;
	double velocityx1;
	double velocityx2;
	double velocityy1;
	double velocityy2;
	double xOnCollision1;
	double yOnCollision1;
	double xOnCollision2;
	double yOnCollision2;
	void CalcCollisionTime(Asteroid &asteroid1,
		Asteroid &asteroid2);
	void CalcCollisionCoordinates(Asteroid &asteroid1,
		Asteroid &asteroid2);
	void CalcCollisionAngel();
	void CalcVelocitiesOnCollision(Asteroid &asteroid1,
		Asteroid &asteroid2);
	void CalcVelocitiesAfterCollision(Asteroid &asteroid1,
		Asteroid &asteroid2);
	void CalcAnglesAfterCollision(Asteroid &asteroid1, Asteroid &asteroid2);
	bool PossibleCollision(Asteroid &asteroid1, Asteroid &asteroid2);
	CollisionInfo ClosestCollision(list<CollisionInfo> &possibleCollisions);
	void ResolveCollision(Asteroid &asteroid1,
		Asteroid &asteroid2);

public:
	void SetAsteroids(list<Asteroid> &asteroids);
	list<Asteroid> GetAsteroids()
	{
		return currentAsteroids;
	}
	void FindCollisions();
};
