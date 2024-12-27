#include "../src/global.hpp"

class Utility{
public:
    static vector<string> split(const string& input , char delimiter);
    static map<string,int> menuHandle(const string &input ,char menu_delimiter,char price_delimiter);
    static vector<string> neighbourHandle(const string &input,char neighbour_delimiter);
private:

};