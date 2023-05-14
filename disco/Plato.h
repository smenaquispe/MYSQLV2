#ifndef PLATO_H
#define PLATO_H

#include"Pista.h"

class Plato {
public:
    int numPistas;
    int numSectorePorPista;
    Pista * superficie1;
    Pista * superficie2;  

    Plato() {}

    void setPistas(int numPistas, int numSectores, int tamanoSector) {
        this->numPistas = numPistas;
        /** se setean el numero de pistas por cada superficie */
        superficie1 = new Pista[numPistas];
        superficie2 = new Pista[numPistas];

        for(int i = 0; i < numPistas; i++) {
            /** se setean los datos de los sectores en cada pista de cada superficie s*/
            superficie1[i].setInfoSector(numSectores, tamanoSector);
            superficie2[i].setInfoSector(numSectores, tamanoSector);
        }
    }

    ~Plato() {
        delete [] superficie1;
        delete [] superficie2;
    }
};

#endif