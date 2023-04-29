/*ch5 polymorphism */

#include "cc.h"
#include <iostream> 

struct Logger {
	virtual void log_transfer() = 0; 
};

struct ConsoleLogger : Logger {
	void log_transfer() override {
		printf("balls"); 
	}
};

//int main() {
//	ConsoleLogger l{}; 
//	l.log_transfer(); 
//}