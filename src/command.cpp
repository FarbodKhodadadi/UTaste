#include "command.hpp"


CommandHandle::CommandHandle(vector<Restaurant*>& restaurants_,vector<Distirict*>& distiricts_):
                            restaurants(restaurants_),distiricts(distiricts_){}

void CommandHandle::commandProsses(const string& input){
    auto tokens = Utility::split(input,' ');
    
    string command =tokens[0];
    if(command=GET)
        getCommand(tokens);
    else if(command = PUT)
        putCommand(tokens);
    else if(command = DELETE)
        deleteCommand(tokens);
    else if(command =POST)
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

    if(action=SIGNUP)
        signup(command_line);
    else if(action=LOGIN)
        login(command_line);
    else if(action=LOGOUT)
        logout(command_line);
    else
        throw NotFoundException(NOT_FOUND);
}

void CommandHandle::putCommand(const vector<string> &command_line){

}
void CommandHandle::signup(const vector<string>& command_line){
    if(command_line.size() < 7)
        throw BadReqException(BAD_REQ);
    for(int i=0 ;i<command_line.size();i++){
        if(command_line[i]=="username")
            string username= command_line[i+1];
        if(command_line[i]="password")
            string password= command_line[i+1];
    }
    
    
}
void CommandHandle::login(const vector<string>& command_line){}
void CommandHandle::logout(const vector<string>& command_line){}