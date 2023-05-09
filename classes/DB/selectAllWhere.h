#ifndef SELECT_ALL_WHERE
#define SELECT_ALL_WHERE

#include"DB.h"

void DB::selectAllWhere() {
    
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

    // select all where
// print row of the table
    char fileName[256];

    strcpy(fileName, "./db/tables/");
    strcat(fileName, this->tableName);

    ifstream tableFile(fileName);

    if (tableFile.is_open()) {
        int pos = 0;
        bool first = true;
        while (tableFile.getline(this->buffer + pos, this->lenBuffer)) {

            bool band = false;
            int columnNumber = 0;

            char* tempBuffer = new char[this->lenBuffer];
            strncpy(tempBuffer, this->buffer + pos, this->lenBuffer);

            char* token = strtok(tempBuffer, " # ");
            while(token != nullptr) {
                if(columnNumber == columnWhere && strcmp(token, this->columnCompare)) {
                    
                    if(condition(token, this->valueCompare)) {
                        band = true;
                        break;
                    } 
                } 
                token = strtok(nullptr, " # ");
                ++columnNumber;
            }

            delete tempBuffer;
            
            
            if(first || band) {
                char* tempBuffer = new char[this->lenBuffer];
                strncpy(tempBuffer, this->buffer + pos, this->lenBuffer);

                char* token = strtok(tempBuffer, " # ");
                while(token != nullptr) {
                    cout<<setw(20)<<left<<token;
                    token = strtok(nullptr, " # ");
                }   

                cout<<endl;

                delete tempBuffer;
                first = false;
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