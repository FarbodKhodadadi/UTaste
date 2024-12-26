#include <vector>
#include <string>
#include <map>
using namespace std;

class Restaurant{
public:
    Restaurant(int num_of_tables_ ,int start_time_ ,int close_time_,
            string district_ ,map<string,int> menu_ ,string name_);



private:

string name;
int num_of_tables;
int start_time;
int close_time;
map<string,int>  menu;
string distirct;

vector< vector<int> > reservations;

};