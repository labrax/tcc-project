/*
 * Screen.h
 *
 *  Created on: 14 de set de 2015
 *      Author: Victor R. Cardoso
 */

#ifndef SRC_CLIENT_GRAPHICS_SCREEN_H_
#define SRC_CLIENT_GRAPHICS_SCREEN_H_

#include <cassert>
#include <string>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

#include "GameWindow.hpp"
#include "Config.hpp"
#include "Console.hpp"

#include "GraphicsPrimitives.hpp"

#include "UI.hpp"

class Screen {
private:
	//window variables
	sf::RenderWindow * window;
	unsigned int width, height;
	
	//pause rendering
	bool paused;
	UI::Element * drawable;
public:
	Screen(UI::Element * drawable);
	virtual ~Screen();
	
	sf::RenderWindow * getWindow();
	unsigned int getWidth();
	unsigned int getHeight();
	
	void stopDraw();
	void resumeDraw();
	
	void draw(GameWindow * gm);
	
	void onEvent(sf::Event & event);
	void onResize(sf::Vector2f & new_size);
};

#endif
