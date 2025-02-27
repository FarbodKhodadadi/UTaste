#include "utility.hpp"

vector<string> Utility::split(const string& input, char delimiter) {
    vector<string> result;
    string token;
    bool insideQuotes = false;
    stringstream s;

    for (char ch : input) {
        if (ch == '"') {
            insideQuotes = !insideQuotes;
            s << ch; // Keep the quotation marks
        } else if (ch == delimiter && !insideQuotes) {
            result.push_back(s.str());
            s.str("");
            s.clear();
        } else {
            s << ch;
        }
    }
    result.push_back(s.str());
    return result;
}
map<string,int> Utility::orderHandle(const string &input){
    auto temp=split(input,DELIMITER);
    map<string, int> foodCount;

    for (const auto& food : temp) {
        foodCount[food]++;
    }
    return foodCount;
}
map<string ,int> Utility::menuHandle(const string& input ,char menu_delimiter ,char price_delimiter){
    map<string,int> result;
    auto items = split(input ,menu_delimiter);
    for(int i=0;i<items.size();i++){
        auto food_price = split(items[i] ,price_delimiter);
        result[food_price[0]]=stoi(food_price[1]);
    }
    return result;
}

vector<string> Utility::neighbourHandle(const string &input , char neighbout_delimiter){
    vector<string> result;
    auto items=split(input,neighbout_delimiter);
    
    for(int i=0 ; i< items.size() ;i++){
        result.push_back(items[i]);
    }
    return result;
}
map<string , string> Utility::commandArgs(const vector<string>& command){
    map<string,string> result;

    for(int i=0 ;i <command.size() ;i++){
        if(command[i]==USERNAME || command[i]==PASSWORD || command[i]==RESTAURANT_NAME 
        || command[i]==FOODS || command[i]==FOOD_NAME || command[i]==START_TIME
        || command[i]==END_TIME  || command[i]==RESERVE_ID || command[i]==TABLE_ID || command[i]==DISTRICT || command[i]==AMOUNT){
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