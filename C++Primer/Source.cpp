#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Sales_item.h"
#include <vector>
#include <regex>
using namespace std;

//method declarations
void print_sum();
void sales();
void file_stuff();
void read_file(const char* name);
void pointer(); 

void pointer2() {
	//change value of pointer *p1
	int num1 = 5; 
	int num2 = 10;
	const int f = num2; 
	num2 = 1000; 
	cout << f << endl; 
	

	//p1 now points to num1
	int* p1 = &num1; 
	std::cout << "p1 is: " << p1 << " and points to value: " << *p1 << std::endl;
	
	//p1 now poitns to num2
	p1 = &num2; 
	std::cout << "p1 is: " << p1 << " and points to value: " << *p1 << std::endl;

	//change value inside num2
	*p1 = 25;
	std::cout << "p1 is: " << p1 << " and points to value: " << *p1 << std::endl;

}



std::vector<int> sortNumsAscending(std::vector<int> arr) {
	//manually 
	cout << sizeof(arr) / sizeof(arr[0]) << endl;
	for (const auto &i: arr) {
		cout << i << endl;
	}
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	sort(arr.begin(), arr.end());

	for (const auto& i : arr) {
		cout << i << ", "; 
	}
	
	return arr; 
}

//returns number of syllables (with dashes)
int numberSyllables(std::string word) {
	const char del = '-';
	//loop through all letters and count the -
	int cnt = 1; 
	for (const auto& i : word) {
		if (i == '-') {
			cnt++;
		}
	}
	return cnt; 

	/*
		other solution:  return std::count(word.begin(),word.end(),'-') + 1;
	*/
}

//count words
int countWords(string str) {

	//split string by ' ' and return length of array (have to do manually? that sucks)
	//loop through and maintain new_str 
	string buf = ""; 
	vector<string> v; 
	for (const auto& i : str) {
		if (i == ' ') {
			v.push_back(buf);
			buf = "";
		}
		else {
			buf += i; 
		}
	}
	//add last word
	v.push_back(buf); 
	
	//print out vec v
	int cnt = 0;
	for (const auto& i : v) {
		cout << i << endl; 
		cnt++;
	}

	return cnt; 
}

//count words alt
int countWordsFast(string str) {
	return count(str.begin(), str.end(), ' ') + 1;
}

/*
	regex stuff: 
	void getAllWords() {
		string seq = "Some words. And... some punctuation.";
		regex rgx("\\w+");

		for( sregex_iterator it(seq.begin(), seq.end(), rgx), it_end; it != it_end; ++it )
			cout << (*it)[0] << "\n";
	}
*/

//mask stuff (e.g. *re* -> creed) 
//scrambled([”red”, “dee”, “cede”, “reed”, “creed”, “decree”], “*re**”) ➞ [“creed”]
using namespace std;
vector<string> scrambled(vector<string> words, string mask) {
	//loop through each word
	vector<string> final; 
	for (string s : words) {
		bool isValid = true; 
		for (int i = 0; i < mask.length(); i++) {
			//lengths must be same, characters must match up (unless its a *) 
			if (mask.length() != s.length() || (mask[i] != '*' && mask[i] != s[i])) {
				isValid = false; 
				break;
			}
		}
		if (isValid) {
			final.push_back(s);
			cout << s << endl;
		}
	}
	return final; 
}

int main() {
	std::cout << "Hello World" << std::endl;
	//pointer2(); 

	std::vector<int> test = { 2,5,-4,68,6 };
	//sortNumsAscending(test);
	//cout << numberSyllables("test-case-fiwe");
	cout << countWords("hello world how are you");
	cout << countWordsFast("test test test four");
	vector<string> words = {"red", "dee", "code", "creed", "ahjfoewjifwej"};
	scrambled(words, "*re**");
}


void pointer() {
	string food = "test";
	string* ptr = &food; 
	cout << food << endl; 
	cout << &food; 
	cout << *ptr << endl; 
	cout << ptr << endl; 
}

//read file and print shit out
void read_file(const char* name) {
	std::ifstream myfile;
	myfile.open(name);
	std::string myline;
	if (myfile.is_open()) {
		while (myfile) { // equivalent to myfile.good()
			std::getline(myfile, myline);
			std::cout << myline << '\n';
		}
	}
	else {
		std::cout << "Couldn't open file\n";
	}
}


//file input/out
void file_stuff() {
	// Create and open a text file
	ofstream MyFile("filename.txt");

	// Write to the file
	MyFile << "Files can be tricky, but it is fun enough!";

	// Close the file
	MyFile.close();
}

//reads unlimited inputs 
void print_sum() {
	int sum = 0, value = 0;
	// read until end-of-file (ctrl-z), calculating a running total of all values read
	while (std::cin >> value)
		sum += value; // equivalent to sum = sum + value
	std::cout << "Sum is: " << sum << std::endl; 

}

void sales() {
	Sales_item s; 
	s.num = 13; 
	s.name = "baby"; 
	s.name = "dfae";
	s.print_name();

	//new object
	toy* t = new toy();
	t->brand = "hfdoi";
	t->num = 3; 
	t->print_name(); 
	std::cout << t->brand; 

}