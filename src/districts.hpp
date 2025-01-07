#ifndef DISTRICT_H
#define DISTRICT_H

#include "global.hpp"

class District{
public:
    District(string name_ ,vector<string> neighbours);
    void printDistrict();
    string getName();
    
    vector<District*> neighbours_object;
    vector<string> neighbours;
private:
    string name;


};

#endif