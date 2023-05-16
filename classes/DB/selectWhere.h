#ifndef SELECT_WHERE
#define SELECT_WHERE

#include"DB.h"
#include"../../utils/myStrtok.h"

void DB::selectWhere() {
    // if table doesnt exist
    if(!this->tableExist()) {
        cout<<"[Error]: Table "<<this->tableName<<" doesn't exist"<<endl;
        return;
    }

        // parse clause of where
    this->parseClause();

    // find column with column compare
    int columnWhere = this->canMakeClause();
    if(columnWhere == -1) {
        cout<<"[Error]: Where clause: "<<this->clause<<" isn't allowed"<<endl;
    }

    // print row of the table
    char fileName[256];

    strcpy(fileName, "./db/tables/");
    strcat(fileName, this->tableName);

    ifstream tableFile(fileName);

    
    int columnMap[256];
    int iterator = 0;


    if (tableFile.is_open()) {
        int pos = 0;
        bool first = true;
        while (tableFile.getline(this->buffer + pos, this->lenBuffer)) {

            
            bool band = false;
            int columnNumber = 0;

            char* tempBuffer = new char[this->lenBuffer];
            strncpy(tempBuffer, this->buffer + pos, this->lenBuffer);

            char* token = myStrtok(tempBuffer, ",");
            while(token != nullptr) {
                if(columnNumber == columnWhere && strcmp(token, this->columnCompare)) {
                    if(condition(token, this->valueCompare)) {
                        band = true;
                        break;
                    } 
                } 
                token = myStrtok(nullptr, ",");
                ++columnNumber;
            }

            delete tempBuffer;
            
            
            if(first || band) {
                char* tempBuffer = new char[this->lenBuffer];
                strncpy(tempBuffer, this->buffer + pos, this->lenBuffer);

                char* token = myStrtok(tempBuffer, ",");
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
                }

                cout<<endl;

                delete tempBuffer;
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