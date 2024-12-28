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
    User* current_user =nullptr;
    void putCommand(const vector<string>& command_line);
    void signup(const vector<string>& command_line);
    void login(const vector<string>& command_line);
    void logout(const vector<string>& command_line);
    User* findUser(const string username);
    void OK();
    void deleteCommand(const vector<string>& command_line);
    void getCommand(const vector<string>& command_line);
    void getDistrict(const vector<string>& command_line);
    void getRestaurant(const vector<string>& command_line);
    void getRestaurantDetails(const vector<string>& command_line);
    void getReserves(const vector<string>& command_line);
    void postCommand(const vector<string>& command_line);
};