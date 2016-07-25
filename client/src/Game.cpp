/*
 * Game.cpp
 *
 *  Created on: 14 de set de 2015
 *      Author: Victor R. Cardoso
 */

#include "Game.h"

Game::Game() {
	gm = new GameWindow(sf::Vector2f(0, 0), sf::Vector2f(0, 0), config::width, config::height);
	
	PlayerConsole * pc = new PlayerConsole();
	gm->addElement(pc, false, false);
	
	screen = new Screen(gm);
	
	ih = new InputHandler();
	//net = new Network();
}

Game::~Game() {
	delete(ih);
	delete(screen);
	delete(gm);
	//delete(pc);
	//delete(net);
}

int Game::run() {
	bool isRunning = true;

	sf::Clock clock;
	while(isRunning) {
		//network

		//GameWindow

		//input
		ih->poolEvents(screen);
		
		//screen
		screen->draw(gm);

		if(gm->exit())
			isRunning = false;

		sf::Time elapsedTime = clock.restart();
		if(elapsedTime < config::time_per_frame)
		{
			sf::sleep(config::time_per_frame - elapsedTime); //TODO: corrigir com o fps
		}
	}
	return 0;
}

