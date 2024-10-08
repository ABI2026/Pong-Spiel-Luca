#include "Ball.h"
#include <iostream>

Ball::Ball()
{
    zeichneBall();
    speed = 3;
}

Ball::~Ball()
{

}

void Ball::zeichneBall()
{
    if (!ballTexture.loadFromFile("ball.png")) // Ersetze mit dem Pfad zu deinem Bild
    {
        return; // Fehler beim Laden der Textur
        std::cout << "Fehler" << std::endl;
    }
    else
    {
        std::cout << "Wurde gelanden" << std::endl;
    }

    ball.setTexture(ballTexture);
    ball.setPosition(145, 100);
    ball.setScale(0.08f, 0.08f);

    std::cout << "Ball Position: " << ball.getPosition().x << ", " << ball.getPosition().y << std::endl;
    std::cout << "Ball Scale: " << ball.getScale().x << ", " << ball.getScale().y << std::endl;
    std::cout << "Ball Global Bounds: " << ball.getGlobalBounds().width << "x" << ball.getGlobalBounds().height << std::endl;

}

sf::Vector2f Ball::getPosition()
{
    return ball.getPosition();
}

int Ball::getSpeed()
{
    return speed;
}

sf::FloatRect Ball::getGloubalBounds()
{
    return ball.getGlobalBounds();
}

void Ball::setPosition(float x, float y)
{
    ball.setPosition(x, y);
}

void Ball::move(float x, float y)
{
    ball.move(x, y);
}

sf::Sprite Ball::getSprite()
{
    return ball;
}
