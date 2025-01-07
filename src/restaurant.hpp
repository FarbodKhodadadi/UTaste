#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "global.hpp"
#include "reserve.hpp"
#include "../exeption/generalException.hpp"
#include "../discount/generaldiscount.hpp"


class Restaurant{
public:
    Restaurant(string name_,string district_ ,map<string,int> menu_ ,int start_time_ ,int close_time_,int num_of_tables_);
    void printRestaurant();
    bool checkReserve(int table,int start,int end);
    bool checkMenu(map<string,int> order);
    bool checkTable(int table);
    bool checkWorkingTime(int start,int end);
    string getDistrict();
    map<string,int> handlePrice(map<string,int> order);
    bool hasReserve(int res_id);
    string getName();
    int last_reserve_id=0;
    map<int,vector<Reservation*>> reservations;
    TotalPriceDiscount* totalprice_ptr;
    FirstOrderDiscount* firstorder_ptr;
    map<string,FoodDiscount*> food_discount_ptr;
    map<string,int> getMenu();
private:
    vector<int> tables;
    string name;
    int num_of_tables;
    int start_time;
    int close_time;
    map<string,int>  menu;
    string distirct;
};

#endif