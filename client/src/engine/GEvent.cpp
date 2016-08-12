//
// Created by vroth on 10/08/16.
//

#include "GEvent.h"

GEvent::GEvent(sf::Event event) : event(event){

}

GEvent::~GEvent() {

}

sf::Event& GEvent::getEvent() {
    return event;
}