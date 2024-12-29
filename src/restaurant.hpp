#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>
using namespace std;

class Restaurant{
public:
    Restaurant(string name_,string district_ ,map<string,int> menu_ ,int start_time_ ,int close_time_,int num_of_tables_);
    void printRestaurant();
    string getName();

private:

string name;
int num_of_tables;
int start_time;
int close_time;
map<string,int>  menu;
string distirct;

map<int,vector<pair<int,int>>> reservations;

};

#endif