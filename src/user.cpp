#include "user.hpp"

User::User(string name,string pass,bool loged_in_):username(name),password(pass),loged_in(loged_in_){}
string User::getUsername(){return username;}