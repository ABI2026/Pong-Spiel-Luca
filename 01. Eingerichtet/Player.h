#pragma once
#include <SFML/Graphics.hpp>
#include "Logik.h"

class Player
{
private:
	sf::RectangleShape player;

public:
	void zeichnePlayer();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	void move(float x, float y);
	sf::RectangleShape getPlayer();

};

