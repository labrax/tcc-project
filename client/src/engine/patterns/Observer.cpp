//
// Created by vroth on 10/08/16.
//

#include "Observer.h"

Observer::Observer() {
    observed = vector<UI::Element *>();
}

Observer::~Observer() {

}

void Observer::addObserved(UI::Element *element) {
    observed.insert(observed.end(), element);
}

void Observer::onEvent(GEvent& event) {
    for(auto & i : observed) {
        i->onEvent(event);
    }
}