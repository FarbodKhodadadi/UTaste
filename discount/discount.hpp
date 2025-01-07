#ifndef DISCOUNT_H
#define DISCOUNT_H

#include "../src/global.hpp"

class Discount{
public:
    Discount();
    Discount(string type_,int value_,string restaurant_);
    string type = NONE;
    string getName();
    int value = 0;
private:
    string restaurant;
};


#endif