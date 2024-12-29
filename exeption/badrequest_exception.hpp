#ifndef BAD_REQ_EXCEPTION_H
#define BAD_REQ_EXCEPTION_H

#include "exception.hpp"

class BadReqException : public Exception{
public:
    BadReqException(): Exception(){};;
    BadReqException(std::string bad_request_message) : Exception(bad_request_message){};
    static std::string getMessageBadRequest(){return "Bad Request";}

};

#endif