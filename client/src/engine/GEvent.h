//
// Created by vroth on 10/08/16.
//

#ifndef TCC_GEVENT_H
#define TCC_GEVENT_H

#include <SFML/Window/Event.hpp>

class GEvent {
private:
    sf::Event event;
public:
    GEvent(sf::Event event);
    ~GEvent();

    sf::Event & getEvent();
};


#endif //TCC_GEVENT_H
