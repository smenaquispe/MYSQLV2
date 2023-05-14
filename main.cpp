#include<iostream>
using namespace std;

#include"./classes/Controller/Controller.h"
#include"./classes/DB/DB.h"

#include"./disco/Disco.h"

/**
 * 
 * Requerimientos:
 * 
 * 1. SELECT:  {
 *         -CONTROLLER: extraer las columnas y el nombre de la tabla
 *         -DB: extraiga primera columna (header) -> {
 *                  -SI: * -> imprime tabla
 *                  -SINO: columnas -> genera tempSchema
 *          }
 * }
 * 2. SELECTWHERE: {
 *          -CONTROLLER: extrae la clause
 *          -DB: injectar el clause, y el funcionamiento es el mismo
 * }
 * 
*/

int main() {

    DB * db = new DB;   
    Controller *controller = new Controller(db);


    
    int n = 2, 
        m = 3,
        p = 15,
        q = 18;
    Disco * disco = new Disco(n,m,p,q);

    controller->run();

    delete db;
    delete controller;

    return 0;
}