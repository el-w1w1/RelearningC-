#include <iostream>
#include "Sales_item.h"

void Sales_item::print_name() {
	std::cout << "your name is: " << this->name << std::endl;
	secret_method();
}

int Sales_item::secret_method() {
	this->num = 25; 
	std::cout << "your new num is: " << this->num << std::endl; 
	return 2; 
}