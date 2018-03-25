#include <SFML\Graphics.hpp>
#include "WindowSize.h"
#include "AsteroidsEditor.h"
#include <Windows.h>

using namespace sf;

int main()
{
	RenderWindow renderWindow(VideoMode(WL, WH), "Test");
	AsteroidsEditor asteroidsEditor;

	srand(time(0));
	asteroidsEditor.MakeAsteroids(100);
	while (renderWindow.isOpen())
	{
		Event event;

		while (renderWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
				renderWindow.close();
		}		
		if (rand() % 3 == 2)
		{
			asteroidsEditor.AddAsteroidToCurrent();
		}
		asteroidsEditor.NextXY();

		vector<CircleShape> asteroids = asteroidsEditor.GetShapes();

		renderWindow.clear();
		for (auto asteroid : asteroids)
            renderWindow.draw(asteroid);
		renderWindow.display();
	}
	return 0;
}

