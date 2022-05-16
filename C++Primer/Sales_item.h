#pragma once

//base class
class Sales_item {
	public: 
		int num;
		const char* name; 
		void print_name();
		Sales_item() {
			this->num = 3; 
			this->name = "fjiow"; 
		}
	private: 
		int secret_method(); 
};

//derived class inherits Sales_item
//can do multiple classe: class MyChildClass: public MyClass, public MyOtherClass {
class toy : public Sales_item {
	public: 
		const char* brand; 
};