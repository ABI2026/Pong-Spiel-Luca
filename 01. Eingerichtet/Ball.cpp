#include "Ball.h"

Ball::Ball()
{
}

Ball::~Ball()
{

}

void Ball::zeichneBall()
{
    if (!ballTexture.loadFromFile("ball.png")) // Ersetze mit dem Pfad zu deinem Bild
    {
        return; // Fehler beim Laden der Textur
    }

    ball.setTexture(ballTexture);
    ball.setPosition(145, 100);
    ball.setScale(0.08f, 0.08f);
}

void Ball::getPosition()
{
    ball.getPosition();
}
