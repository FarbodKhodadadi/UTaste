#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "global.hpp"
#include "reserve.hpp"
#include "../exeption/generalException.hpp"
using namespace std;

class Restaurant{
public:
    Restaurant(string name_,string district_ ,map<string,int> menu_ ,int start_time_ ,int close_time_,int num_of_tables_);
    void printRestaurant();
    bool checkReserve(int table,int start,int end);
    bool checkMenu(map<string,int> order);
    bool checkTable(int table);
    bool checkWorkingTime(int start,int end);
    string getName();
    int last_reserve_id=0;
    vector<Reservation*> reservations;
private:

string name;
int num_of_tables;
int start_time;
int close_time;
map<string,int>  menu;
string distirct;




};

#endif