#ifndef SELECT
#define SELECT

#include"DB.h"
#include"../../utils/myStrtok.h"

void DB::select() {
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


    int columnMap[256];
    int iterator = 0;
    bool first = true;

    if (tableFile.is_open()) {
        int pos = 0;
        while (tableFile.getline(this->buffer + pos, this->lenBuffer)) {
            
            char* token = myStrtok(this->buffer + pos, ",");

            if(first) {
                while(token != nullptr) {
                    if(strstr(this->columnNames, token)) {
                        columnMap[iterator] = 1;
                        if(token[0] == '\0') cout<<setw(20)<<left<<"null";
                        else cout<<setw(20)<<left<<token;
                    } else {
                        columnMap[iterator] = 0;
                    }
                    ++iterator;
                    token = myStrtok(nullptr, ",");
                }

                cout<<endl;
                first = false;
            } else {
                iterator = 0;
                while(token != nullptr) {
                    if(columnMap[iterator]) {
                        if(token[0] == '\0') cout<<setw(20)<<left<<"null";
                        else cout<<setw(20)<<left<<token;
                    }
                    ++iterator;
                    token = myStrtok(nullptr, ",");
                }
                cout<<endl;
            }
            
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