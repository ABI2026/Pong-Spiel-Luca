#pragma once
#include <SFML/Graphics.hpp>
#include "Logik.h"

class Player
{
private:
	sf::RectangleShape player;

public:
	void zeichnePlayer();
	void getPosition();
};

