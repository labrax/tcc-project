/*
 * InputHandler.h
 *
 *  Created on: 14 de set de 2015
 *      Author: Victor R. Cardoso
 */

#ifndef SRC_CLIENT_CONTROL_INPUTHANDLER_H_
#define SRC_CLIENT_CONTROL_INPUTHANDLER_H_

#include <SFML/Window/Event.hpp>

#include "ui/Screen.h"
#include "Console.h"
#include "patterns/Observer.h"

#define MIN_SIZE 5
#define MAX_SIZE 50

class InputHandler : public Observer{
private:
	
public:
	InputHandler();
	virtual ~InputHandler();
	void poolEvents(Screen * screen);
};

#endif
