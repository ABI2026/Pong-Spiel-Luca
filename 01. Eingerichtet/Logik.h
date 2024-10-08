#pragma once
#include <SFML/Graphics.hpp>
class Ball;
class Player;

class Logik
{
private:
    int health;
    int score;
    int mx;
    int my;
    Ball& ball;
    Player& player;
    

public:
    Logik(Ball& b, Player& p);
    void kollisionFenster();
    void kollisionSpieler();
};

