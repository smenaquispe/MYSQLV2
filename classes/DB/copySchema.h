#ifndef COPY_SCHEMA
#define COPY_SCHEMA

#include"DB.h"

void DB::copySchema() {
    
    // open schema file
    ifstream schemasFile("./db/schema");

    char tempString[1024];

    if (schemasFile.is_open()) {
        int pos = 0;
        while (schemasFile.getline(this->buffer + pos, this->lenBuffer)) {
            
            char* tempBuffer = new char[this->lenBuffer];
            strncpy(tempBuffer, this->buffer + pos, this->lenBuffer);
            char* token = strtok(tempBuffer, ",");

            if(!strcmp(token,this->tableName)) {
                strcpy(tempString, buffer + pos);
            }   

            delete tempBuffer;

            if(pos >= sizeof(this->buffer)) {
                pos = 0;
            }

        }
    } else {
        cout<<"Can't open file"<<"./db/schema"<<endl;
    }
    
    schemasFile.close();

    ofstream schemasFile_out("./db/schema", std::ios::app);

    char * pos = strstr(tempString, this->tableName);
    if(pos != NULL) {
        strcpy(pos, this->fileName);
        if(strlen(this->fileName) < strlen(this->tableName)) {
            strcpy(pos + strlen(this->fileName), pos + strlen(this->tableName));
        }
    }
    
    if(schemasFile_out.is_open())
        schemasFile_out<<tempString<<endl;
}

#endif