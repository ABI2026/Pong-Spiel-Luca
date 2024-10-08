#pragma once
#include <SFML/Graphics.hpp>
class Engine
{
private:
	sf::RenderWindow meinSpieleFenster;

public:
	void erstelleFenster();
	bool isOpen();
	void clear();
	void display();
	sf::RenderWindow& getWindow();
	void pollEvent();
};

