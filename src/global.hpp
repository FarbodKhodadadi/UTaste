#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <fstream> 

#include "restaurant.hpp"
#include "user.hpp"
#include "districs.hpp"

#include "../general/utility.hpp"

#include "../exeption/exception.hpp"
#include "../exeption/badrequest_exception.hpp"
#include "../exeption/notfound_exception.hpp"
#include "../exeption/permission_exception.hpp"
#include "../exeption/empty_exception.hpp"

using namespace std;

const char DELIMITER =',';
const char MENU_DELIMITER=';';
const char PRICE_DELIMITER=':';
const char NEIGHBOUR_DELIMITER=';';

const string GET="GET";
const string PUT="PUT";
const string DELETE="DELETE";
const string POST="POST";
