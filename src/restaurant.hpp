#include <vector>
#include <string>
#include <map>
using namespace std;

class Restaurant{
public:
    Restaurant();
    


private:

string name;
int num_of_tables;
int start_time;
int close_time;
map<string,int>  menu;
string distirct;

vector< vector<int> > reservations;

};