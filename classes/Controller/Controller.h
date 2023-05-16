#ifndef CONTROLLER
#define CONTROLLER

#include<iostream>
#include<regex>
using namespace std;

#include"../DB/DB.h"

class Controller
{
private:

    DB * db;

    const char * init_string = "MEGATRON3000";
    const char * quit_string = "QUIT";
    const char * insert_string = "& INSERT INTO (.*) \\((.*)\\) #";
    const char * select_string = "& SELECT (.*) FROM (.*) #";
    const char * select_file_string = "& SELECT (.*) FROM (.*) \\| (.*) #";
    const char * select_where_string = "& SELECT (.*) FROM (.*) WHERE (.*) #";
    const char * select_where_file_string = "& SELECT (.*) FROM (.*) WHERE (.*) \\| (.*) #";
    const char * create_table_string = "& CREATE TABLE (.*) \\((.*)\\) #";

    // comparision (where clause)
    char * clause;

    // variables de la sesion y vida del programa
    bool inSession;
    bool isOpen;


    // iniciar y terminar session
    void init(char *);
    void quit(char *);

public:
    Controller(DB * db);
    ~Controller();

    void run();
};

Controller::Controller(DB * db)
{
    this->db = db;
    inSession = false;
    isOpen = true;
}

Controller::~Controller()
{
}

#include"run.h"
#include"init.h"
#include"quit.h"

#endif