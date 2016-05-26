//
// Created by loewi on 28.04.16.
//

#ifndef PRAKTIKUM3_SIMPLEEXCEPTION_H
#define PRAKTIKUM3_SIMPLEEXCEPTION_H

#include <string>


class SimpleException {
public:
    SimpleException(std::string message, int code) : _msg(message), _errorCode(code) {

    }

    std::string msg() {
        return _msg;
    }

    int code() {
        return _errorCode;
    }


protected:
    std::string _msg;
    int _errorCode;

};


#endif //PRAKTIKUM3_SIMPLEEXCEPTION_H
