//
// Created by loewi on 25.05.16.
//

#ifndef PRAKTIKUM3_HELPER_H
#define PRAKTIKUM3_HELPER_H


#include <stdlib.h>
#include <string>

class Helper {
public:
    static std::string randomString(int size) {
        int i;
        std::string str;
        for (i = 0; i < size; ++i) {
            str.push_back((char)((std::rand() % 26) + 'A'));
        }
        return str;
    }

};


#endif //PRAKTIKUM3_HELPER_H
