#include "discount.hpp"

Discount::Discount(){}

Discount::Discount(string type_, int value_, string restaurant_) : type(type_), value(value_), restaurant(restaurant_) {}

string Discount::getName(){
    return restaurant;
}
