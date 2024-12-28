#include "command.hpp"

CommandHandle::CommandHandle(vector<Restaurant*>& restaurants_,vector<District*>& districts_,vector<User*>& users_):
                            restaurants(restaurants_),districts(districts_),users(users_){}

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
void CommandHandle::putCommand(const vector<string> &command_line){

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

void CommandHandle::signup(const vector<string>& command_line){

    if(command_line.size() < 7)
        throw BadReqException(BAD_REQ);
    if(current_user !=nullptr)
        throw PermisionException(PERMISSION_DENIED);

    map<string,string> args=Utility::commandArgs(command_line);
    if(args.find("username") == args.end() || args.find("password")==args.end())
        throw BadReqException(BAD_REQ);
    
    string username = Utility::removeQuotation(args.find("username")->second);
    string password = Utility::removeQuotation(args.find("password")->second);
    
    if(findUser(username)!=nullptr)
        throw BadReqException(BAD_REQ);
    OK();

    current_user=new User(username,password,true);
    users.push_back(current_user);
    
}

void CommandHandle::login(const vector<string>& command_line){
    if(command_line.size() < 7)
            throw BadReqException(BAD_REQ);
    if(current_user!= nullptr)
        throw PermisionException(PERMISSION_DENIED);

    map<string,string> args=Utility::commandArgs(command_line);
    if(args.find("username") == args.end() || args.find("password")==args.end())
        throw BadReqException(BAD_REQ);
    string username = Utility::removeQuotation(args.find("username")->second);
    string password = Utility::removeQuotation(args.find("password")->second);

    auto user = findUser(username);
    if(user==nullptr)
        throw NotFoundException(NOT_FOUND);
    
    if(user->getPassword() != password)
        throw PermisionException(PERMISSION_DENIED);

    user->loged_in=true;
    current_user=user;
    OK();
}

void CommandHandle::logout(const vector<string>& command_line){
    if(command_line.size() < 3)
            throw BadReqException(BAD_REQ);
    if(current_user == nullptr)
        throw PermisionException(PERMISSION_DENIED);
    
    current_user->loged_in=false;
    current_user=nullptr;
    OK();
}

void CommandHandle::OK(){
    cout << OK << endl;
}

bool CommandHandle::checkUsername(const string username){
    for(int i =0 ;i <users.size();i++){
        if(users[i]->getUsername() == username){
            return true;
        }
    }
    return false;
}
string CommandHandle::checkPassword(const string username){
    for(int i =0 ;i <users.size();i++){
        if(users[i]->getUsername() == username){
            return users[i]->getPassword();
        }
    }
}
User* CommandHandle::findUser(const string username){
    for(int i =0 ;i <users.size();i++){
        if(users[i]->getUsername() == username){
            return users[i];
        }
    }
    return nullptr;
}