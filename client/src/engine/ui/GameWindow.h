/*
 * GameWindow.h
 *
 *  Created on: 14 de set de 2015
 *      Author: Victor R. Cardoso
 */

#ifndef SRC_CLIENT_GAMESTATE_GameWindow_H_
#define SRC_CLIENT_GAMESTATE_GameWindow_H_

#include <ctime>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include "../internal/Config.h"

#include "UI.h"
#include "GameUI.h"

#include "../internal/DataLoader.h"

class GameWindow : public UI::Window
{
private:
    sf::RenderTexture renderTexture;
    bool may_exit = false;
public:
	GameWindow(sf::Vector2f pos, sf::Vector2f size, unsigned int width, unsigned int height);
	virtual ~GameWindow();
	
	void draw(sf::RenderWindow * window);
	bool onEvent(sf::Event & event);
	void onResize(sf::Vector2f & new_size);
	
	bool exit();
};

#endif
