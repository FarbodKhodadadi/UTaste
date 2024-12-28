#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User{
public:
    User();
    User(string name ,string pass ,bool loged_in);
    string getUsername();
    string getPassword();
    bool loged_in = false;
private:

string username;
string password;

};

#endif