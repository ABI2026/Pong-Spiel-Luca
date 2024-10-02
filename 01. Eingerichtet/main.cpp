#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    int health = 3; // Lebenszähler initialisieren
    int score = 0;
    int mx = 0; // m_move x-Achse
    int my = 0;
    int speed = 5;

    // Schriftart
    Font font;
    font.loadFromFile("fonts/arial.ttf");

    // Label 
    Text text("", font);
    text.setCharacterSize(30);
    text.setString(std::to_string(score));

    // Lebensanzeige
    Text healthText("", font);
    healthText.setCharacterSize(30);
    healthText.setPosition(0, 40);
    healthText.setString("Health: " + std::to_string(health));

    // Spielefenster erstellen
    RenderWindow meinSpieleFenster(VideoMode(300, 500), "Pong");
    meinSpieleFenster.setFramerateLimit(30);

    // Textur für den Ball
    Texture ballTexture;
    if (!ballTexture.loadFromFile("ball.png")) // Ersetze mit dem Pfad zu deinem Bild
    {
        return -1; // Fehler beim Laden der Textur
    }

    // Ball als Sprite
    Sprite ball;
    ball.setTexture(ballTexture);
    ball.setPosition(145, 100);
    ball.setScale(0.08f, 0.08f); // Setze die Größe des Balls auf 8% der Originalgröße

    // Player
    RectangleShape player(Vector2f(40, 10));
    player.setPosition(130, 400);
    player.setFillColor(Color::Red);

    while (meinSpieleFenster.isOpen()) {
        Vector2f ballPos = ball.getPosition();
        Vector2f playerPos = player.getPosition();

        // Bewegung des Balls
        ball.move(mx, my);

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

        // Tastatur auslesen
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            my = speed;
            mx = speed;
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
            if (playerPos.x > 0) // Bildbegrenzung nach links
            {
                player.move(-speed, 0); // y-Achse == 0
            }

        if (Keyboard::isKeyPressed(Keyboard::Right))
            if (playerPos.x < 300 - player.getSize().x) // Bildbegrenzung nach rechts
            {
                player.move(speed, 0); // y-Achse == 0
            }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) // Neu
        {
            meinSpieleFenster.close();
        }

        // Update der Lebensanzeige
        healthText.setString("Health: " + std::to_string(health));

        meinSpieleFenster.clear();
        meinSpieleFenster.draw(ball); // Ball als Sprite zeichnen
        meinSpieleFenster.draw(text);
        meinSpieleFenster.draw(healthText); // Lebensanzeige zeichnen
        meinSpieleFenster.draw(player);
        meinSpieleFenster.display();
    }

    return 0;
}