#include "exception.hpp"

Exception ::Exception(){ exception_message="";}

Exception ::Exception(std::string message){
    exception_message = message;
}

std::string Exception :: getMessage(){return exception_message; }