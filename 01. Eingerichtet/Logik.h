#pragma once
#include <SFML/Graphics.hpp>
class Ball;
class Player;
class Engine;
class Schrift;

class Logik
{
private:
    int health;
    int score;
    int mx;
    int my;
    Ball& ball;
    Player& player;
    Engine& engine;
    Schrift& schrift;
    

public:
    Logik(Ball& b, Player& p, Engine& e, Schrift& s);
    void kollisionFenster();
    void kollisionSpieler();
    void punktestand();
};

