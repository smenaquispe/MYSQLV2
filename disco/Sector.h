#ifndef SECTOR_H
#define SECTOR_H

#include<string.h>
/**
 * será un node de una lista enlazada circular
*/
class Sector {
public:
    char * dato;
    Sector * sig;
    Sector * prev;

    Sector(int tamanoSector, const char *dato) {
        this->dato = new char[tamanoSector];
        sig = prev = nullptr;
        strcpy(this->dato,dato);
    }

    ~Sector() {
        delete [] dato;
    }
};


#endif