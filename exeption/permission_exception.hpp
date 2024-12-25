#include "exception.hpp"

class PermissionException : public Exception{
public:
    PermissionException();
    PermissionException(std::string Permission_message) : Exception(exception_message){};
    static std::string getMessagePermission(){return "Permission Denied";}

};