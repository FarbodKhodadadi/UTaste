
#include "restaurant.hpp"

Restaurant::Restaurant(string name_,string district_ ,map<string,int> menu_ ,int start_time_ ,int close_time_,int num_of_tables_ ):
            num_of_tables(num_of_tables_ ),start_time(start_time_) ,close_time(close_time_),
            distirct(district_) , menu(menu_) , name(name_){

                for(int i=0 ;i < num_of_tables ;i++){
                    reservations[i]={};
                }
            };
