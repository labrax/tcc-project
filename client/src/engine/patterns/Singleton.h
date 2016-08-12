//
// Created by vroth on 10/08/16.
//

#ifndef TCC_SINGLETON_H
#define TCC_SINGLETON_H


class Singleton {
protected:
    Singleton();

public:
    static Singleton & getInstance();
    virtual ~Singleton();
};


#endif //TCC_SINGLETON_H
