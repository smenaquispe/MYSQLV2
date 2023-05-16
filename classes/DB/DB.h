#ifndef DB_
#define DB_

#include<iostream>
using namespace std;

class DB
{
private:

    // memory buffer
    size_t lenBuffer;
    char * buffer;

    // recieve of statement
    char * columnNames;
    char * tableName;
    char * clause;
    char * fileName;

    // clause parsed vars
    char * columnCompare;
    char * valueCompare;
    bool (*condition)(char *, char *);

public:
    DB();
    ~DB();

    // firs just select column and table
    void setProps(char *, char *);
    // set props but select need 3 props, so bool is for decoration
    void setProps(char *, char *, char *, bool);
    // secon select column, table and where clause
    void setProps(char *, char *, char *);
    // thir seledt, columns table clause and file to save
    void setProps(char *, char *, char *, char *);

    // select all
    void selectAll();
    // select
    void select();
    // select some columns and save in file
    void selectFile();
    // select all where
    void selectAllWhere();
    // select where
    void selectWhere();

    // select all where and save in file
    void selectAllWhereFile();
    // select where and save in file
    void selectWhereFile();
    
    // create table
    void createTable();

    // insert
    void insert();


    // when select all you can copy schema
    void copySchema();
    // will create a shcema in base of other
    void createSchema();


    // check if table exist
    bool tableExist();
    // parse the clause
    void parseClause();
    // check if clause is allow
    int canMakeClause();

};

DB::DB()
{
    lenBuffer = 1024;
    buffer = new char[lenBuffer];
}

DB::~DB()
{
    delete buffer;
}

#include"setProps.h"
#include"tableExist.h"
#include"parseClause.h"
#include"canMakeClause.h"
#include"selectAll.h"
#include"selectAllWhere.h"
#include"select.h"
#include"selectFile.h"
#include"selectWhere.h"
#include"selectAllWhereFile.h"
#include"selectWhereFile.h"
#include"createTable.h"
#include"copySchema.h"
#include"createSchema.h"
#include"insert.h"

#endif