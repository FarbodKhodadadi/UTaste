#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <fstream> 
#include <algorithm>

#include "../exeption/generalException.hpp"

using namespace std;

const char DELIMITER =',';
const char MENU_DELIMITER=';';
const char PRICE_DELIMITER=':';
const char NEIGHBOUR_DELIMITER=';';
const char SEMICOLON_DELIMITER=';';
const char FOOD_DISCOUNT_DELIMITER='|';

const string OK="OK";
const string GET="GET";
const string PUT="PUT";
const string DELETE="DELETE";
const string POST="POST";

const string BAD_REQ="Bad Request";
const string NOT_FOUND="Not Found";
const string PERMISSION_DENIED="Permission Denied";
const string EMPTY="Empty";

const string SIGNUP="signup";
const string LOGIN="login";
const string LOGOUT="logout";   
const string DISTRICT_COMM="districts";
const string RESTAURANT="restaurants";
const string RESTAURANTS_DETAILS="restaurant_detail";
const string RESERVES="reserves";
const string RESERVE="reserve";
const string MY_DISTRICT="my_district";
const string INCREASE_BUDGET ="increase_budget";
const string SHOW_BUDGET="show_budget";


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
const string AMOUNT="amount";

const string NONE="none";

#endif