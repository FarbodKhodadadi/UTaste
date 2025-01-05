#ifndef FIRSTORDER_H
#define FIRSTORDER_H
#include "discount.hpp"
class FirstOrderDiscount : public Discount{
public:
    FirstOrderDiscount():Discount(){};
    FirstOrderDiscount(string restaurant_,string type_,int value_):Discount(type_,value_,restaurant_){};
};

#endif