/*
 * GameWindow.cpp
 *
 *  Created on: 14 de set de 2015
 *      Author: Victor R. Cardoso
 */

#include "GameWindow.h"

GameWindow::GameWindow(sf::Vector2f pos, sf::Vector2f size, unsigned int width, unsigned int height) : Window(pos, size, "")
{
    if (!renderTexture.create((config::grid_distance + 2) * config::sprite_size, (config::grid_distance + 2) * config::sprite_size))
    {
        SFMLError(__FILE__, __LINE__);
    }
    renderTexture.setSmooth(true);
}

GameWindow::~GameWindow()
{

}

void GameWindow::draw(sf::RenderWindow * window)
{
    renderTexture.clear();

    sf::Sprite * sp = DataLoader::getInstance().getSprite("assets/roguelikeChar_transparent.png", 1, 7);
    sf::Sprite * bkpg = DataLoader::getInstance().getSprite("assets/roguelikeCity_transparent.png", 0, 20);

    for(int i = 0; i < 14; i++) {
        for(int j = 0; j < 14; j++) {
            bkpg->setPosition(sf::Vector2f(i*16, j*16));
            renderTexture.draw(*bkpg);
        }
    }

    sp->setPosition(sf::Vector2f(16, 16));
    renderTexture.draw(*sp);
    renderTexture.display();


    static sf::Texture texture = renderTexture.getTexture();
    static sf::Sprite sprite(texture);

    float scale_x = size.x/texture.getSize().x;
    float scale_y = size.y/texture.getSize().y;
    float scale = scale_x < scale_y ? scale_x : scale_y;
    sprite.setScale(scale, scale);

    sprite.setPosition(sf::Vector2f(size.x/2 - scale*texture.getSize().x/2, size.y/2 - scale*texture.getSize().y/2));

    window->draw(sprite);
    //UI::Window::draw(window);
	//TODO: check drawing order


    char iteration[64];
    sprintf(iteration, "Game version: %s", config::game_title);
    drawText(window, sf::Vector2f(0, 0), std::string(iteration), 16, sf::Color::Blue, ALIGN_LEFT);

    drawElements(window);
}

bool GameWindow::onEvent(sf::Event & event)
{
	//Console::getConsole().log("player_: %f %f\n", player_x, player_y);
	//Console::getConsole().log("mouse_: %u %u\n", mouse_x, mouse_y);

	if(event.type == sf::Event::Closed)
	{
        may_exit = true;
		return true;
	}
	return false;
	//return false;
}

void GameWindow::onResize(sf::Vector2f & new_size)
{
    size = new_size;
}

bool GameWindow::exit()
{
	return may_exit;
}
