#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <fstream> 

#include "../exeption/generalException.hpp"

using namespace std;

const char DELIMITER =',';
const char MENU_DELIMITER=';';
const char PRICE_DELIMITER=':';
const char NEIGHBOUR_DELIMITER=';';

const string GET="GET";
const string PUT="PUT";
const string DELETE="DELETE";
const string POST="POST";

const string BAD_REQ="Bad Request";
const string NOT_FOUND="Not Found";

const string SIGNUP="signup";
const string LOGIN="login";
const string LOGOUT="logout";

const string DISTRICT="district";
const string RESTAURANT_NAME="restaurant_name";
const string USERNAME="username";
const string PASSWORD="password";
const string TABLE_ID="table_id";
const string RESERVE_ID="reserve_id";
const string FOODS="foods";
const string FOOD_NAME="food_name";
const string START_TIME="start_time";
const string END_TIME="end_time";