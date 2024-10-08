#include "Engine.h"

void Engine::erstelleFenster()
{
	meinSpieleFenster.create(sf::VideoMode(300, 500), "Pong");
	meinSpieleFenster.setFramerateLimit(30);
}

bool Engine::isOpen()
{
	return meinSpieleFenster.isOpen();
}

void Engine::clear()
{
	meinSpieleFenster.clear();
}

void Engine::display()
{
	meinSpieleFenster.display();
}

sf::RenderWindow& Engine::getWindow()
{
	return meinSpieleFenster;
}

void Engine::pollEvent()
{
	sf::Event event;

	while(meinSpieleFenster.pollEvent(event))
	{
	
	}
}

