#ifndef MY_STRTOK
#define MY_STRTOK

#include <iostream>
#include <cstring>

char* myStrtok(char* str, const char* delimiter) {
    static char* buffer = nullptr;
    if (str != nullptr)
        buffer = str;
    else if (buffer == nullptr)
        return nullptr;

    char* token = buffer;
    char* delimiterPtr = std::strpbrk(buffer, delimiter);

    if (delimiterPtr != nullptr) {
        *delimiterPtr = '\0';
        buffer = delimiterPtr + 1;
    }
    else
        buffer = nullptr;

    return token;
}

#endif