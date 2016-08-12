//
// Created by vroth on 10/08/16.
//

#ifndef TCC_GSPRITEVIEWER_H
#define TCC_GSPRITEVIEWER_H

#include <ctime>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include "../internal/Config.h"

#include "UI.h"
#include "GameUI.h"

#include "../internal/DataLoader.h"

using std::string;

class GSpriteViewer : public UI::Window {
private:
    sf::RenderTexture renderTexture;
    bool may_exit = false;
    uint32_t x, y, curr_file;
public:
    GSpriteViewer(sf::Vector2f pos, sf::Vector2f size, unsigned int width, unsigned int height);
    virtual ~GSpriteViewer();

    void draw(sf::RenderWindow * window);
    bool onEvent(sf::Event & event);
    void onResize(sf::Vector2f & new_size);

    bool exit();
};


#endif //TCC_GSPRITEVIEWER_H
