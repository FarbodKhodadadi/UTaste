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
Restaurant* CsvData::findRestaurant(string name,vector<Restaurant*> restaurants){
    for(int i=0 ; i<restaurants.size() ;i++){
        if(restaurants[i]->getName()==name)
            return restaurants[i];
    }
    return nullptr;
}
TotalPriceDiscount* CsvData::handleTotalPriceDis(const string restaurant,const string input){
    vector<string> args =Utility::split(input ,SEMICOLON_DELIMITER);
    string type=args[0];
    if(type==NONE){
        return new TotalPriceDiscount(restaurant,type,0,0);
    }
    int minimum=stoi(args[1]);
    int value=stoi(args[2]);
    
    return new TotalPriceDiscount(restaurant,type,minimum,value);

}
FirstOrderDiscount* CsvData::handleFirstOrderDis(const string restaurant,const string input){
    vector<string> args =Utility::split(input ,SEMICOLON_DELIMITER);
    string type=args[0];
    if(type==NONE){
        return new FirstOrderDiscount(restaurant,type,0);
    }
    int value=stoi(args[1]);
    
    return new FirstOrderDiscount(restaurant,type,value);

}
map<string,FoodDiscount*> CsvData::handleFoodDiscount(const string restaurant, const string input){

    vector<string> foods =Utility::split(input ,FOOD_DISCOUNT_DELIMITER);
    map<string,FoodDiscount*> result;
    for(auto &food : foods){
        vector<string> args =Utility::split(food ,SEMICOLON_DELIMITER);
        string type =args[0];
        vector<string> food_discount =Utility::split(args[1],PRICE_DELIMITER);
        string food_name=food_discount[0];
        int value=stoi(food_discount[1]);
        if(type==NONE){
            result[food_name]=new FoodDiscount(restaurant,food,type,0);
        }
        result[food_name]=new FoodDiscount(restaurant,food,type,value);
    }
    return result;
    
}
void CsvData::loadDiscounts(const char *discounts_path, vector<Restaurant *> restaurants)
{
    Restaurant* res_ptr=nullptr;
    ifstream file(discounts_path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file3 " << "\n";
    }
        string input;
        getline(file,input);

        while(getline(file,input)){
            vector<string> token = Utility::split(input , DELIMITER);
            string restaurant =token[0];
            res_ptr=findRestaurant(restaurant,restaurants);
            res_ptr->totalprice_ptr=handleTotalPriceDis(restaurant,token[1]);
            res_ptr->firstorder_ptr=handleFirstOrderDis(restaurant,token[2]);
            res_ptr->food_discount_ptr=handleFoodDiscount(restaurant,token[3]);
            
            res_ptr=nullptr;
        }
        file.close();
        return;
}
