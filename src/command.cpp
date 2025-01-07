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
    else if(action==RESERVE)
        postReserve(command_line);
    else if(action==INCREASE_BUDGET)
        increseBudget(command_line);
    else
        throw NotFoundException(NOT_FOUND);
}
void CommandHandle::postReserve(const vector<string>& command_line){
    if(command_line.size() < 11)
        throw BadReqException(BAD_REQ);
    if(current_user ==nullptr)
        throw PermisionException(PERMISSION_DENIED);

    map<string,string> args=Utility::commandArgs(command_line);

    if(args.find(RESTAURANT_NAME) == args.end() || args.find(TABLE_ID)==args.end() ||
        args.find(START_TIME)==args.end() || args.find(END_TIME)==args.end())
        throw BadReqException(BAD_REQ);

    if(args.find(FOODS)!=args.end()){
        string restaurant_name = Utility::removeQuotation(args.find(RESTAURANT_NAME)->second);
        
        int table_id = stoi(Utility::removeQuotation(args.find(TABLE_ID)->second));
        int start_time = stoi(Utility::removeQuotation(args.find(START_TIME)->second));
        int end_time = stoi(Utility::removeQuotation(args.find(END_TIME)->second));
        string foods=Utility::removeQuotation(args.find(FOODS)->second);
        auto order=Utility::orderHandle(foods);
        auto res_ptr=findRestaurant(restaurant_name);
        if(res_ptr==nullptr)
            throw NotFoundException(NOT_FOUND);

        auto order_price=res_ptr->handlePrice(order);

        if(start_time<0 || start_time>24 || end_time<0 || end_time>24 || res_ptr->checkReserve(table_id,start_time,end_time) 
            || !current_user->checkUserReserve(start_time,end_time) || !res_ptr->checkWorkingTime(start_time,end_time) || !res_ptr->checkTable(table_id)){
            throw PermisionException(PERMISSION_DENIED);
        }

        if(!res_ptr->checkMenu(order)){
            throw NotFoundException(NOT_FOUND);
        }
        int reserve_id=res_ptr->last_reserve_id +=1;

        auto reserve_class=new Reservation(reserve_id,start_time,end_time,restaurant_name,order,table_id,order_price);

        res_ptr->reservations[table_id].push_back(reserve_class);
        current_user->reserves.push_back(reserve_class);
        reserve_class->printReserve();
        reserve_class=nullptr;
        return;
    }else{
        string restaurant_name = Utility::removeQuotation(args.find(RESTAURANT_NAME)->second);
        
        int table_id = stoi(Utility::removeQuotation(args.find(TABLE_ID)->second));
        int start_time = stoi(Utility::removeQuotation(args.find(START_TIME)->second));
        int end_time = stoi(Utility::removeQuotation(args.find(END_TIME)->second));

        auto res_ptr=findRestaurant(restaurant_name);
        if(res_ptr==nullptr)
            throw NotFoundException(NOT_FOUND);
        if(start_time<0 || start_time>24 || end_time<0 || end_time>24 || res_ptr->checkReserve(table_id,start_time,end_time) 
            || !current_user->checkUserReserve(start_time,end_time) || !res_ptr->checkWorkingTime(start_time,end_time) || !res_ptr->checkTable(table_id)){
            throw PermisionException(PERMISSION_DENIED);
        }
        int reserve_id=res_ptr->last_reserve_id +=1;

        auto reserve_class=new Reservation(reserve_id,start_time,end_time,restaurant_name,table_id);

        res_ptr->reservations[table_id].push_back(reserve_class);
        current_user->reserves.push_back(reserve_class);
        reserve_class->printReserve();

        reserve_class=nullptr;
        return;
    } 
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
    if(current_user != nullptr)
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

void CommandHandle::increseBudget(const vector<string> &command_line){
    if(command_line.size() < 5)
            throw BadReqException(BAD_REQ);
    if(current_user == nullptr)
        throw PermisionException(PERMISSION_DENIED);
    map<string,string> args=Utility::commandArgs(command_line);
    if(args.find(AMOUNT)==args.end() || !all_of(args.find(AMOUNT)->second.begin(),args.find(AMOUNT)->second.end(), ::isdigit))
        throw BadReqException(BAD_REQ);
    int amount=stoi(args.find(AMOUNT)->second);
    if(amount<0)
        throw BadReqException(BAD_REQ);
    current_user->setWallet(amount);
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
    else if(action == SHOW_BUDGET)
        getBudget(command_line);
    else
        throw NotFoundException(NOT_FOUND);
}

void CommandHandle::getDistrict(const vector<string> &command_line){
    if(command_line.size() < 3)
            throw BadReqException(BAD_REQ);
    if(current_user == nullptr)
        throw PermisionException(PERMISSION_DENIED);

    map<string,string> args=Utility::commandArgs(command_line);

    if(args.find(DISTRICT) == args.end()){
        if(districts.empty())
            throw EmptyException(EMPTY);
        sort(districts.begin(), districts.end(), [](District* a, District* b) {
            return a->getName() < b->getName();
        });
        for(auto& district : districts) {
            district->printDistrict();
        }
    }else{
        string district = Utility::removeQuotation(args.find(DISTRICT)->second);
        auto dis_ptr =findDistrict(district);
        if(dis_ptr==nullptr)
            throw NotFoundException(NOT_FOUND);
        dis_ptr->printDistrict();
        return;
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

void CommandHandle::getBudget(const vector<string> &command_line){
    if(command_line.size() < 3)
            throw BadReqException(BAD_REQ);
    if(current_user == nullptr)
        throw PermisionException(PERMISSION_DENIED);
    cout<<current_user->getWallet()<<endl;
}

Restaurant* CommandHandle::findRestaurant(const string name){
    for(int i=0 ; i<restaurants.size() ;i++){
        if(restaurants[i]->getName()==name)
            return restaurants[i];
    }
    return nullptr;
}
void CommandHandle::getReserves(const vector<string> &command_line){
    if(command_line.size() < 3)
            throw BadReqException(BAD_REQ);
    if(current_user == nullptr)
        throw PermisionException(PERMISSION_DENIED);
    if(current_user->reserves.empty()){
        throw EmptyException(EMPTY);
    }
    map<string,string> args=Utility::commandArgs(command_line);

    if(args.find(RESTAURANT_NAME) != args.end()){
        if(args.find(RESERVE_ID) != args.end()){

            string restaurant =Utility::removeQuotation(args.find(RESTAURANT_NAME)->second);
            int reserve_id=stoi(Utility::removeQuotation(args.find(RESERVE_ID)->second));
            auto restaurant_ptr = findRestaurant(restaurant);

            if(restaurant_ptr==nullptr)
                throw NotFoundException(NOT_FOUND);
            else if(restaurant_ptr->hasReserve(reserve_id) && !current_user->hasReserve(restaurant,reserve_id))
                throw PermisionException(PERMISSION_DENIED);

            for(auto &it:current_user->reserves){
                if(current_user->hasReserve(restaurant,reserve_id)){
                    cout << it->reserve_id <<": " << it->restaurant << " "<< it->table_num << " " <<it->start_time <<"-"<<it->end_time;
                    for(auto &order : it->orders){
                        cout <<" "<<order.first<<"("<<order.second<<")";
                    }
                    cout <<endl;
                    return;
                }
            }
        }else{
            for(auto it : current_user->reserves){
                if(it->restaurant==Utility::removeQuotation(args.find(RESTAURANT_NAME)->second)){
                     cout << it->reserve_id <<": " << it->restaurant << " "<< it->table_num << " " <<it->start_time <<"-"<<it->end_time;
                    for(auto &order : it->orders){
                        cout <<" "<<order.first<<"("<<order.second<<")";
                    }
                    cout <<endl;
                }
            }
        }
    }else{
       if(args.find(RESERVE_ID) != args.end()){
        throw BadReqException(BAD_REQ);
       }
        for(auto &res : current_user->reserves){
            cout << res->reserve_id <<": " << res->restaurant << " "<< res->table_num << " " <<res->start_time <<"-"<<res->end_time;
            for(auto &order : res->orders){
                cout <<" "<<order.first<<"("<<order.second<<")";
            }
            cout <<endl;
        }
    }
}

District* CommandHandle::findDistrict(const string name){
    for(int i=0 ; i<districts.size() ;i++){
        if(districts[i]->getName()==name)
            return districts[i];
    }
    return nullptr;
}

void CommandHandle::deleteCommand(const vector<string> &command_line){
    string action=command_line[1];
    if(action==RESERVE)
        deleteReserve(command_line);
    else
        throw NotFoundException(NOT_FOUND);
}
void CommandHandle::deleteReserve(const vector<string> &command_line ){
    if(command_line.size() < 7)
            throw BadReqException(BAD_REQ);
    if(current_user == nullptr)
        throw PermisionException(PERMISSION_DENIED);
    map<string,string> args=Utility::commandArgs(command_line);

    if(args.find(RESTAURANT_NAME) == args.end() || args.find(RESERVE_ID) == args.end())
        throw BadReqException(BAD_REQ);

    string restaurant = Utility::removeQuotation(args.find(RESTAURANT_NAME)->second);
    int reserve_id = stoi(Utility::removeQuotation(args.find(RESERVE_ID)->second));

    auto restaurant_ptr = findRestaurant(restaurant);

    if(restaurant_ptr==nullptr || !restaurant_ptr->hasReserve(reserve_id))
        throw NotFoundException(NOT_FOUND);
    else if(!current_user->hasReserve(restaurant,reserve_id))
        throw PermisionException(PERMISSION_DENIED);

    for(int i=0;i<current_user->reserves.size();i++){
        if(current_user->reserves[i]->reserve_id==reserve_id){
            delete current_user->reserves[i];
            current_user->reserves.erase(current_user->reserves.begin()+i);
        }
    }
    for(auto it=restaurant_ptr->reservations.begin();it != restaurant_ptr->reservations.end();it++){
        for(int i=0;i<it->second.size();i++){
            if(it->second[i]->reserve_id==reserve_id){
                it->second.erase(i+it->second.begin());
                OK();
                return;
            }
        }
    }
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
        OK();
        return;
    }else
        throw BadReqException(BAD_REQ);
}