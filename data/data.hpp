#include "../src/global.hpp"
#include "../general/utility.hpp"
#include "../src/restaurant.hpp"
#include "../src/districts.hpp"
#include "../discount/generaldiscount.hpp"

class CsvData{
public:
    static vector<Restaurant*> loadRestaurants(const char* restaurants_path);
    static vector<District*> loadDistricts(const char* districts_path);
    static void loadDiscounts (const char* discounts_path,vector<Restaurant*> restaurants);
    static Restaurant* findRestaurant(string name,vector<Restaurant*> restaurants);
    static TotalPriceDiscount* handleTotalPriceDis(const string restaurant,const string input);
    static FirstOrderDiscount* handleFirstOrderDis(const string restaurant,const string input);
    static map<string,FoodDiscount*> handleFoodDiscount(const string restaurant ,const string input);
};