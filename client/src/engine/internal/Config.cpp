/*
 * Config.cpp
 *
 *  Created on: 15 de set de 2015
 *      Author: Victor R. Cardoso
 */

#include "Config.h"

namespace config
{
	//game
	sf::Time time_per_frame = sf::seconds(1.0f/frameratelimit);
	char game_title[32] = "alpha";

	uint32_t amount_assets = 5;
	const char assets_file[][5] = {
            "roguelikeChar_transparent.png",
            "roguelikeIndoor_transparent.png",
            "roguelikeCity_transparent.png",
            "roguelikeSheet_transparent.png",
            "roguelikeDungeon_transparent.png"
    };

	//gamestate
	unsigned int height = 30, width = 40, iterations_per_sec = 1;
	unsigned char uchar_nil = 0;

	//player
	unsigned int initial_zoom = 10;

	//screen
	unsigned int frameratelimit = 50, screen_width = 800, screen_height = 600;
    unsigned int grid_distance = 7;
    unsigned int sprite_size = 16;
	
	//player console
	sf::Color color_inside(32, 32, 32, 128);
	sf::Color color_border(192, 192, 192, 128);
	sf::Color color_text(32, 32, 200);
	
	unsigned int txt_size = 15;
}
