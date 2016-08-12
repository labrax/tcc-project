/*
 * Console.cpp
 *
 *  Created on: 25 de out de 2015
 *      Author: Victor R. Cardoso
 */

#include "Console.h"

Console::Console()
{
	
}

Console::~Console()
{
	
}

void Console::log(const char* format, ...)
{
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    va_end(argptr);
}
