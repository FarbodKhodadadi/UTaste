#include "reserve.hpp"

Reservation::Reservation(){}

Reservation::Reservation(int reserve_id_, int start, int end, string restaurant_, int table_num_) :
                        reserve_id(reserve_id_), start_time(start), end_time(end),
                        restaurant(restaurant_), table_num(table_num_) {
                            orders={};
                            order_price={};
                        }

Reservation::Reservation(int reserve_id_, int start, int end, string restaurant_, map<string, int> orders_, int table_num_,map<string,int> order_price_) :
                        reserve_id(reserve_id_),start_time(start), end_time(end),
                        restaurant(restaurant_), orders(orders_), table_num(table_num_),order_price(order_price_){}

void Reservation::printReserve(){
    cout << "Reserve ID: " << reserve_id <<endl;
    cout << "Table " << table_num << " for " << start_time <<" to "<< end_time << " in " << restaurant <<endl;
    cout << "Price:" << calPrice() <<endl;
}

int Reservation::calPrice(){
    int total=0;
    for(auto &food:orders){
        auto price= order_price.find(food.first)->second;
        total += price * (food.second);
    }
    return total;
}
