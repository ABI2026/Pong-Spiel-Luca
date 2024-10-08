#include "Player.h"

void Player::zeichnePlayer()
{
    player.setSize(sf::Vector2f(40, 10));
    player.setPosition(130, 400);
    player.setFillColor(sf::Color::Red);
}

sf::Vector2f Player::getPosition()
{
    return player.getPosition();
}

sf::Vector2f Player::getSize()
{
    return player.getSize();
}

void Player::move(float x, float y)
{
    player.move(x, y);
}

sf::RectangleShape Player::getPlayer()
{
    return player;
}
