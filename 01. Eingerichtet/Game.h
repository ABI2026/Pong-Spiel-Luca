#pragma once
#include <SFML/Graphics.hpp>
#include "Schrift.h"
#include "Ball.h"
#include "Engine.h"
#include "Logik.h"
#include "Player.h"
#include <iostream>

class Game
{
private:
	Schrift& schrift;
	Ball& ball;
	Engine& engine;
	Logik& logik;
	Player& player;

public:
	Game(Schrift& s, Ball& b, Engine& e, Logik& l, Player& p);

	void run();
};

