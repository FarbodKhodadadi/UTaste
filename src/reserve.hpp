#ifndef RESERVE_H
#define RESERVE_H

#include "global.hpp"
class User;
class Restaurant; 

class Reservation{
public:
    Reservation();
    Reservation(int reserve_id_, int start ,int end,string restaurant_ ,int table_num_,User* current_user,Restaurant* res_ptr);
    Reservation(int reserve_id_, int start ,int end,string restaurant_ ,map<string,int> orders_,int table_num_,map<string,int> order_price_,User* current_user,Restaurant* res_ptr);
    void printReserve(User* current_user);
    int calPrice();
    int foodOrderDiscount(User* current_user,Restaurant* res_ptr);
    int firstOrderDiscount(User* current_user,Restaurant* res_ptr);
    int totalItemDiscount(User* current_user,Restaurant* res_ptr);

    string restaurant;
    map<string,int> orders;
    map<string,int> order_price;
    int reserve_id;
    int start_time;
    int end_time;
    int table_num;
    int original_price;
    int order_amount_discount;
    int first_order_discount;
    int total_item_discount;
    int price_after_discount;
    

};


#endif