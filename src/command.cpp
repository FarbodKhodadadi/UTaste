#include "command.hpp"

CommandHandle::CommandHandle(vector<Restaurant*>& restaurants_,vector<Distirict*>& distiricts_):
                            restaurants(restaurants_),distiricts(distiricts_){};

void CommandHandle::commandHandle(const string& input){
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
        throw 
}
