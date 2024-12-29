#ifndef RESERVE_H
#define RESERVE_H

#include "global.hpp"
#include "restaurant.hpp"

class Reservation{
public:
    Reservation();
    Reservation(int reserve_id_, int start ,int end,string restaurant_ ,map<string,int> orders_,int table_num_);
    int reserve_id;
    int start_time;
    int end_time;
    string restaurant;
    map<string,int> orders;
    int table_num;
};


#endif