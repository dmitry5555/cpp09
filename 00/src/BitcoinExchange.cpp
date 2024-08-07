#include "BitcoinExchange.hpp"


bool checkRate(std::string& input) {
    std::istringstream str_stream(input);
	bool res = true;
    float float_value;

	res = true;
    if (str_stream >> float_value) {
		if (float_value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			res = false;
		}
		else if (1000 < float_value) {
			std::cout << "Error: too large a number." << std::endl;
			res = false;
		}

    } else {
        std::cout << "Error: bad input" << std::endl;
		res = false;
    }

	return res;
}

bool checkDate(std::string& input) {
	std::istringstream str_stream(input);

	int year, month, day;
	char dash;
	bool res;

	dash = '-';
	// std::cout << input << std::endl;
	res = true;
	// смотрим что год день и месяц валидны и что дата в формате год-месяц-день
	
	if (str_stream >> year >> dash >> month >> dash >> day) {
		
		if (year < 0 || month < 0 || month > 12 || day < 0 || day > 31) {
			std::cout << "Error: bad input => " << input << std::endl;
			res = false;
		}
		// проверяем день соответствует месяцу
		// Январь, март, май, июль, август, октябрь, декабрь: 31 день
		// Апрель, июнь, сентябрь, ноябрь: 30 дней 
		// Февраль: 28 дней в обычный год, 29 дней в високосный год
		else if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
			std::cout << "Error: bad input => " << input << std::endl;
			res = false;
		} else if (day > 29 && month == 2) {
			std::cout << "Error: bad input => " << input << std::endl;
			res = false;
		} else if (day > 28 && month == 2 && year % 4 != 0) {
			std::cout << "Error: bad input => " << input << std::endl;
			res = false;
		}
		
	}
	
	return res;
}

float calcRate(std::string& inputValue, std::string dbValue) {
	std::istringstream str_stream(inputValue);
	std::istringstream str_stream2(dbValue);
	float inpV;
	float dbV;
	str_stream >> inpV;
	str_stream2 >> dbV;
	return inpV * dbV;
}

