#include <vector>
#include <string>
#include <map>
using namespace std;

class Restaurant{
public:
    Restaurant(string name_,string district_ ,map<string,int> menu_ ,int start_time_ ,int close_time_,int num_of_tables_);



private:

string name;
int num_of_tables;
int start_time;
int close_time;
map<string,int>  menu;
string distirct;

vector< vector<int> > reservations;

};