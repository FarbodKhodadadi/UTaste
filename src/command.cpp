#include "command.hpp"

CommandHandle::CommandHandle(vector<Restaurant*>& restaurants_,vector<District*>& districts_):
                            restaurants(restaurants_),districts(districts_){}

void CommandHandle::commandProcess(const string& input){
    auto tokens = Utility::split(input,' ');
    
    string command =tokens[0];
    if(command==GET)
        getCommand(tokens);
    else if(command == PUT)
        putCommand(tokens);
    else if(command == DELETE)
        deleteCommand(tokens);
    else if(command ==POST)
        postCommand(tokens);
    else
        throw BadReqException(BAD_REQ);
}

void CommandHandle::deleteCommand(const vector<string> &command_line){

}

void CommandHandle::getCommand(const vector<string> &command_line){

}

void CommandHandle::postCommand(const vector<string> &command_line){
    string action=command_line[1];

    if(action==SIGNUP)
        signup(command_line);
    else if(action==LOGIN)
        login(command_line);
    else if(action==LOGOUT)
        logout(command_line);
    else
        throw NotFoundException(NOT_FOUND);
}

void CommandHandle::putCommand(const vector<string> &command_line){

}
void CommandHandle::signup(const vector<string>& command_line){

    if(command_line.size() < 7)
        throw BadReqException(BAD_REQ);
    map<string,string> args=Utility::commandArgs(command_line);

    

}
void CommandHandle::login(const vector<string>& command_line){}
void CommandHandle::logout(const vector<string>& command_line){}