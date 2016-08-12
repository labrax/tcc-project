//
// Created by vroth on 10/08/16.
//

#ifndef TCC_OBSERVER_H
#define TCC_OBSERVER_H

#include <vector>
#include "../GElement.h"
#include "../GEvent.h"
#include "../ui/UI.h"

using std::vector;

class Observer {
private:
    vector< UI::Element *> observed;
public:
    Observer();
    virtual ~Observer();
    void addObserved(UI::Element * element);
    void onEvent(GEvent& event);
};


#endif //TCC_OBSERVER_H
