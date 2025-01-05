#ifndef FOODORDER_H
#define FOODORDER_H
#include "discount.hpp"
class FoodDiscount : public Discount{
public:
    FoodDiscount():Discount(){};
    FoodDiscount(string restaurant_,string food_,string type_,int value_):Discount(type_,value_,restaurant_),food(food_){};
private:
    string food;
};

#endif