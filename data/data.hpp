#include "../src/global.hpp"

class CsvData{
public:
    vector<Restaurant*> loadRestaurants(const string &restaurant_path);
    vector<Distirict*> loadDistricts(const string &districs_path);

};