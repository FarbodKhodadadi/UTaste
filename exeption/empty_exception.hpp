#include "exception.hpp"

class PermissionException : public Exception{
public:
    PermissionException();
    PermissionException(std::string empty_message) : Exception(exception_message){};
    static std::string getMessageEmpty(){return "Empty";}

};