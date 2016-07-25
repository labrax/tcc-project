//
// Created by vroth on 24/07/16.
//

#ifndef TCC_ERROR_H
#define TCC_ERROR_H

#include <exception>
#include <typeinfo>
#include <cstring>
#include <cstdio>

class Error : public std::exception {
private:
    char file[128];
    int line;
public:
    Error(const char * file, int line);
    virtual const char * what() const throw();
};

class DataLoaderError : public Error {
public:
    DataLoaderError(const char * file, int line);
};

class SFMLError : public Error {
public:
    SFMLError(const char * file, int line);
};

#endif //TCC_ERROR_H
