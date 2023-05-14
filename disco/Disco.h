#ifndef DISCO_H
#define DISCO_H

#include"Plato.h"

class Disco {
public: 
    /* arreglo de platos */
    int numPlatos;
    int numPistas;
    int numSectores;
    int tamanoSector;

    int cantidadActualPlatos; // contador de la cantidad de platos que hay
    Plato * inicioPlatos; // seran una lista enlazada doble, con capacidad maxima del numero de platos
    Plato * finPlatos;

    // buffer
    char buffer[1024];

    Disco(int numPlatos, int numPistas, int numSectores, int tamanoSector) {
        this->numPlatos = numPlatos;
        this->numPistas = numPistas;
        this->numSectores = numSectores;
        this->tamanoSector = tamanoSector;

        this->cantidadActualPlatos = 0;
        this->inicioPlatos = this->finPlatos = nullptr;
    }

    ~Disco() {}

    bool estaLleno() {
        return numPlatos == cantidadActualPlatos;
    }

    Plato * crearPlato() {
        // se alcanzo el número máximo de platos posibles
        // el disco esta lleno
        if(numPlatos == cantidadActualPlatos) return nullptr;

        // creo nuevo plato
        Plato * nuevoPlato = new Plato(this->numPistas, this->numSectores, this->tamanoSector);

        // no hay platos
        if(this->inicioPlatos == nullptr) {
            this->inicioPlatos = nuevoPlato;
            this->finPlatos = nuevoPlato;
        } else {
            this->finPlatos->sig = nuevoPlato;
            nuevoPlato->ant = this->finPlatos;
        }

        cantidadActualPlatos++;

        return nuevoPlato;
    }

    // get plato en cierto index, tomando de 0 hasta n - 1
    Plato * getPlato(int index) {
        
        // si no cumple con el rango
        if(index >= numPlatos) return nullptr;
        if(index < 0) return nullptr;

        Plato * current = inicioPlatos;
        int count = 0;
        while (current)
        {   
            if(count == index) break;
            ++count;
            current = current->sig;
        }

        return current;
    }

    Sector * cargarSector(const char * dato) {

        Plato * currentPlato = inicioPlatos;
        strcpy(buffer, dato);

        while (currentPlato)
        {
            // comprobamos que el plato esta lleno o no
            if(!currentPlato->estaLleno()) { 
                // si no esta lleno guardamos el sector en este plato
                return currentPlato->cargarSector(buffer);
            
            }
            // sino que vaya al siguiente plato e intente guardar alli
            currentPlato = currentPlato->sig;
        }

        // no se cargó el dato, si no esta lleno
        if(!this->estaLleno()) {
            // creamos y guardmos en el puntero
            currentPlato = crearPlato();
            return currentPlato->cargarSector(buffer);
        }

        return nullptr;
    }

    void cargarBloque() {

    }
};

#endif
