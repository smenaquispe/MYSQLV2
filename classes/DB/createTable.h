#ifndef CREATE_TABLE
#define CREATE_TABLE

#include"DB.h"

void DB::createTable() {
    
    // if table doesnt exist
    if(this->tableExist()) {
        cout<<"[Error]: Table "<<this->tableName<<" exist"<<endl;
        return;
    }

    strcpy(buffer, tableName);

    char* token = strtok(this->columnNames, ", ");
    while (token != nullptr)
    {
        strcat(buffer, ",");
        strcat(buffer, token);
        token = strtok(nullptr, ", ");
    }

    ofstream schemaFile("./db/schema", ios::app);
    if(schemaFile.is_open()) {
        schemaFile<<buffer<<endl;
        schemaFile.close();


    } else {
        cout<<"[Error]: can't open schema file"<<endl;
    }

}

#endif