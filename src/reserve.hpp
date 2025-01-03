#ifndef RESERVE_H
#define RESERVE_H

#include "global.hpp"

class Reservation{
public:
    Reservation();
    Reservation(int reserve_id_, int start ,int end,string restaurant_ ,int table_num_);
    Reservation(int reserve_id_, int start ,int end,string restaurant_ ,map<string,int> orders_,int table_num_,map<string,int> order_price_);
    void printReserve();
    int reserve_id;
    int start_time;
    int end_time;
    int calPrice();
    string restaurant;
    map<string,int> orders;
    map<string,int> order_price;
    int table_num;
};


#endif