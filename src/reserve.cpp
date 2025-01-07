#include "reserve.hpp"
#include "restaurant.hpp"
#include "user.hpp"

Reservation::Reservation(){}

Reservation::Reservation(int reserve_id_, int start, int end, string restaurant_, int table_num_,User* current_user,Restaurant* res_ptr) :
                        reserve_id(reserve_id_), start_time(start), end_time(end),
                        restaurant(restaurant_), table_num(table_num_) {
                            orders={};
                            order_price={};
                            original_price=calPrice();
                            order_amount_discount=foodOrderDiscount(current_user, res_ptr);
                            first_order_discount=firstOrderDiscount(current_user, res_ptr);
                            total_item_discount=totalItemDiscount(current_user, res_ptr);
                            if(original_price-first_order_discount-order_amount_discount-total_item_discount >=0){
                                price_after_discount= original_price-first_order_discount-order_amount_discount-total_item_discount;
                            }else{
                                price_after_discount = 0;
                            }
                            


                        }

Reservation::Reservation(int reserve_id_, int start, int end, string restaurant_, map<string, int> orders_, int table_num_,map<string,int> order_price_,User* current_user,Restaurant* res_ptr) :
                        reserve_id(reserve_id_),start_time(start), end_time(end),
                        restaurant(restaurant_), orders(orders_), table_num(table_num_),order_price(order_price_){
                            original_price=calPrice();
                            order_amount_discount=foodOrderDiscount(current_user, res_ptr);
                            first_order_discount=firstOrderDiscount(current_user, res_ptr);
                            total_item_discount=totalItemDiscount(current_user, res_ptr);
                            if(original_price-first_order_discount-order_amount_discount-total_item_discount >=0){
                                price_after_discount= original_price-first_order_discount-order_amount_discount-total_item_discount;
                            }else{
                                price_after_discount = 0;
                            }
                        }

void Reservation::printReserve(User* current_user){
    if(current_user->getWallet() >= price_after_discount){
        cout << "Reserve ID: " << reserve_id <<endl;
        cout << "Table " << table_num << " for " << start_time <<" to "<< end_time << " in " << restaurant <<endl;
        cout << "Original Price: " << original_price <<endl;
        cout << "Order Amount Discount: "<< total_item_discount<<endl;
        cout << "Total ItemSpecific Discount: "<< order_amount_discount<<endl;
        cout << "First Order Discount: "<<first_order_discount<<endl;
        cout << "Total Price: "<<price_after_discount<<endl;
        current_user->pay(price_after_discount);
    }else{
        throw BadReqException(BAD_REQ);
    }
}

int Reservation::calPrice(){
    int total=0;
    for(auto &food:orders){
        auto price= order_price.find(food.first)->second;
        total += price * (food.second);
    }
    return total;
}

int Reservation::foodOrderDiscount(User* current_user,Restaurant* res_ptr){
    int result=0;
    for(auto &food:orders){
        auto price= order_price.find(food.first)->second;

        price = price * (food.second);
        if(res_ptr->food_discount_ptr.find(food.first) != res_ptr->food_discount_ptr.end()){
            if(res_ptr->food_discount_ptr.find(food.first)->second->type==PERCENTAGE){
                result += price*(res_ptr->food_discount_ptr.find(food.first)->second->value)/100;
            }
            else{
                result += res_ptr->food_discount_ptr.find(food.first)->second->value;
            }
        }
    }
    return result;
}

int Reservation::firstOrderDiscount(User* current_user,Restaurant* res_ptr){
    int result = 0;
    if(current_user->checkFirstOrder(restaurant)){
        int total_price = original_price - order_amount_discount ;
        if(res_ptr->firstorder_ptr->type == PERCENTAGE){
            result = total_price * (res_ptr->firstorder_ptr->value)/100;
        }else{
            result = res_ptr->firstorder_ptr->value;
        }
    }
    return result;
}

int Reservation::totalItemDiscount(User* current_user,Restaurant* res_ptr){
    int result = 0;
    int total_price = original_price - order_amount_discount - first_order_discount;
    if(res_ptr->totalprice_ptr->type != NONE){
        if (total_price >= res_ptr->totalprice_ptr->minimum){
            if(res_ptr->totalprice_ptr->type == PERCENTAGE){
                result= total_price * (res_ptr->totalprice_ptr->value) /100;
            }else{
                result = res_ptr->totalprice_ptr->value;
            }
        }
    }
    return result;
}
