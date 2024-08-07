#include <map> // Add this line to include the <map> header file
#include "BitcoinExchange.hpp"
 
// date = year - month - date  | value (exchange rate) = float from 0 to 1000

std::map<std::string, std::string> database;

int main(int argc, char **argv) {
	
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_name>\n";
        return 1;
    }

    std::string filename2 = "data.csv";
    std::ifstream file2(filename2);
    if (!file2.is_open()) {
        std::cerr << "Error: could not open file.";
        return 1;
    }
    
    std::string line2; 
	std::getline(file2, line2); 

    while (std::getline(file2, line2)) {
		std::istringstream iss(line2);
		std::string date, valueStr;
        if (std::getline(iss, date, ',') && std::getline(iss, valueStr)) {
			database[date] = valueStr;
        }
    }
    file2.close();
	// print for testing
    // std::map<std::string, std::string>::iterator it;
    // for (it = database.begin(); it != database.end(); it++) {
	// 	std::cout << it->first << " => " << it->second << std::endl;
	// }



	// read file to check
	std::string filename = argv[1];
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file.";
        return 1;
    }

    std::map<std::string, std::string>::iterator it;
    std::string line; 
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;

        std::getline(iss, date, '|');
		std::getline(iss, valueStr);
		
		if ( checkDate(date) && checkRate(valueStr) ) {
			it = database.lower_bound(date);
			if (it != database.begin()) {
				--it;
				std::cout << date << "=>" << valueStr << " = " << calcRate(valueStr, it->second) << std::endl;
			}
		}

    }

    file.close();
	
	return 0;

}
