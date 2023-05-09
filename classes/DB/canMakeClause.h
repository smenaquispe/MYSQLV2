#ifndef CAN_MAKE_CLAUSE
#define CAN_MAKE_CLAUSE

#include"DB.h"

int DB::canMakeClause() {
    // if columncompare exists
    // open schema file
    ifstream schemasFile("./db/schema");

    if (schemasFile.is_open()) {
        int pos = 0;
        while (schemasFile.getline(this->buffer + pos, this->lenBuffer)) {
            char* token = strtok(this->buffer + pos, " # ");
            if(!strcmp(token,this->tableName)) {
                int count = -1;
                while (token != nullptr)
                {
                    if(!strcmp(token, this->columnCompare)) {
                        return count / 2;
                    }
                    count++;
                    token = strtok(nullptr, " # ");
                }
                
            }
                
            if(pos >= sizeof(this->buffer)) {
                pos = 0;
            }

        }
    } else {
        cout<<"Can't open file"<<"./db/schema"<<endl;
    }
    
    schemasFile.close();

    return -1;
}

#endif