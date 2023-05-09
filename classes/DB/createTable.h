#ifndef CREATE_TABLE
#define CREATE_TABLE

#include"DB.h"

void DB::createTable() {
    
    // if table doesnt exist
    if(this->tableExist()) {
        cout<<"[Error]: Table "<<this->tableName<<" exist"<<endl;
        return;
    }

    buffer = this->tableName;

    cout<<columnNames<<endl;

    char* token = strtok(this->columnNames, ",");
    while (token != nullptr)
    {
        strcat(buffer, " # ");
        strcat(buffer, token);

        char* tempBuffer = new char[this->lenBuffer];
        strncpy(tempBuffer, token, this->lenBuffer);
        char* token2 = strtok(tempBuffer, " ");

        cout<<token2<<endl;

        token = strtok(nullptr, ",");
    }
    

    cout<<buffer;

}

#endif