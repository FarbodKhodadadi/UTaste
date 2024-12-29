#ifndef PERMISSION_EXCEPTION_H
#define PERMISSION_EXCEPTION_H
#include "exception.hpp"

class PermisionException : public Exception{
public:
    PermisionException(): Exception(){};
    PermisionException(std::string Permission_message) : Exception(Permission_message){};
    static std::string getMessagePermission(){return "Permission Denied";}

};

#endif