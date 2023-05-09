#ifndef RUN
#define RUN

#include"Controller.h"
#include<string.h>

void Controller::run() {
    
    size_t lenInput = 256;
    char input[lenInput];

    // vars to extract of the input
    char * columnNames = nullptr;
    char * nameTable = nullptr;
    char * clause = nullptr;
    char * fileName = nullptr;

    // get the regex
    regex select_pattern(this->select_string,regex_constants::icase);
    regex select_where_pattern(this->select_where_string,regex_constants::icase);
    regex select_where_file_pattern(this->select_where_file_string,regex_constants::icase);
    regex create_table_pattern(this->create_table_string,regex_constants::icase);

    //mathc
    smatch match;

    do{
        if(!this->inSession) cout<<"% ";
        else cout<<"> ";

        cin.getline(input, lenInput);
 
        if(input == "\n") continue;

        this->init(input);
        this->quit(input);

        // just if is in session
        if(this->inSession) {
            
            string strInput = string(input);

            // case create table
            if(regex_match(strInput, match, create_table_pattern)){
                nameTable = strdup(match[1].str().c_str());
                columnNames = strdup(match[2].str().c_str());

                db->setProps(columnNames, nameTable);
                db->createTable();
            }

            // case of select where but save in file
            else if(regex_match(strInput, match, select_where_file_pattern)) {
                columnNames = strdup(match[1].str().c_str());
                nameTable = strdup(match[2].str().c_str());
                clause = strdup(match[3].str().c_str());
                fileName = strdup(match[4].str().c_str());

                db->setProps(columnNames, nameTable, clause, fileName);

                
                if(!strcmp(columnNames, "*")) db->selectAllWhereFile();
                else db->selectWhereFile();
            }
            
            
            // case of select where
            else if(regex_match(strInput, match, select_where_pattern)) {
                columnNames = strdup(match[1].str().c_str());
                nameTable = strdup(match[2].str().c_str());
                clause = strdup(match[3].str().c_str());

                db->setProps(columnNames, nameTable, clause);

                if(!strcmp(columnNames, "*")) db->selectAllWhere();
                else db->selectWhere();
            }
            
            // case of just select
            else if(regex_match(strInput, match, select_pattern)) {
                columnNames = strdup(match[1].str().c_str());
                nameTable = strdup(match[2].str().c_str());

                db->setProps(columnNames, nameTable);

                if(!strcmp(columnNames, "*")) db->selectAll();
                else db->select();
            }

            //if(columnNames) free(columnNames);
            //if(nameTable) free(nameTable);
            //if(clause) free(clause);
            
        }


    } while(this->isOpen);

}

#endif