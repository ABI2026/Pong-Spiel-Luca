#include "Game.h"

Game::Game(Schrift& s, Ball& b, Engine& e, Logik& l, Player& p) : schrift(s), ball(b), engine(e), logik(l), player(p)
{

}

void Game::run()
{
	engine.erstelleFenster();

	while(engine.isOpen())
	{
		engine.pollEvent();

		logik.kollisionFenster();
		logik.kollisionSpieler();
		logik.tastatur();
		logik.updateLeben();

		engine.clear();
		engine.getWindow().draw(ball.getSprite());
		engine.getWindow().draw(schrift.getText());
		engine.getWindow().draw(schrift.getHealthtext());
		engine.getWindow().draw(player.getPlayer());
		engine.getWindow().display();
	}
}
