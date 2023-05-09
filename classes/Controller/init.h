#ifndef INIT
#define INIT

#include"Controller.h"
#include<regex>

void Controller::init(char * input) {
    regex init_pattern(this->init_string, regex_constants::icase);

    if (regex_match(input, init_pattern)) {
        if(this->inSession) cout<<"You've already stayed in MEGATRON3000\n";
        else {
            cout<<"Welcome to MEGATRON 3000 !\n";     
            this->inSession = true;
        }
    } 
}

#endif