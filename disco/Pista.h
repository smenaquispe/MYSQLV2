#ifndef PISTA_H
#define PISTA_H

#include"Sector.h"
#include<iostream>
using namespace std;

/**
 * es una lista enlaza circular doble de los sectores
*/
class Pista {
public:
/*
    la idea es que se creen nuevos sectores dinamicamente
    como maximo el numSectores
*/
    int numSectores;
    int tamanoSector;
    Sector * cabezal; // este sector será donde se encuentra ubicado el cabezal

    Pista() {
        // por defecto el cabezal comienza en null
        cabezal = nullptr;
    }
    ~Pista() {}

    void setInfoSector(int numSectores, int tamanoSector) {
        this->numSectores = numSectores;
        this->tamanoSector = tamanoSector;
    }

    void createSector(char * value) {
        // creo mi nodo sector con el tamaño correpondiente y el valor que pasaron a  la pista
        Sector * newSector = new Sector(this->tamanoSector, value);
        if(cabezal == nullptr) {
            cabezal = newSector;
            cabezal->sig = newSector;
            cabezal->prev = newSector;
        } else {
            Sector * next = cabezal->sig;
            cabezal->sig = newSector;
            newSector->sig = next;
            next->prev = newSector;
            newSector->prev = cabezal;

            cabezal = newSector;
        }
    }

    void printPista() {
        Sector* current = cabezal;
        do{
            cout<<current->dato<<endl;
            current = current->sig;
        }while (current != cabezal);
    }
};

#endif