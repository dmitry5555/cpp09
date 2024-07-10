#include "BitcoinExchange.hpp"
#include <sstream>

// date = year - month - date  | value (exchange rate) = float from 0 to 1000


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file_name>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Can't open file: " << filename << "\n";
        return 1;
    }
    
    std::string line; 
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string date, valueStr;
        if (std::getline(iss, date, ',') && std::getline(iss, valueStr)) {
            // std::string value = valueStr;
			std::cout << valueStr << std::endl;
            // Теперь у вас есть дата в переменной date и курс обмена в переменной value
            // Здесь можно добавить обработку этих данных
        }
    }
    // Обработка файла

    file.close();
    return 0;

}
