#ifndef PLATO_H
#define PLATO_H

#include"Pista.h"
#include"Superficie.h"

/**
 * los platos seran una lista enlazada
 * y tendran 2 listas enlazadas dobles, (por cada superficie) en un array de superifice
*/
class Plato {
public:
    int numPistas;
    int numSectorePorPista;
    int tamanoSector;

    // propios del plato que maneja el disco
    Plato * sig;
    Plato * ant;

    // este es mi array de superficies
    Superficie * superficies;

    Plato(int numPistas, int numSectores, int tamanoSector) {
        this->numPistas = numPistas;
        this->numSectorePorPista = numSectores;
        this->tamanoSector = tamanoSector;

        superficies = new Superficie[2];
        superficies[0].setDatos(numPistas, numSectorePorPista, tamanoSector);
        superficies[1].setDatos(numPistas, numSectorePorPista, tamanoSector);
    }

    ~Plato() {}

    bool estaLleno() {
        return (superficies[0].estaLleno() && superficies[1].estaLleno());
    }

    Sector * cargarSector(char * dato) {
        if(!superficies[0].estaLleno()) {
            return superficies[0].cargarDato(dato);
        }  else if(!superficies[1].estaLleno()) {
            return superficies[1].cargarDato(dato);
        }
        return nullptr;
    }
};

#endif