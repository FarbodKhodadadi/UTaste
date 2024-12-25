#include "exception.hpp"

class PermissionException : public Exception{
public:
    PermissionException();
    PermissionException(std::string bad_request_message) : Exception(exception_message){};
    static std::string getMessageBadRequest(){return "Bad Request";}

};