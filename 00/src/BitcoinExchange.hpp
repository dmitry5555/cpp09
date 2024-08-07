#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

bool checkRate(std::string& input);
bool checkDate(std::string& input);
float calcRate(std::string& inputValue, std::string dbValue);

#endif