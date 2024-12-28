#include "../src/global.hpp"
#include "../general/utility.hpp"
#include "../src/restaurant.hpp"
#include "../src/districs.hpp"

class CsvData{
public:
    static vector<Restaurant*> loadRestaurants(const string &restaurant_path);
    static vector<District*> loadDistricts(const string &districs_path);

};