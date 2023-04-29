#include "cc.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>

int test() {
	printf("die"); 
	return 3; 
}

/* Note: book recommends c-style way but included date-style chrono way for funsies */
struct Timer {

	/*constructors */
	Timer() : start_time{ std::time(0) }, name{ "" } {
		//chrono way to get time
		//auto start = std::chrono::system_clock::now(); 
		std::cout << "just started" << start_time << std::endl;

	}

	Timer(const char* n) : start_time { std::time(0) }, name{ n } {
		std::cout << name << " just started" << start_time << std::endl;
	}

	/*destructor*/
	~Timer() {
		std::time_t death_time = std::time(0);
		if (start_time != 0) {
			printf("death time for %s: %llu\nDifference: %llu", name, death_time, death_time - start_time);
		}
	}
	/*copy constructor*/
	Timer(const Timer& other) : start_time{ other.start_time }, name{ other.name } {

	}

	/*copy assignment*/
	Timer& operator=(const Timer& other) {
		if (this == &other) return *this;
		start_time = other.start_time;
		return *this;
	}


	/*move constructor -> point is to zero out other & put contents into this */
	Timer(Timer&& other) noexcept : start_time{ other.start_time }, name{ other.name } {
		other.start_time = 0; 
		other.name = "";
	}

	/*move assignment*/
	Timer& operator=(Timer&& other) noexcept {
		if (this == &other) return *this;
		start_time = other.start_time; 
		other.start_time = 0; 
	}


private: 
	std::time_t start_time; 
	const char* name; 
};

/*
int main() {
	Timer t{"blah"};
	std::this_thread::sleep_for(std::chrono::seconds(2)); 
	Timer f{t}; 
	
	f = std::move(t); 


	return 0; 
}*/