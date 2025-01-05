#ifndef DISCOUNT_H
#define DISCOUNT_H

#include "../src/global.hpp"

class Discount{
public:
    Discount();
    Discount(string type_,int value_,string restaurant_);
private:
string getName();

string restaurant;
string type = NONE;
int value = 0;

};


#endif