#pragma once
#include <iostream>
#include <stdlib.h>
#include <list>
#include "Asteroid.h"
#include "AsteroidsFactory.h"
#include "CollisionsResolver.h"

using namespace std;

class AsteroidsEditor
{
public:
	vector<CircleShape> GetShapes();
	void MakeAsteroids(int n);
	void AddAsteroidToCurrent();
	void NextXY();
private:
	AsteroidsFactory asteroidsFactory;
	CollisionsResolver collisionsResolver;
	list<Asteroid> allAsteroids;
	list<Asteroid> currentAsteroids;	
	void DeleteAsteroidsFromCurrent();
};
