#include "Logik.h"
#include <iostream>
#include "Logik.h"
#include "Ball.h"   // Hier die vollständige Definition von Ball einbinden
#include "Player.h"
#include <iostream>
#include "Engine.h"
#include "Schrift.h"

using namespace std;


Logik::Logik(Ball& b, Player& p, Engine& e, Schrift& s) 
    : ball(b), player(p), engine(e), schrift(s) {}

void Logik::kollisionFenster()
{
    sf::Vector2f playerPos = player.getPosition();
    sf::Vector2f ballPos = ball.getPosition();

    // Kollision mit den Fenstergrenzen
    if (ballPos.x <= 0)
    {
        mx = ball.getSpeed();
    }
    else if (ballPos.x >= 300 - ball.getGloubalBounds().width)
    {
        mx = -ball.getSpeed();
    }

    if (ballPos.y <= 0)
    {
        my = ball.getSpeed();
    }
    else if (ballPos.y >= 500 - ball.getGloubalBounds().height) // Stoppe den Ball und verliere ein Leben
    {
        health--; // Lebensanzahl verringern
        if (health <= 0) {
            // Spiel beenden oder Neustart
            engine.getWindow().close(); // Zum Testen einfach das Fenster schließen
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

    sf::Vector2f ballPos = ball.getPosition();
    sf::Vector2f playerPos = player.getPosition();
    // Ballkollision mit dem Spieler
    if (ballPos.x + ball.getGloubalBounds().width >= playerPos.x &&
        ballPos.x <= playerPos.x + player.getSize().x &&
        ballPos.y + ball.getGloubalBounds().height >= playerPos.y &&
        ballPos.y <= playerPos.y + player.getSize().y)
    {
        // Um sicherzustellen, dass der Ball nicht in den Spieler eindringt
        if (my > 0) { // Wenn der Ball nach unten bewegt wird
            score++;
            punktestand();
                //text.setString(std::to_string(score));
            my = -ball.getSpeed(); // Ball prallt sofort nach oben ab
            ball.setPosition(ballPos.x, playerPos.y - ball.getGloubalBounds().height); // Ball oberhalb des Spielers positionieren
        }
    }
}

void Logik::punktestand()
{
    
    schrift.label(score);
}
