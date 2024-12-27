#include "utility.hpp"

vector<string> Utility::split(const string& input , char delimiter){

    vector<string> result;
    stringstream s(input);
    string token;

    while(getline(s , token ,delimiter)){
        result.push_back(token);
    }
    return result;
}

map<string ,int> Utility::menuHandle(const string& input ,char menu_delimiter ,char price_delimiter){

    map<string,int> result;
    auto items = split(input ,menu_delimiter);
    for(auto &item: items){
        auto food_price = split(item ,price_delimiter);
        result[food_price[0]]=stoi(food_price[1]);
    }
    return result;
}

vector<string> Utility::neighbourHandle(const string &input , char neighbout_delimiter){
    vector<string> result;
    auto items=split(input,neighbout_delimiter);
    for(int i=0 ; i< items.size() ;i++){
        result[i]=items[i];
    }
    return result;
}