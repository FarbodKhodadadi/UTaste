#include "restaurant.hpp"

Restaurant::Restaurant(string name_,string district_ ,map<string,int> menu_ ,int start_time_ ,int close_time_,int num_of_tables_ ):
            name(name_),distirct(district_) ,menu(menu_),start_time(start_time_) ,close_time(close_time_),
            num_of_tables(num_of_tables_ ){

            for(int i=0;i<num_of_tables<i++;i++){
                reservations[i]={};
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
        }
    }
    for(int i=0;i<num_of_tables;i++){
        cout<<i<<":";
        for (auto it=reservations[i].begin();it!=reservations[i].end();it++){
            cout << " (" <<it->first<<"-"<<it->second<<")";
            if (next(it) != reservations[i].end()) {
                cout << ","; 
            }
        }
    }
}
string Restaurant::getName(){return name;}
