//
// Created by vroth on 10/08/16.
//

#ifndef TCC_GELEMENT_H
#define TCC_GELEMENT_H

#include <vector>
#include "patterns/Observer.h"

using std::vector;

class GElement {
private:
    uint32_t identifier;
    vector<Observer *> observers;
public:
    GElement(uint32_t identifier);
    GElement();
    virtual ~GElement();

    void addObserver(Observer * observer);
    bool notify(GElement * caller, GEvent * event);
};


#endif //TCC_GELEMENT_H
