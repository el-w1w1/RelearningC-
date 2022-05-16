#include <iostream>
#include <fstream>
#include <string>
#include "Sales_item.h"
using namespace std;

//method declarations
void print_sum();
void sales();
void file_stuff();
void read_file(const char* name);

int main() {
	std::cout << "Hello World" << std::endl; 
	//print_sum();
	//sales();
	//file_stuff();
	read_file("filename.txt");
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
/** // read file
ifstream MyReadFile(name);
const char* contents;
MyReadFile >> contents;
// Use a while loop together with the getline() function to read the file line by line
while (std::getline(MyReadFile, myText)) {
	// Output the text from the file
	cout << myText;
}

MyReadFile.close(); 
**/

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