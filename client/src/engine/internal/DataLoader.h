//
// Created by vroth on 24/07/16.
//

#ifndef TCC_DATALOADER_H
#define TCC_DATALOADER_H

#include "../Console.h"
#include "Error.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <fstream>
#include <vector>
#include <string>
#include <map>

class DataLoader {
private:
    DataLoader();

    std::map < std::string, std::vector<char> > dataStore;
    std::map < std::tuple < std::string, unsigned int, unsigned int >, sf::Sprite * > spriteStore;
    sf::Sprite * getSprite(std::string filename, sf::IntRect & rect);
public:
    ~DataLoader();
    static DataLoader & getInstance();

    void loadFile(std::string filename);
    sf::Sprite * getSprite(std::string file_name, int idx, int idy);
};


#endif //TCC_DATALOADER_H
