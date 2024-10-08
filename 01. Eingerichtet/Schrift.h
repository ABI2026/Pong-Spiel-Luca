#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Logik.h"
class Schrift
{
private:
	sf::Font font;
	sf::Text text;

public:
	void schriftArt();
	void label(int score);
};

