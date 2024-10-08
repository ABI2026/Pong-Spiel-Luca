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
	~Ball(); //falls ich Plane bestimmte B�lle sp�ter zu l�schen

	void zeichneBall();
	sf::Vector2f getPosition();
	int getSpeed();
	sf::FloatRect getGloubalBounds();
	void setPosition(float x, float y);
};

