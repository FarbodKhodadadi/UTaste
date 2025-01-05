#ifndef TOTALPRICEDIS_H
#define TOTALPRICEDIS_H
#include "discount.hpp"

class TotalPriceDiscount : public Discount{
public:
    TotalPriceDiscount():Discount(){};
    TotalPriceDiscount(string restaurant_,string type_,int minimum_ ,int value_):Discount(type_,value_,restaurant_) ,minimum(minimum_){};
private:
    int minimum;
};

#endif