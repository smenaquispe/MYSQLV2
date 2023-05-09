#ifndef SET_PROPS
#define SET_PROPS

#include"DB.h"

void DB::setProps(char * columNames, char * tableName) {
    this->columnNames = columNames;
    this->tableName = tableName;
}

void DB::setProps(char * columNames, char * tableName, char * clause) {
    this->columnNames = columNames;
    this->tableName = tableName;
    this->clause = clause;
}


void DB::setProps(char * columNames, char * tableName, char * clause, char * fileName) {
    this->columnNames = columNames;
    this->tableName = tableName;
    this->clause = clause;
    this->fileName = fileName;
}

#endif
