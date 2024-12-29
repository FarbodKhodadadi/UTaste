#include "data.hpp"


vector<Restaurant*> CsvData::loadRestaurants(const char* restaurant_path){
    
    vector<Restaurant*> restaurants;
    ifstream file(restaurant_path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file1 " << "\n";
    }
    string input;
    getline(file,input);
    while(getline(file,input)){
        vector<string> token = Utility::split(input , DELIMITER);
        string name =token[0];
        string district =token[1];
        map<string ,int> menu =Utility::menuHandle(token[2],MENU_DELIMITER,PRICE_DELIMITER);
        int open_time =stoi(token[3]);
        int close_time=stoi(token[4]);
        int num_tables=stoi(token[5]);
        restaurants.push_back(new Restaurant(name ,district ,menu,open_time,close_time,num_tables));
    }
    file.close();
    return restaurants;
}

vector<District*> CsvData::loadDistricts(const char* district_path){
    vector<District*> districts;
    ifstream file(district_path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file2 " << "\n";
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
