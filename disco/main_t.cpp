#include<iostream>
using namespace std;

#include"Disco.h"

int main() {

    /*
    n = numero de platos
    m = numero de pistas
    p = numero de sectores
    q = tamanño del sector
    */

    int n = 2, 
        m = 3,
        p = 15,
        q = 18;

    Disco disco(n, m, p , q);

    Sector * s = disco.cargarSector("hola");

    return 0;
}