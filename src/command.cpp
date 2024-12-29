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
    else if(command == "show")
        showUsers(tokens);
    else
        throw BadReqException(BAD_REQ);
}

void CommandHandle::postCommand(const vector<string> &command_line){
    string action=command_line[1];
    if(action==SIGNUP)
        signup(command_line);
    else if(action==LOGIN)
        login(command_line);
    else if(action==LOGOUT)
        logout(command_line);
    else if(action==RESERVES)
        postReserve(command_line);
    else
        throw NotFoundException(NOT_FOUND);
}
void CommandHandle::postReserve(const vector<string>& command_line){
    if(command_line.size() < 13)
        throw BadReqException(BAD_REQ);
    if(current_user !=nullptr)
        throw PermisionException(PERMISSION_DENIED);

    map<string,string> args=Utility::commandArgs(command_line);
    if(args.find(RESTAURANT_NAME) == args.end() || args.find(TABLE_ID)==args.end() ||
        args.find(START_TIME)==args.end() || args.find(END_TIME)==args.end() || args.find(FOODS)==args.end())
        throw BadReqException(BAD_REQ);
    string restaurant_name = Utility::removeQuotation(args.find(RESTAURANT_NAME)->second);
    int table_id = stoi(Utility::removeQuotation(args.find(TABLE_ID)->second));
    int start_time = stoi(Utility::removeQuotation(args.find(START_TIME)->second));
    int end_time = stoi(Utility::removeQuotation(args.find(END_TIME)->second));
    string foods=Utility::removeQuotation(args.find(FOODS)->second);
    auto order=Utility::orderHandle(foods);

    auto res_ptr=findRestaurant(restaurant_name);
    if(res_ptr==nullptr)
        throw NotFoundException(NOT_FOUND);
    if(start_time<0 || start_time>24 || end_time<0 || end_time>24 || !res_ptr->checkReserve(table_id,start_time,end_time) 
        || !current_user->checkUserReserve(start_time,end_time) || !res_ptr->checkWorkingTime(start_time,end_time) || res_ptr->checkTable(table_id)){
        throw PermisionException(PERMISSION_DENIED);
    }
    if(!res_ptr->checkMenu(order))
        throw NotFoundException(NOT_FOUND);

    int reserve_id=res_ptr->last_reserve_id +=1;

    auto res_class=new Reservation(reserve_id,start_time,end_time,restaurant_name,order,table_id);

    res_ptr->reservations.push_back(res_class);
    current_user->reserves.push_back(res_class);

    res_class=nullptr;
}
void CommandHandle::signup(const vector<string>& command_line){

    if(command_line.size() < 7)
        throw BadReqException(BAD_REQ);
    if(current_user !=nullptr)
        throw PermisionException(PERMISSION_DENIED);

    map<string,string> args=Utility::commandArgs(command_line);
    if(args.find("username") == args.end() || args.find("password")==args.end())
        throw BadReqException(BAD_REQ);
    
    string input_username = Utility::removeQuotation(args.find("username")->second);
    string input_password = Utility::removeQuotation(args.find("password")->second);
    
    if(findUser(input_username)!=nullptr)
        throw BadReqException(BAD_REQ);

    OK();

    current_user=new User(input_username,input_password,true);
    users.push_back(current_user);
    
}

void CommandHandle::login(const vector<string>& command_line){
    if(command_line.size() < 7)
            throw BadReqException(BAD_REQ);
    if(current_user!= nullptr)
        throw PermisionException(PERMISSION_DENIED);

    map<string,string> args=Utility::commandArgs(command_line);
    if(args.find(USERNAME) == args.end() || args.find(PASSWORD)==args.end())
        throw BadReqException(BAD_REQ);
    string input_username = Utility::removeQuotation(args.find(USERNAME)->second);
    string input_password = Utility::removeQuotation(args.find(PASSWORD)->second);

    auto user = findUser(input_username);
    if(user==nullptr)
        throw NotFoundException(NOT_FOUND);

    if(input_password == user->getPassword()){
        current_user=user;
        current_user->loged_in=true;
        OK();
    }else
        throw PermisionException(PERMISSION_DENIED);
}
//Test method
void CommandHandle::showUsers(const vector<string>& command_line){
    for(auto& res:restaurants){
        cout <<res->getName()<<endl;
    }
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
    cerr << "OK" << endl;
}

User* CommandHandle::findUser(string username){
    for(int i =0 ;i <users.size();i++){
        if(users[i]->getUsername() == username){
            return users[i];
        }
    }
    return nullptr;
}

void CommandHandle::getCommand(const vector<string> &command_line){
    string action=command_line[1];
    if(action==DISTRICT_COMM)
        getDistrict(command_line);
    else if(action==RESTAURANT)
        getRestaurant(command_line);
    else if(action==RESTAURANTS_DETAILS)
        getRestaurantDetails(command_line);
    else if(action==RESERVES)
        getReserves(command_line);
    else
        throw NotFoundException(NOT_FOUND);
}

void CommandHandle::getDistrict(const vector<string> &command_line){
    if(command_line.size() < 3)
            throw BadReqException(BAD_REQ);
    if(current_user == nullptr)
        throw PermisionException(PERMISSION_DENIED);

    map<string,string> args=Utility::commandArgs(command_line);
    if(args.find(DISTRICT) != args.end()){
        string district = Utility::removeQuotation(args.find(DISTRICT)->second);
        auto dis_ptr =findDistrict(district);
        if(dis_ptr==nullptr)
            throw NotFoundException(NOT_FOUND);
        dis_ptr->printDistrict();
        return;
    }
    else{
        if(districts.empty())
            throw EmptyException(EMPTY);
        sort(districts.begin(), districts.end(), [](District* a, District* b) {
            return a->getName() < b->getName();
        });
        for(auto& district : districts) {
            district->printDistrict();
        }
    }
}

void CommandHandle::getRestaurant(const vector<string> &command_line){
    if(command_line.size() < 3)
            throw BadReqException(BAD_REQ);
    if(current_user == nullptr)
        throw PermisionException(PERMISSION_DENIED);

    map<string,string> args=Utility::commandArgs(command_line);
    if(args.find(FOOD_NAME) != args.end()){
        
    }
}

void CommandHandle::getRestaurantDetails(const vector<string> &command_line){
    if(command_line.size() < 5)
            throw BadReqException(BAD_REQ);
    if(current_user == nullptr)
        throw PermisionException(PERMISSION_DENIED);
    map<string,string> args=Utility::commandArgs(command_line);

    if(args.find(RESTAURANT_NAME) != args.end()){

        string restaurant = Utility::removeQuotation(args.find(RESTAURANT_NAME)->second);

        auto res_ptr =findRestaurant(restaurant);
        if(res_ptr==nullptr)
            throw NotFoundException(NOT_FOUND);
        res_ptr->printRestaurant();
    }else
        throw BadReqException(BAD_REQ);
}

Restaurant* CommandHandle::findRestaurant(const string name){
    for(int i=0 ; i<restaurants.size() ;i++){
        if(restaurants[i]->getName()==name)
            return restaurants[i];
    }
    return nullptr;
}
void CommandHandle::getReserves(const vector<string> &command_line){
    
}

District* CommandHandle::findDistrict(const string name){
    for(int i=0 ; i<districts.size() ;i++){
        if(districts[i]->getName()==name)
            return districts[i];
    }
    return nullptr;
}

void CommandHandle::deleteCommand(const vector<string> &command_line){

}

void CommandHandle::putCommand(const vector<string> &command_line){
    string action=command_line[1];
    if(action==MY_DISTRICT)
        setDistrict(command_line);
    else
        throw NotFoundException(NOT_FOUND);
}

void CommandHandle::setDistrict(const vector<string>& command_line){
    if(command_line.size() < 5)
            throw BadReqException(BAD_REQ);
    if(current_user == nullptr)
        throw PermisionException(PERMISSION_DENIED);

    map<string,string> args=Utility::commandArgs(command_line);
    if(args.find(DISTRICT) != args.end()){
        string district = Utility::removeQuotation(args.find(DISTRICT)->second);
        auto dis_ptr =findDistrict(district);
        if(dis_ptr==nullptr)
            throw NotFoundException(NOT_FOUND);
        current_user->user_district=dis_ptr;
        return;
    }else
        throw BadReqException(BAD_REQ);
}