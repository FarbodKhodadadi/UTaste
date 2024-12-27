#include "exception.hpp"

class PermisionException : public Exception{
public:
    PermisionException(): Exception(){};
    PermisionException(std::string Permission_message) : Exception(exception_message){};
    static std::string getMessagePermission(){return "Permission Denied";}

};