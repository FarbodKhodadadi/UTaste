#include "restaurant.hpp"

Restaurant::Restaurant(string name_,string district_ ,map<string,int> menu_ ,int start_time_ ,int close_time_,int num_of_tables_ ):
            name(name_),distirct(district_) ,menu(menu_),start_time(start_time_) ,close_time(close_time_),
            num_of_tables(num_of_tables_ ){
            
            firstorder_ptr=new FirstOrderDiscount();
            totalprice_ptr = new TotalPriceDiscount();
            
            for(auto &dis:food_discount_ptr){
                dis.second=new FoodDiscount();
            }

            reservations={};
}

void Restaurant::printRestaurant(){
    cout << "Name:" << " " <<name <<endl;
    cout <<"District:" << " " <<distirct<<endl;
    cout <<"Time:" << " " << start_time<<"-"<<close_time<<endl;
    cout<<"Menu:";

    vector<pair<string, int>> sorted_menu(menu.begin(), menu.end());
    sort(sorted_menu.begin(), sorted_menu.end());
    for(auto it=sorted_menu.begin(); it!=sorted_menu.end(); it++){
        cout<<" "<<it->first<<"("<<it->second<<")";
        if (next(it) != sorted_menu.end()) {
            cout << ","; 
        }else
            cout << endl;
    }
    
    
    for(int i=1;i<num_of_tables+1;i++){
        sort(reservations[i].begin(), reservations[i].end(), [](Reservation* a, Reservation* b) { return a->start_time < b->start_time; });
        cout<<i<<":";
        for (auto &it :reservations[i]){
            cout << " (" << it->start_time << "-" << it->end_time << ")"; 
            if (next(find(reservations[i].begin(), reservations[i].end(), it)) != reservations[i].end())
                cout << ",";
        }
        cout << endl;
    }
    if(totalprice_ptr->type != NONE){
        cout << "Order Amount Discount: "<<totalprice_ptr->type <<", "<<totalprice_ptr->minimum << ", "<<totalprice_ptr->value<<endl;
    }
    if(!food_discount_ptr.empty()){
        cout <<"Item Specific Discount:";
        for(auto item :food_discount_ptr){
            if(item.second->type!=NONE){
                cout <<" "<<item.first<<"("<<item.second->type<<": "<<item.second->value<<")";
                if(next(find(food_discount_ptr.begin(),food_discount_ptr.end(),item))!=food_discount_ptr.end())
                    cout <<",";
            }
        }
        cout << endl;
    }
    if(firstorder_ptr->type!=NONE){
        cout <<"First Order Discount: "<<firstorder_ptr->type <<", "<<firstorder_ptr->value<<endl;
    }
}

bool Restaurant::checkReserve(int table, int start, int end){
    auto reserves=reservations[table];
    for(auto res:reserves){
        if(res->table_num == table){
            if(start < res->end_time && end > res->start_time){
                return true;
            }
        }
    }
    return false;
}

bool Restaurant::checkMenu(map<string, int> order)
{   
    for (const auto& item : order) {
        if (menu.find(item.first) == menu.end()) {
            return false;
        }
    }
    return true;
}

bool Restaurant::checkTable(int table){
    if(table<1 || table>num_of_tables){
        return false;
    }
    return true;
}
bool Restaurant::checkWorkingTime(int start, int end)
{
    if(start < start_time ||end > close_time)
        return false;
    return true;
}

string Restaurant::getDistrict(){
    return distirct;
}

map<string, int> Restaurant::handlePrice(map<string, int> order)
{
    map<string,int> result;
    for(auto &it:order){
        result[it.first] = menu.find(it.first)->second;
    }
    return result;
}
bool Restaurant::hasReserve(int res_id){
    for(auto it = reservations.begin();it!=reservations.end();it++){
        for(auto reserve : it->second){
            if(reserve->reserve_id==res_id){
                return true;
            }
        }
    }
    return false;
}
string Restaurant::getName() { return name; }

map<string, int> Restaurant::getMenu(){
    return menu;
}
