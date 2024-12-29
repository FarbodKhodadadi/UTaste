#include "reserve.hpp"

Reservation::Reservation(){}

Reservation::Reservation(int reserve_id_, int start, int end, string restaurant_, map<string, int> orders_, int table_num_) :
                        reserve_id(reserve_id_),start_time(start), end_time(end),
                        restaurant(restaurant_), orders(orders_), table_num(table_num_){}