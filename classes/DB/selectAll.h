#ifndef SELECT_ALL
#define SELECT_ALL

#include"DB.h"
#include<iostream>
#include<iomanip>
#include"../../utils/myStrtok.h"

void DB::selectAll() {

    // if table doesnt exist
    if(!this->tableExist()) {
        cout<<"[Error]: Table "<<this->tableName<<" doesn't exist"<<endl;
        return;
    }

    // print row of the table
    char fileName[256];

    strcpy(fileName, "./db/tables/");
    strcat(fileName, this->tableName);

    ifstream tableFile(fileName);

    if (tableFile.is_open()) {
        int pos = 0;
        while (tableFile.getline(this->buffer + pos, this->lenBuffer)) {
            char* token = myStrtok(this->buffer + pos, ",");
            while(token != nullptr) {
                if(token[0] == '\0') cout<<setw(20)<<left<<"null";
                else cout<<setw(20)<<left<<token;
                token = myStrtok(nullptr, ",");
            }
            
            cout<<endl;

            pos += tableFile.gcount();

            if(pos >= sizeof(this->buffer)) {
                pos = 0;
            }
        }
    } else {
        cout<<"Can't open file "<<this->tableName<<endl;
    }

    tableFile.close();

}

#endif