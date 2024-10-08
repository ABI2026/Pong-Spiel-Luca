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
