//
// Created by vroth on 10/08/16.
//

#include "Singleton.h"

Singleton::Singleton() {

}

Singleton::~Singleton() {}

Singleton& Singleton::getInstance() {
    static Singleton * instance = new Singleton();
    return *instance;
}