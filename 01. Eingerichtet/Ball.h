#include <SFML/Graphics.hpp>
#include "Logik.h"

#pragma once
class Ball
{
private:
	sf::Texture ballTexture;
	sf::Sprite ball;
	int speed;

public:
	Ball();
	~Ball(); //falls ich Plane bestimmte Bälle später zu löschen

	void zeichneBall();
	void getPosition();
};

