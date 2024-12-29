#ifndef DISTRICT_H
#define DISTRICT_H

#include "global.hpp"

class District{
public:
    District(string name_ ,vector<string> neighbours);
    void printDistrict();
    string getName();

private:

string name;
vector<string> neighbours;
vector<Restaurant*> dis_restaurants;

};

#endif