#include "districts.hpp"
#include "global.hpp"

District ::District(string name_, vector<string> neighbours_): name(name_) , neighbours(neighbours_) {}
string District::getName(){return name;}
void District::printDistrict(){
    cout << name << ": ";
    for(auto dis : neighbours){
        cout << dis <<", ";
    }
    cout << endl;
}