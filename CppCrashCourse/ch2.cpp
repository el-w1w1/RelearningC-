#include <iostream>
#include <cstddef>
#include <bitset> 

using namespace std; 

template <typename T> 
T add(T x, T y, T z) {
    return x + y + z; 
}

enum class Race {
    Aiden,
    Ross,
    Rachel
};

class food {

    int y; 

    public: 
    int balls; 

    int coolnums; 
    string yktv;
    food() {
        balls = 444; 
        printf("eated"); 
    }

    ~food() {
        balls = 0; 
        printf("kiilleded"); 
    }
};

enum class Operation {
    Addition,
    Subtraction,
    Multiplication,
    Division
};

struct Calculator {
    
    Calculator(Operation o) {
        op = o; 
    }

    int calculate(int a, int b) {
        if(op == Operation::Addition) {
            return a + b; 
        } else if (op == Operation::Multiplication) {
            return a * b;   
        } else if (op == Operation::Subtraction) {
            return a - b; 
        } else if (op == Operation::Division) {
            return a / b; 
        }
    }

    private:
    Operation op; 
};

void test() {
    //std::byte b{42}; 
    Race r = Race::Ross; 
    Operation op = Operation::Subtraction; 
    Calculator calc = Calculator(op);
    cout << calc.calculate(7,8); 
}

int main() {
    test(); 
    food f; 
    
    printf("cools\n"); 
    // auto val = add(1.f,2.f,3.f);
    // printf("%d", val);
} 