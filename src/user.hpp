#ifndef USER_H
#define USER_H
#include <string>
#include "districts.hpp"
using namespace std;

class User{
public:
    User();
    User(string name ,string pass ,bool loged_in);
    string getUsername();
    string getPassword();
    bool loged_in = false;
    District* user_district;
private:

string username;
string password;
District* user_district;

};

#endif