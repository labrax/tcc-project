/*
 * Game.h
 *
 *  Created on: 14 de set de 2015
 *      Author: Victor R. Cardoso
 */

#ifndef SRC_CLIENT_GAME_H_
#define SRC_CLIENT_GAME_H_

#include "engine/Console.h"
#include "engine/internal/Config.h"

#include "engine/InputHandler.h"
#include "engine/ui/GameWindow.h"
#include "engine/ui/Screen.h"

class Game
{
private:
	GameWindow * gm;
	Screen * screen;
	InputHandler * ih;
	//Network * net;
public:
	Game();
	virtual ~Game();
	int run();
};

#endif
