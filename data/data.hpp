#include "../src/global.hpp"
#include "../general/utility.hpp"
#include "../src/restaurant.hpp"
#include "../src/districts.hpp"

class CsvData{
public:
    static vector<Restaurant*> loadRestaurants(const char* restaurants_path);
    static vector<District*> loadDistricts(const char* districts_path);
};