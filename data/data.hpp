#include "../src/global.hpp"
#include "../general/utility.hpp"
#include "../src/restaurant.hpp"
#include "../src/districts.hpp"

class CsvData{
public:
    CsvData(string rest, string dis);
    vector<Restaurant*> loadRestaurants();
    vector<District*> loadDistricts();
private:
    string restaurant_path;
    string district_path;
};