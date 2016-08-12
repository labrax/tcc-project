/*
 * Console.hpp
 *
 *  Created on: 25 de out de 2015
 *      Author: Victor R. Cardoso
 */

#ifndef COMMON_CONSOLE_H_
#define COMMON_CONSOLE_H_

#include <cstdio>
#include <cstdarg>
#include "patterns/Singleton.h"

class Console : public Singleton {
private:
	Console();
public:
	void log(const char* format, ...);
	~Console();
};

#endif
