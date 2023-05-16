#ifndef CREATE_TABLE
#define CREATE_TABLE

#include"DB.h"

void DB::createTable() {
    
    // if table doesnt exist
    if(this->tableExist()) {
        cout<<"[Error]: Table "<<this->tableName<<" exist"<<endl;
        return;
    }

    
    char fileName[256];

    strcpy(fileName, "./db/tables/");
    strcat(fileName, this->tableName);

    ofstream tableFile(fileName);

    strcpy(buffer, tableName);

    bool save = true;
    bool first = true;
    char* token = strtok(this->columnNames, ", ");
    tableFile<<token;
    
    while (token != nullptr)
    {
        strcat(buffer, ",");
        strcat(buffer, token);

        if(save && !first) {
            tableFile<<",";
            tableFile<<token;
        }

        save = !save;
        first = false;

        token = strtok(nullptr, ", ");

    }

    tableFile<<endl;

    ofstream schemaFile("./db/schema", ios::app);
    if(schemaFile.is_open()) {
        schemaFile<<buffer<<endl;
        schemaFile.close();
        cout<<"Table "<<this->tableName<<" created"<<endl;
    } else {
        cout<<"[Error]: can't open schema file"<<endl;
    }

}

#endif