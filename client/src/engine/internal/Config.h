/*
 * Config.hpp
 *
 *  Created on: 15 de set de 2015
 *      Author: Victor R. Cardoso
 */

#ifndef COMMON_CONFIG_H_
#define COMMON_CONFIG_H_

#include <SFML/System/Time.hpp>

#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics.hpp>

namespace config {
	//game
	extern sf::Time time_per_frame;
	extern char game_title[];
	//gamestate
	extern unsigned int height, width, iterations_per_sec;
	extern unsigned char uchar_nil;
	//player
	extern unsigned int initial_zoom;
	//screen
	extern unsigned int frameratelimit, screen_height, screen_width;
    extern unsigned int grid_distance; //in each direction, i.e. for 7 we have 15*15 tiles!
    extern unsigned int sprite_size;
	//player console
	extern sf::Color color_inside, color_border, color_text;
	extern unsigned int txt_size;
}

#endif
