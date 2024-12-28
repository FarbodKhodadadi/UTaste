#include "global.hpp"
#include "restaurant.hpp"
#include "districs.hpp"
#include "user.hpp"
#include "../exeption/generalException.hpp"
#include "../general/utility.hpp"

class CommandHandle{
public:
    CommandHandle(vector<Restaurant*>& restaurants,vector<District*>& distiricts,vector<User*>& users);
    void commandProcess(const string& input);

private:
    vector<Restaurant*>& restaurants;
    vector<District*>& districts;
    vector<User*>& users;
    void deleteCommand(const vector<string>& command_line);
    void getCommand(const vector<string>& command_line);
    void postCommand(const vector<string>& command_line);
    void putCommand(const vector<string>& command_line);
    User* signup(const vector<string>& command_line);
    void login(const vector<string>& command_line);
    void logout(const vector<string>& command_line);
    void OK();
};