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
    bool hasReserve(const string rest_name ,int res_id );
    District* user_district;
    vector<Reservation*> reserves;
    bool checkUserReserve(int start,int end);
    void setWallet(const int amount);
    int getWallet();

private:
int wallet;
string username;
string password;

};

#endif