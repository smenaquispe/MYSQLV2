#ifndef PISTA_H
#define PISTA_H

#include"Sector.h"
#include<iostream>
using namespace std;

/**
 * es una lista enlaza circular doble de los sectores
 * pero tambien forman una lista enlazada dbole en las superficies de los platos
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

    int cantidadActualSectores; // contador de la cantidad de sectores que tiene la pista

    Pista * sig; // como es una lista enlaza entonces tiene siguiente
    Pista * ant;

    Pista(int numSectores, int tamanoSector) {
        this->numSectores = numSectores;
        this->tamanoSector = tamanoSector;

        // por defecto el cabezal comienza en null
        cabezal = nullptr;
        ant = sig = nullptr;
        cantidadActualSectores = 0; 

    }

    ~Pista() {}

    // la pista esta llena
    bool estaLleno() {
        return cantidadActualSectores == numSectores;
    }

    Sector * cargarSector(char * value) {

        // máxmima cantidad de sectores que se pueden alamcenar en esta pista
        if(cantidadActualSectores == numSectores) return nullptr;

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

        cantidadActualSectores++;

        return newSector;
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