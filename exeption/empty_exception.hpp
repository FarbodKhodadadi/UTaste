#include "exception.hpp"

class EmptyException : public Exception{
public:
    EmptyException();
    EmptyException(std::string empty_message) : Exception(exception_message){};
    static std::string getMessageEmpty(){return "Empty";}

};