#ifndef SELECT_FILE
#define SELECT_FILE

#include"DB.h"

void DB::selectFile() {
    // if table doesnt exist
    if(!this->tableExist()) {
        cout<<"[Error]: Table "<<this->tableName<<" doesn't exist"<<endl;
        return;
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
    bool first = true;

    if (tableFile.is_open()) {
        int pos = 0;
        while (tableFile.getline(this->buffer + pos, this->lenBuffer)) {
            
            char* token = myStrtok(this->buffer + pos, ",");

            if(first) {
                bool firstRow = true;
                while(token != nullptr) {
                    if(strstr(this->columnNames, token)) {
                        if(!firstRow) {
                            newTable<<",";
                        } else {
                            firstRow = false;
                        }
                        columnMap[iterator] = 1;
                        newTable<<token;
                        if(token[0] == '\0') cout<<setw(20)<<left<<"null";
                        else cout<<setw(20)<<left<<token;
                    } else {
                        columnMap[iterator] = 0;
                    }
                    ++iterator;
                    token = myStrtok(nullptr, ",");
                }

                cout<<endl;
                newTable<<endl;
                first = false;
            } else {
                iterator = 0;
                bool firstRow = true;
                while(token != nullptr) {
                    if(columnMap[iterator]) {
                        if(!firstRow) {
                            newTable<<",";
                        } else {
                            firstRow = false;
                        }
                        newTable<<token;
                        if(token[0] == '\0') cout<<setw(20)<<left<<"null";
                        else cout<<setw(20)<<left<<token;
                    }
                    ++iterator;
                    token = myStrtok(nullptr, ",");
                }
                cout<<endl;
                newTable<<endl;
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