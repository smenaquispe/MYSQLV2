#include<iostream>
using namespace std;

#include"./classes/Controller/Controller.h"
#include"./classes/DB/DB.h"

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
    controller->run();

    delete db;
    delete controller;

    return 0;
}