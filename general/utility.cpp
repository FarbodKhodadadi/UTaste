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
map<string , string> Utility::commandArgs(const vector<string>& command){
    map<string,string> result;

    for(int i=0 ;i <command.size() ;i++){
        if(command[i]==USERNAME || command[i]==PASSWORD || command[i]==RESTAURANT_NAME 
        || command[i]==FOODS || command[i]==FOOD_NAME || command[i]==START_TIME
        || command[i]==END_TIME  || command[i]==RESERVE_ID || command[i]==TABLE_ID){
            if(i+1 >=command.size()){
                throw BadReqException(BAD_REQ);
            }
            result[command[i]]=command[i+1];
        }

    }
    return result;
}

string Utility::removeQuotation(const string& input){
    if (input.size() >= 2 && input.front() == '"' && input.back() == '"') {
        return input.substr(1, input.size() - 2);
    }
    return input;
}