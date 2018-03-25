#include "AsteroidsEditor.h"


vector<CircleShape> AsteroidsEditor::GetShapes()
{
	vector<CircleShape> shapes;

	for (auto p : currentAsteroids)
	    shapes.push_back(p.GetShape());
	return shapes;
}

void AsteroidsEditor::MakeAsteroids(int n)
{
	if (n > 0)
	    for (int i = 0; i < n; i++)
		    allAsteroids.push_back(asteroidsFactory.NewAsteroid(rand() % 3));
}

void AsteroidsEditor::NextXY()
{
	if (!currentAsteroids.empty())
	{
		collisionsResolver.SetAsteroids(currentAsteroids);
		collisionsResolver.FindCollisions();
		currentAsteroids.clear();
		currentAsteroids = collisionsResolver.GetAsteroids();
		DeleteAsteroidsFromCurrent();
	}
}

void AsteroidsEditor::AddAsteroidToCurrent()
{
	if (!allAsteroids.empty())
	{
		int n = rand() % allAsteroids.size();
		auto p = allAsteroids.begin();
		for (int i = 0; i < n; i++)
			p++;
		currentAsteroids.push_back(*p);
	}	
}

void AsteroidsEditor::DeleteAsteroidsFromCurrent()
{
	if (!currentAsteroids.empty())
		currentAsteroids.remove_if([](Asteroid ast)
		{return ast.GetX() - 2 * ast.GetRadius() > WL || 
			ast.GetX() + 2 * ast.GetRadius() < 0 || 
			ast.GetY() - 2 * ast.GetRadius() > WH || 
			ast.GetY() + 2 * ast.GetRadius()  < 0; });
}


