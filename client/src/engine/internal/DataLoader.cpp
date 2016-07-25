//
// Created by vroth on 24/07/16.
//

#include "DataLoader.h"

DataLoader::DataLoader() {

}

DataLoader::~DataLoader() {

}

DataLoader &DataLoader::getInstance() {
    static DataLoader *instance = new DataLoader();
    return *instance;
}

void DataLoader::loadFile(std::string file_name) {
    sf::ContextSettings glsettings;
    glsettings.antialiasingLevel = 2;

    std::ifstream texture_file{file_name.c_str(), std::ifstream::binary};
    std::vector<char> buffer;
    if (texture_file) {
        // get length of file:
        texture_file.seekg(0, texture_file.end);
        const auto length = texture_file.tellg();
        if (!length) {
            Console::getConsole().log("Cannot load zero byte texture file %s\n", file_name.c_str());
            throw new DataLoaderError(__FILE__, __LINE__);
        }
        buffer.resize(length); // reserve space

        texture_file.seekg(0, texture_file.beg);

        auto start = &*buffer.begin();
        texture_file.read(start, length);
        texture_file.close();
    } else {
        Console::getConsole().log("Could not open texture file %s\n", file_name.c_str());
        throw new DataLoaderError(__FILE__, __LINE__);
    }

    dataStore.insert(std::pair<std::string, std::vector<char> >(file_name, buffer));
}

sf::Sprite *DataLoader::getSprite(std::string file_name, sf::IntRect &rect) {
    std::map<std::string, std::vector<char> >::iterator it = this->dataStore.find(file_name);

    sf::Texture *texture = new sf::Texture();

    if (it == dataStore.end()) {
        this->loadFile(file_name);
    }
    it = this->dataStore.find(file_name);

    if (!texture->loadFromMemory(&it->second[0], it->second.size(), rect)) {
        Console::getConsole().log("Texture load failed.\n");
        throw new DataLoaderError(__FILE__, __LINE__);
    }

    //TODO: complete this code
    sf::Sprite *sprite = new sf::Sprite(*texture);
    //sprite->setTexture(texture);
    return sprite;
}


sf::Sprite * DataLoader::getSprite(std::string file_name, int idx, int idy) {
    std::map<std::tuple<std::string, unsigned int, unsigned int>, sf::Sprite *>::iterator it = this->spriteStore.find(
            std::tuple<std::string, unsigned int, unsigned int>(file_name, idx, idy));

    if ( it == spriteStore.end() ) {
        Console::getConsole().log("Loading sprite %s (%d,%d)\n", file_name.c_str(), idx, idy);
        sf::IntRect ir = sf::IntRect(17 * idx, 17 * idy, 16, 16);
        sf::Sprite * sprite = getSprite(file_name, ir);
        std::tuple<std::string, unsigned int, unsigned int> tp = std::tuple<std::string, unsigned int, unsigned int>(file_name, idx, idy);
        spriteStore.insert(std::pair< std::tuple<std::string, unsigned int, unsigned int>, sf::Sprite * > (tp, sprite));
        return sprite;
    }

    return it->second;
}