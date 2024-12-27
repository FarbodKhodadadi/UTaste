#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <fstream> 

#include "../general/utility.hpp"
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
