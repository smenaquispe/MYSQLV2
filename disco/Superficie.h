#ifndef SUPERFICIE_H
#define SUPERFICIE_H

#include"Pista.h"

// lista enlazada doble de pistas
class Superficie
{
public:
    int numSectores;
    int tamanoSector;
    int numPistas;

    Pista * inicioPistas;
    Pista * finPistas;

    int cantidadActualPistas;

    Superficie() {
        inicioPistas = finPistas = nullptr;
        cantidadActualPistas = 0;
    }

    ~Superficie() {}

    void setDatos(int numPistas, int numSectores, int tamanoSector) {
        this->numPistas = numPistas;
        this->numSectores = numSectores;
        this->tamanoSector = tamanoSector;        
    }

    bool estaLleno() {
        return numPistas == cantidadActualPistas;
    }

    Pista * crearPista() {
        if(numPistas == cantidadActualPistas) return nullptr;

        Pista * nuevaPista = new Pista(numSectores, tamanoSector);

        if(this->inicioPistas == nullptr) {
            this->inicioPistas = nuevaPista;
            this->finPistas = nuevaPista;
        } else {
            this->finPistas->sig = nuevaPista;
            nuevaPista->ant = this->finPistas;
        }

        cantidadActualPistas++;

        return nuevaPista;
    }

    Sector * cargarDato(char * dato) {
        // esta lleno
        if(cantidadActualPistas == numPistas) return nullptr;

        Pista * currentPista = inicioPistas;
        while (currentPista)
        {
            // si encuentra una pista que no este llena
            if(!currentPista->estaLleno()) {
                return currentPista->cargarSector(dato);
            }
            currentPista = currentPista->sig;
        }

        // todas las pistas estan llenas, pero aun se puede agregas más pistas, crea una nueva
        currentPista = crearPista();
        return currentPista->cargarSector(dato);
    }

};

#endif