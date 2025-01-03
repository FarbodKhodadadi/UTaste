#include "restaurant.hpp"

Restaurant::Restaurant(string name_,string district_ ,map<string,int> menu_ ,int start_time_ ,int close_time_,int num_of_tables_ ):
            name(name_),distirct(district_) ,menu(menu_),start_time(start_time_) ,close_time(close_time_),
            num_of_tables(num_of_tables_ ){
            
            for(int i=1;i<num_of_tables+1;i++){
                tables.push_back(i);
                reservations.push_back(new Reservation());
            }
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
        cout<<i<<":";
        for (auto &it :reservations){
            if(it->table_num==i){
                cout << " (" << it->start_time << "-" << it->end_time << ")";
                if (next(find(reservations.begin(), reservations.end(), it)) != reservations.end())
                    cout << ","; 
            }
           
        }
        cout << endl;
    }
}
bool Restaurant::checkReserve(int table, int start, int end){

    for(auto res:reservations){
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
        throw NotFoundException(NOT_FOUND);
    }
    return true;
}
bool Restaurant::checkWorkingTime(int start, int end)
{
    if(start < start_time ||end > close_time)
        return false;
    return true;
}
map<string, int> Restaurant::handlePrice(map<string, int> order){
    map<string,int> result;
    for(auto &it:order){
        result[it.first] = menu.find(it.first)->second;
    }
    return result;
}
string Restaurant::getName() { return name; }
