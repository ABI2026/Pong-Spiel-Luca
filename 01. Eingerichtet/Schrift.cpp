#include "Schrift.h"

void Schrift::schriftArt()
{
	font.loadFromFile("fonts/arial.ttf");
}

void Schrift::label(int score)
{
	text.setFont(font);
	text.setCharacterSize(30);
	text.setString(std::to_string(score));
}

void Schrift::healthAnzeige(int health)
{
	healthText.setFont(font);
	healthText.setCharacterSize(30);
	healthText.setPosition(0, 40);
	healthText.setString("Health: " + std::to_string(health));
}

void Schrift::updateHealth(int health)
{
	healthText.setString("Health: " + std::to_string(health));
}

sf::Text Schrift::getText()
{
	return text;
}

sf::Text Schrift::getHealthtext()
{
	return healthText;
}
