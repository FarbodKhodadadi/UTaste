#include "user.hpp"

User::User(){};
User::User(string name,string pass,bool loged_in_):username(name),password(pass),loged_in(loged_in_){
    user_district=nullptr;
}
string User::getUsername(){return username;}
string User::getPassword(){return password;}