#include "global.hpp"
#include "main.hpp"

int main(int argc ,char* argv[]){

    string restaurants_path = argv[1];
    string districts_path = argv[2];
    
    vector<Restaurant*> restaurants= CsvData::loadRestaurants(restaurants_path);
    vector<District*> districts= CsvData::loadDistricts(districts_path);
    string input;
    
    while(getline(cin,input)){
    
    }



}