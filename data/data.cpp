#include "data.hpp"


vector<Restaurant*> CsvData::loadRestaurants(const string &restaurant_path){
    
    vector<Restaurant*> restaurants;
    fstream file(restaurant_path);

    string input;
    getline(file,input);

    while(getline(file,input)){
        vector<string> token = Utility::split(input , DELIMITER);
        string name =token[0];
        string district =token[1];
        map<string ,int> menu =Utility::menuHandle(token[3],MENU_DELIMITER,PRICE_DELIMITER);
        int open_time =stoi(token[4]);
        int close_time=stoi(token[5]);
        int num_tables=stoi(token[6]);
        restaurants.push_back(new Restaurant(name ,district ,menu,open_time,close_time,num_tables));
    }
    return restaurants;
}

vector<District*> CsvData::loadDistricts(const string & district_path){
    vector<District*> districts;
        fstream file(district_path);

        string input;
        getline(file,input);

        while(getline(file,input)){
            vector<string> token = Utility::split(input , DELIMITER);
            string name =token[0];
            vector<string> neighbours = Utility::neighbourHandle(token[1],NEIGHBOUR_DELIMITER);
            districts.push_back(new District(name,neighbours));
        }
        return districts;
}
