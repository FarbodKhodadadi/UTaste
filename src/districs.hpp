#include "global.hpp"

class District{
public:
    District(string name_ ,vector<string> neighbours);
    void printDistrict();
    string getName();

private:

string name;
vector<string> neighbours;


};