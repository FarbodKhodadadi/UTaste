#include "data.hpp"

CsvData::CsvData(string rest ,string dis):restaurant_path(rest),district_path(dis){}

vector<Restaurant*> CsvData::loadRestaurants(){
    
    vector<Restaurant*> restaurants;
    ifstream file(restaurant_path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << "\n";
    }
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
    file.close();
    return restaurants;
}

vector<District*> CsvData::loadDistricts(){
    vector<District*> districts;
        ifstream file(district_path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << "\n";
    }
        string input;
        getline(file,input);

        while(getline(file,input)){
            vector<string> token = Utility::split(input , DELIMITER);
            string name =token[0];
            vector<string> neighbours = Utility::neighbourHandle(token[1],NEIGHBOUR_DELIMITER);
            districts.push_back(new District(name,neighbours));
        }
        file.close();
        return districts;
}
