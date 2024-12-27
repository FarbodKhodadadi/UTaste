#include "global.hpp"

class CommandHandle{
public:
    CommandHandle(vector<Restaurant*>& restaurants,vector<Distirict*>& distiricts);
    void commandHandle(const string& input);

private:
    vector<Restaurant*>& restaurants;
    vector<Distirict*>& distiricts;
    void deleteCommand(const vector<string>& command_line);
    void getCommand(const vector<string>& command_line);
    void postCommand(const vector<string>& command_line);
    void putCommand(const vector<string>& command_line);
};