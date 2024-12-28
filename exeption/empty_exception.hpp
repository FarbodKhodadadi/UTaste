#ifndef EMPTY_EXCEPTION_H
#define EMPTY_EXCEPTION_H

#include "exception.hpp"

class EmptyException : public Exception{
public:
    EmptyException(): Exception(){};
    EmptyException(std::string empty_message) : Exception(exception_message){};
    static std::string getMessageEmpty(){return "Empty";}

};

#endif