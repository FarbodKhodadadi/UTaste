#ifndef USER_H
#define USER_H
#include <string>
#include "districts.hpp"
#include "reserve.hpp"
using namespace std;

class User{
public:
    User();
    User(string name ,string pass ,bool loged_in);
    string getUsername();
    string getPassword();
    bool loged_in = false;
    District* user_district;
    vector<Reservation*> reserves;
    bool checkUserReserve(int start,int end);
private:

string username;
string password;

};

#endif