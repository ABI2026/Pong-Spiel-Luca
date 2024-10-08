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
	sf::Text healthText;

public:
	void schriftArt();
	void label(int score);
	void healthAnzeige(int health);
	void updateHealth(int health);
	sf::Text getText();
	sf::Text  getHealthtext();
};

