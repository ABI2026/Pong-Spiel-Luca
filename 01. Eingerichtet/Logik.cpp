#include "Logik.h"
#include <iostream>


Logik::Logik(Ball& b, Player& p) : ball(b), player(p)
{

}

void Logik::kollisionFenster()
{
    sf::Vector2f playerPos = player.getPosition();
    sf::Vector2f ballPos = ball.getPosition();
    sf::Vector2f playerPos = player.getPosition();

    // Kollision mit den Fenstergrenzen
    if (ballPos.x <= 0)
    {
        mx = speed;
    }
    else if (ballPos.x >= 300 - ball.getGlobalBounds().width)
    {
        mx = -speed;
    }

    if (ballPos.y <= 0)
    {
        my = speed;
    }
    else if (ballPos.y >= 500 - ball.getGlobalBounds().height) // Stoppe den Ball und verliere ein Leben
    {
        health--; // Lebensanzahl verringern
        if (health <= 0) {
            // Spiel beenden oder Neustart
            meinSpieleFenster.close(); // Zum Testen einfach das Fenster schließen
            cout << "Game Over" << endl;
        }
        else {
            // Ball zurücksetzen
            score = 0; // Zurücksetzen des Scores
            ball.setPosition(145, 100); // Ball zurücksetzen
        }
    }

}

void Logik::kollisionSpieler()
{

    Vector2f ballPos = ball.getPosition();
    Vector2f playerPos = player.getPosition();
    // Ballkollision mit dem Spieler
    if (ballPos.x + ball.getGlobalBounds().width >= playerPos.x &&
        ballPos.x <= playerPos.x + player.getSize().x &&
        ballPos.y + ball.getGlobalBounds().height >= playerPos.y &&
        ballPos.y <= playerPos.y + player.getSize().y)
    {
        // Um sicherzustellen, dass der Ball nicht in den Spieler eindringt
        if (my > 0) { // Wenn der Ball nach unten bewegt wird
            score++;
            text.setString(std::to_string(score));
            my = -speed; // Ball prallt sofort nach oben ab
            ball.setPosition(ballPos.x, playerPos.y - ball.getGlobalBounds().height); // Ball oberhalb des Spielers positionieren
        }
    }
}
