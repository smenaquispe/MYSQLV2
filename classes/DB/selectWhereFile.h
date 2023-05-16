#ifndef SELECT_WHERE_FILE
#define SELECT_WHERE_FILE

#include"DB.h"

void DB::selectWhereFile() {
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

    // create a new schema
    this->createSchema();

    // creating the new file table
    char newTableFile[256];
    strcpy(newTableFile, "./db/tables/");
    strcat(newTableFile,this->fileName);
    ofstream newTable(newTableFile);

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

            char* token = strtok(tempBuffer, ",");
            while(token != nullptr) {
                if(columnNumber == columnWhere && strcmp(token, this->columnCompare)) {
                    if(condition(token, this->valueCompare)) {
                        band = true;
                        break;
                    } 
                } 
                token = strtok(nullptr, ",");
                ++columnNumber;
            }

            delete tempBuffer;
            
            
            if(first || band) {
                char* tempBuffer = new char[this->lenBuffer];
                strncpy(tempBuffer, this->buffer + pos, this->lenBuffer);

                char* token = strtok(tempBuffer, ",");
                if(first) {
                    bool firstRow = true;
                    while(token != nullptr) {
                        if(strstr(this->columnNames, token)) {
                            columnMap[iterator] = 1;
                            if(!firstRow) {
                                newTable<<",";
                            } else {
                                firstRow = false;
                            }
                            newTable<<token;
                            cout<<setw(20)<<left<<token;
                        } else {
                            columnMap[iterator] = 0;
                        }
                        ++iterator;
                        token = strtok(nullptr, ",");
                    }   
                    first = false;
                } else {
                    iterator = 0;
                    bool firstRow = true;
                    while(token != nullptr) {
                        if(columnMap[iterator]){
                            if(!firstRow) {
                                newTable<<",";
                            } else {
                                firstRow = false;
                            }
                            newTable<<token;
                            cout<<setw(20)<<left<<token;
                        }
                        ++iterator;
                        token = strtok(nullptr, ",");
                    }
                }

                cout<<endl;
                newTable<<endl;

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