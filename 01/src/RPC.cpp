// Your program must be able to handle operations with these tokens: "+ - / *"




// save to stack

// read from top, do actions 



#include <iostream>
#include <string>
#include <stack>
#include <sstream>

int main(int argc, char* argv[]) {

	
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::stack<int> our_stack;

	std::string args = argv[1];
	std::istringstream iss(args);
	std::string arg;
	int int_value;
	int temp_value;

	while (std::getline(iss, arg, ' ')) {
		std::cout << "Arg: " << arg << std::endl;
		// check if it is a decimal - put to stack
		if (arg == "+" || arg == "-" || arg == "*" || arg == "/") {
			std::cout << "Operator: " << arg << std::endl;
			temp_value = our_stack.top() * 100; // get top element val
			our_stack.pop(); // delete top elem
			our_stack.push(temp_value);
		}
		else {
			std::istringstream str_stream(arg);
			if (str_stream >> int_value) {
				std::cout << "Int: " << int_value << std::endl;
				our_stack.push(int_value);
			} else {
				std::cout << "Not an Int" << std::endl;
			}
		}
		std::cout << "res is: " << temp_value << std::endl;
	}

	return 0;
}
