#ifndef QUIT
#define QUIT

#include"Controller.h"

void Controller::quit(char * input) {
    /** break the session but not quit the program */
    regex quit_pattern(this->quit_string, regex_constants::icase);

    if (regex_match(input, quit_pattern)){
        this->inSession = false;
    }
}

#endif