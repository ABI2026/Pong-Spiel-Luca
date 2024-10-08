#include "Player.h"

void Player::zeichnePlayer()
{
    player.setSize(sf::Vector2f(40, 10));
    player.setPosition(130, 400);
    player.setFillColor(sf::Color::Red);
}

void Player::getPosition()
{
    player.getPosition();
}
