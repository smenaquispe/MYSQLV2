#include<iostream>
using namespace std;

#include"Pista.h"

int main() {

    Pista p;
    char buffer[1024] = "hola";

    /* set informacion de creacion de setores */
    p.setInfoSector(6, 14);

    p.createSector(buffer);

    strcpy(buffer, "mundo");
    p.createSector(buffer);

    strcpy(buffer, "como");
    p.createSector(buffer);

    strcpy(buffer, "estas");
    p.createSector(buffer);

    strcpy(buffer, "que");
    p.createSector(buffer);

    strcpy(buffer, "honda");
    p.createSector(buffer);

    p.printPista();

    return 0;
}