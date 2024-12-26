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
