#include "CollisionsResolver.h"
#include "CollisionsHalper.h"

using namespace CollisionsHalper;

void CollisionsResolver::SetAsteroids(list<Asteroid> &asteroids)
{
	if (!currentAsteroids.empty())
	{
		currentAsteroids.clear();
	}
	currentAsteroids = asteroids;
}

void CollisionsResolver::FindCollisions()
{
	if (!currentAsteroids.empty())
	{
		list<Asteroid>::iterator p = currentAsteroids.begin();
		list<Asteroid>::iterator pend1 = currentAsteroids.end();

		while (p != pend1)
		{
			p->ChangeCollisionState(false);
			p++;
		}
		if (currentAsteroids.size() > 1)
		{
			struct CollisionInfo collisionInfo;

			p = currentAsteroids.begin();
			list<Asteroid>::iterator p1, p2, pend2 = pend1--;
			while (p != pend1)
			{
				if (!p->CollisionHappens())
				{
					list<CollisionInfo> possibleCollisions;
					p1 = p;
					p2 = ++p;
					while (p2 != pend2)
					{
						if (PossibleCollision(*p1, *p2))
						{
							CalcCollisionTime(*p1, *p2);
							if (collisionTime > 0 && collisionTime <= 1)
							{
								collisionInfo.Asteroid = &(*p2);
								collisionInfo.CollisionTime = collisionTime;
								possibleCollisions.push_back(collisionInfo);
							}                                   							
						}
						p2++;
					}
					if (!possibleCollisions.empty())
					{
						if (possibleCollisions.size() > 1)
						{
							collisionInfo = ClosestCollision(possibleCollisions);
						}
						collisionTime = collisionInfo.CollisionTime;
						ResolveCollision(*p1, *collisionInfo.Asteroid);
					}
				}
				else
				{
					p++;
				}
			}
		}
		p = currentAsteroids.begin();
		pend1 = currentAsteroids.end();
		while (p != pend1)
		{
			if (!p->CollisionHappens())
			{
				p->NextXY();
			}
			p++;
		}
	}
}

void CollisionsResolver::ResolveCollision(Asteroid &asteroid1,
	Asteroid &asteroid2)
{
	CalcCollisionCoordinates(asteroid1, asteroid2);
	CalcCollisionAngel();
	CalcVelocitiesOnCollision(asteroid1, asteroid2);
	CalcVelocitiesAfterCollision(asteroid1, asteroid2);
	CalcAnglesAfterCollision(asteroid1, asteroid2);
	asteroid1.ChangeCollisionState(true);
	asteroid2.ChangeCollisionState(true);
}

void CollisionsResolver::CalcCollisionTime(Asteroid &asteroid1, Asteroid &asteroid2)
{
	collisionTime = CollisionTime(asteroid1.GetX(), asteroid2.GetX(), 
		asteroid1.GetY(), asteroid2.GetY(),
		asteroid1.GetRadius(), asteroid2.GetRadius(), 
		asteroid1.GetVelocityX(), asteroid2.GetVelocityX(), 
		asteroid1.GetVelocityY(), asteroid2.GetVelocityY());
}

void CollisionsResolver::CalcCollisionCoordinates(Asteroid &asteroid1, Asteroid &asteroid2)
{
	xOnCollision1 = CollisionCoordinate(asteroid1.GetX(), asteroid1.GetVelocityX(), collisionTime);
	yOnCollision1 = CollisionCoordinate(asteroid1.GetY(), asteroid1.GetVelocityY(), collisionTime);
	xOnCollision2 = CollisionCoordinate(asteroid2.GetX(), asteroid2.GetVelocityX(), collisionTime);
	yOnCollision2 = CollisionCoordinate(asteroid2.GetY(), asteroid2.GetVelocityY(), collisionTime);
	asteroid1.SetX(xOnCollision1);
	asteroid1.SetY(yOnCollision1);
	asteroid2.SetX(xOnCollision2);
	asteroid2.SetY(yOnCollision2);
}

void CollisionsResolver::CalcCollisionAngel()
{
	collisionAngle = CollisionAngle(xOnCollision1, xOnCollision2, yOnCollision1, yOnCollision2);
}

void CollisionsResolver::CalcVelocitiesOnCollision(Asteroid &asteroid1,
	Asteroid &asteroid2)
{
	auto angleOnCollision1 = AngleOnCollision(asteroid1.GetAngle(), collisionAngle);
	auto angleOnCollision2 = AngleOnCollision(asteroid2.GetAngle(), collisionAngle);
	velocityx1 = VelocityX(asteroid1.GetVelocity(), angleOnCollision1);
	velocityy1 = VelocityY(asteroid1.GetVelocity(), angleOnCollision1);
	velocityx2 = VelocityX(asteroid2.GetVelocity(), angleOnCollision2);
	velocityy2 = VelocityY(asteroid2.GetVelocity(), angleOnCollision2);
}

void CollisionsResolver::CalcVelocitiesAfterCollision(Asteroid &asteroid1, Asteroid &asteroid2)
{
	velocityx1 = Velocity1XAfterCollision(velocityx1, velocityx2, asteroid1.GetMass(), asteroid2.GetMass());
	velocityx2 = Velocity1XAfterCollision(velocityx1, velocityx2, asteroid1.GetMass(), asteroid2.GetMass());
	asteroid1.SetVelocity(VelocityAfterCollision(velocityx1, velocityy1));
	asteroid2.SetVelocity(VelocityAfterCollision(velocityx2, velocityy2));
}

void CollisionsResolver::CalcAnglesAfterCollision(Asteroid &asteroid1, Asteroid &asteroid2)
{
	auto angleAfterCollision1 = AngleAfterCollision(velocityx1, velocityy1);
	auto angleAfterCollision2 = AngleAfterCollision(velocityx2, velocityy2);
	asteroid1.SetAngle(AngleAfterCollisionForScreen(angleAfterCollision1, collisionAngle));
	asteroid2.SetAngle(AngleAfterCollisionForScreen(angleAfterCollision2, collisionAngle));
}

bool CollisionsResolver::PossibleCollision(Asteroid & asteroid1, Asteroid & asteroid2)
{
	float MinDistance = asteroid1.GetVelocity() + asteroid2.GetVelocity() + asteroid1.GetRadius() + asteroid2.GetRadius();
	return (abs(asteroid1.GetX() - asteroid2.GetX()) <= MinDistance &&
		abs(asteroid1.GetY() - asteroid2.GetY()) <= MinDistance);
}

CollisionInfo CollisionsResolver::ClosestCollision(list<CollisionInfo> &possibleCollisions)
{
	list<CollisionInfo>::iterator p = possibleCollisions.begin();
	list<CollisionInfo>::iterator pend = possibleCollisions.end();
	struct CollisionInfo closestCollision;
	
	closestCollision = *p;
	p++;
	while (p != pend)
	{
		if (closestCollision.CollisionTime > p->CollisionTime)
		{
			closestCollision = *p;
		}
		else
		{
			if (p->Asteroid->GetMass() / closestCollision.Asteroid->GetMass() > 3 &&
				p->CollisionTime / closestCollision.CollisionTime < 1.2f)
			{
				closestCollision = *p;
			}
		}
		p++;
	}

	return closestCollision;
}


