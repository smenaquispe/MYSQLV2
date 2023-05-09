#ifndef TABLE_EXIST
#define TABLE_EXIST

#include"DB.h"
#include<fstream>
#include<string.h>

bool DB::tableExist() {
    // open schema file
    ifstream schemasFile("./db/schema");

    if (schemasFile.is_open()) {
        int pos = 0;
        while (schemasFile.getline(this->buffer + pos, this->lenBuffer)) {
            char* token = strtok(this->buffer + pos, " # ");
            if(!strcmp(token,this->tableName)) {
                return true;
            }
                
            if(pos >= sizeof(this->buffer)) {
                pos = 0;
            }

        }
    } else {
        cout<<"Can't open file"<<"./db/schema"<<endl;
    }
    
    schemasFile.close();

    return false;
}
#endif