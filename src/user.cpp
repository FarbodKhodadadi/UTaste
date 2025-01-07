#include "user.hpp"

User::User(){};
User::User(string name,string pass,bool loged_in_):username(name),password(pass),loged_in(loged_in_){
    user_district=nullptr;
    wallet=0;
    for(auto &i:reserves){
        i=nullptr;
    }
}
string User::getUsername(){return username;}
string User::getPassword(){return password;}

bool User::hasReserve(const string rest_name, int res_id){
    for(auto &it: reserves){
        if(it->restaurant == rest_name && it->reserve_id == res_id)
            return true;
    }
    return false;
}

bool User::checkUserReserve(int start, int end){
    for (const auto& reservation : reserves) {
        if (max(start, reservation->start_time) < min(end, reservation->end_time)) {
            return false; 
        }
    }
    return true;

}

void User::setWallet(const int amount){
    wallet=wallet+amount;
}

int User::getWallet(){
    return wallet;
}
