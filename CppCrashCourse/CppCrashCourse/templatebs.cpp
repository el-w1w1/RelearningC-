#include "cc.h"
#include <iostream> 
#include <unordered_map> 
#include <vector>

/* non-generic mode function */
int mode_generic(const int* values, size_t length) {
	//just count whichever num has the most?
	std::cout << length << std::endl; 
	// hashmap of all values (value : count) 
	std::unordered_map<int, int> umap;
	for (int i = 0; i < length; i++) {
		std::cout << values[i] << std::endl;
		if (umap.find(values[i]) != umap.end()) {
			umap[values[i]]++;
		}
		else {
			umap[values[i]] = 1;
		}
	}

	//find max 
	bool tie = false; 
	int mode = -1; 
	int max = -1; 
	for (const auto& n : umap) {
		if (n.second > max) {
			mode = n.first; 
			max = n.second; 
			tie = false; 
		}
		else if (n.second == max) {
			tie = true; 
			max = n.second;
		} 
	}

	if (tie) {
		return -1; 
	}
	else {
		return mode; 
	}
}

//should require T is an int
template<typename T>
concept Integer = std::is_same_v<T, int>;

//template<Integer T> requires std::is_same_v<T,int> //works but wants to declare Integer 
template<Integer T>
T mode(const T* values, size_t length) {

	//just count whichever num has the most?
	//std::cout << length << std::endl;
	// hashmap of all values (value : count) 
	std::unordered_map<T, int> umap;
	for (int i = 0; i < length; i++) {
		//std::cout << values[i] << std::endl;
		if (umap.find(values[i]) != umap.end()) {
			umap[values[i]]++;
		}
		else {
			umap[values[i]] = 1;
		}
	}

	//find max 
	bool tie = false;
	int mode = -1;
	int max = -1;
	for (const auto& n : umap) {
		if (n.second > max) {
			mode = n.first;
			max = n.second;
			tie = false;
		}
		else if (n.second == max) {
			tie = true;
			max = n.second;
		}
	}

	if (tie) {
		return -1;
	}
	else {
		return mode;
	}
}

struct Logger {
	virtual ~Logger() = default; 
		virtual void log_transfer(long from, long to, double amount) = 0; 
};

template<typename T> 
struct ConsoleLogger : Logger  {
	void log_transfer(T from, T to, double amount) override {
		printf("[cons] %ld -> %ld: %f\n", from, to, amount);
	}
};
struct FileLogger : Logger {
	void log_transfer(long from, long to, double amount) override {
		printf("[file] %ld,%ld,%f\n", from, to, amount);
	}
};

struct Account {
	Account(double balance) : balance{ balance } {}
	~Account() = default;
	double getBalance() {
		return balance;
	}


private:
	double balance;
};

template<typename Account> 
struct Bank {


	Bank(Logger* new_logger) {
		std::vector<Account> accounts{};
		logger = new_logger;
	}

	void set_logger(Logger* new_logger) {
		logger = new_logger;
	}
	void make_transfer(Account from, Account to, double amount) {
		if (logger) logger->log_transfer(from, to, amount);
	}

	void create_account(double balance) {
		//add account to accounts
		//set to starting balance 
		Account new_acc{ balance };
		accounts.push_back(new_acc); 
		
	}
private:
	std::vector<Account> accounts; 
	Logger* logger;
};



int main() {
	int test[] = { 1,2,4,4,5,6,7,7,7 }; 
	std::cout << mode(test, (sizeof(test)/sizeof(int))) << std::endl;
	double test2[] = { 1,2,4,4,5,6,7,7,7 };
	//std::cout << mode(test2, (sizeof(test2) / sizeof(double))) << std::endl; //doesn't work
	
	




	//ConsoleLogger b{}; 
	//Bank bank{&b};
	//bank.set_logger(&b);
	//bank.make_transfer(2, 2, 100); 
	return 0; 
}