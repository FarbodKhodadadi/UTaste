#include <string>
using namespace std;

class User{
public:
    User(string name ,string pass ,bool loged_in);
    string getUsername();
private:

string username;
string password;
bool loged_in = false;

};