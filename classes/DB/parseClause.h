#ifndef PARSE_CLAUSE
#define PARSE_CLAUSE

#include"DB.h"
#include<regex>

bool equal_op(char *, char *);
bool higher_than(char *, char *);
bool lower_than(char *, char *);
bool higher_equal_than(char *, char *);
bool lower_equal_than(char *, char *);


void DB::parseClause() {
    regex pattern(R"((\w+)\s*([><=!]+)\s*(\w+))");
    smatch match;

    string c = string(clause);

    if (regex_search(c, match, pattern)) {
        this->columnCompare = strdup(match[1].str().c_str());
        this->valueCompare = strdup(match[3].str().c_str());

        char * operator_ = strdup(match[2].str().c_str());

        if (!strcmp(operator_,"=")) {
            this->condition = equal_op;
            return;
        } else if (!strcmp(operator_,">")) {
            this->condition = higher_than;
            return;
        } else if (!strcmp(operator_,"<")) {
            this->condition = lower_than;
            return;
        } else if (!strcmp(operator_,">=")) {
            this->condition = higher_equal_than;
            return;
        } else if (!strcmp(operator_,"<=")) {
            this->condition = lower_equal_than;
            return;
        }
    } else {
        cout << "[Error] Syntax error in WHERE clause" << endl;
        return;
    }     
}

bool equal_op(char * param, char * value) {
    return (!strcmp(param, value));
}

bool higher_than(char * param, char * value) {
    int param_ = stoi(param);
    int value_ = stoi(value);
    return (param_ > value_);
}

bool lower_than(char * param, char * value) {
    int param_ = stoi(param);
    int value_ = stoi(value);
    return (param_ < value_);
}

bool higher_equal_than(char * param, char * value) {
    int param_ = stoi(param);
    int value_ = stoi(value);
    return (param_ >= value_);
}

bool lower_equal_than(char * param, char * value) {
    int param_ = stoi(param);
    int value_ = stoi(value);
    return (param_ <= value_);
}

#endif