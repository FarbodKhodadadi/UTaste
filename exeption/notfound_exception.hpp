#include "exception.hpp"

class NotFoundException : public Exception{
public:
    NotFoundException();
    NotFoundException(std::string not_found_message) : Exception(exception_message){};
    static std::string getMessageNotFound(){return "Not Found";}

};