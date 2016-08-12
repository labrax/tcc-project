//
// Created by vroth on 10/08/16.
//

#include "GElement.h"

GElement::GElement() {
    static uint32_t internal_count = 0;
    GElement(++internal_count);
}

GElement::GElement(uint32_t identifier) : identifier(identifier) {

}

GElement::~GElement() {

}

void GElement::addObserver(Observer *observer) {
    observers.insert(observers.end(), observer);
    observer->addObserved(this);
}

bool GElement::notify(GElement *caller, GEvent *event) {
    return false;
}