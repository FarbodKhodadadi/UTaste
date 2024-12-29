#include "exception.hpp"

class NotFoundException : public Exception{
public:
    NotFoundException(): Exception(){};
    NotFoundException(std::string not_found_message) : Exception(not_found_message){};
    static std::string getMessageNotFound(){return "Not Found";}

};