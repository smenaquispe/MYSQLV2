#ifndef INSERT
#define INSERT

#include"DB.h"

void DB::insert() {
    // if table doesnt exist
    if(!this->tableExist()) {
        cout<<"[Error]: Table "<<this->tableName<<" doesn't exist"<<endl;
        return;
    }

    int countSchema = 0;
    ifstream schemasFile("./db/schema");
    if (schemasFile.is_open()) {
        int pos = 0;
        while (schemasFile.getline(this->buffer + pos, this->lenBuffer)) {
            char* token = strtok(this->buffer + pos, ",");
            if(!strcmp(token,this->tableName)) {
                while (token != nullptr)
                {
                    ++countSchema;
                    token = strtok(nullptr, ",");
                }
                break;
            }
                
            if(pos >= sizeof(this->buffer)) {
                pos = 0;
            }

        }
    }

    // test if the value inputs are equivalent to schema
    int countInput = 0;

    char* copy = new char[strlen(columnNames) + 1];
    strcpy(copy, columnNames);
    char* token = myStrtok(copy, ", ");
    while (token != nullptr)
    {
        ++countInput;
        token = myStrtok(nullptr, ", ");
    }
    delete copy;

    countSchema = (countSchema-1)/2;
    if(countSchema == countInput) {    
        char fileName[256];

        strcpy(fileName, "./db/tables/");
        strcat(fileName, this->tableName);

        ofstream tableFile(fileName, ios::app);
        if(tableFile.is_open()) {
            tableFile<<endl<<columnNames;
            tableFile.close();
        }

        cout<<columnNames<<" added to "<<this->tableName<<endl;
    } else {
        cout<<"[Error]: Check schema, can't save this columns"<<endl;
    }
}

#endif