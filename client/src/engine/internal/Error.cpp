//
// Created by vroth on 24/07/16.
//

#include "Error.h"

Error::Error(const char *file, int line) {
    strcpy(this->file, file);
    this->line = line;
}

const char* Error::what() const throw()
{
    static char errorline[512];
    sprintf(errorline, "%s:%d %s\n", file, line, typeid(this).name());
    return errorline;
}

DataLoaderError::DataLoaderError(const char* file, int line) : Error(file, line) {}

SFMLError::SFMLError(const char *file, int line) : Error(file, line) {}