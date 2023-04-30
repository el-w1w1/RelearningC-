#include <stdio.h> 
#include <iostream> 
#include <string.h> 
#include <math.h> 

using namespace std; 

/* random shit */
void luhn_myway(int digit) {
    // double then sum the individual digits 
    int sum = digit * 2; 
    if (sum >= 10) {
        int diff = sum % 10; 
        sum = diff + ((sum - diff) / 10); 
    }

    cout << "my sum: " << sum << endl; 

}

/* Takes digit of arb length and sums the indiv digits (assume no convert into string bs)*/
void sum_indiv_digits(int num) {
    //determine num of digits in num
    int ag = 10; 
    int sum = 0; 
    int chopped = num; 
    int diff; 

    if(num <= 10 && num > 0) {
        cout << "sum is " << num << endl; 
        return; 
    }

    while(ag <= num * 10) {
        diff = chopped % ag; 
        chopped -= diff; 
        sum += diff / (ag/10); 
        //increment to next digit
        ag *= 10; 
    }

    cout << "sum of " << num << " is " << sum << endl; 
}


void luhn_check_sum(int digit) {
    int d = digit * 2;
    int sum; 
    if (d >= 10) sum = 1 + d % 10; 
    else sum = d; 
    cout << "Sum is: " << sum << endl; 
}



void decode_char(char f) {

}
/* Decode the message */
void decode_message(char* msg) {

}

/* Exercise 2_3 for printing X */
void two_3(int height) {
    //define static vars
    

    char hash = '#'; 
    char space = ' '; 
    int midpt = (height/2); 
    int l_size = (midpt * 4) -2; 
    //print top part 
    // loop from 0 to l_size 
    for (int i = 0; i < midpt; i++) {
        int pos = 0; 
        while (pos < l_size) {
            if (pos == i || pos == l_size-1-i*2){
                for(int j = 0; j < i+1; j++)
                    cout << hash; 
                pos += i+1;
            } else {
                cout << space;
                pos++;  
            }
        }
        cout << endl; 
    }

    //bottom half 
    for (int i = midpt-1; i > -1; i--) {
        int pos = 0; 
        while (pos < l_size) {
            if (pos == i || pos == l_size-1-i*2){
                for(int j = 0; j < i+1; j++)
                    cout << hash; 
                pos += i+1;
            } else {
                cout << space;
                pos++;  
            }
        }
        cout << endl; 
    }
}

string change_base(char* str, int cur_base, int des_base) {
    char* start = str; 
    //calculate base 10 
    int total_val = 0; 
    int idx = 0; 
    for(char num = *start; num; num=*++start) {
        int raw_val = int(num); 
        if(raw_val >= 48 && raw_val <= 57) {
            total_val += (raw_val-48) * pow(cur_base, idx); 
        } else if (raw_val >= 97 && raw_val <= 122) {
            total_val += ((raw_val-97) + 10) * pow(cur_base, idx); 
        } else {
            throw("invalid char %s", num); 
        }
        idx++; 
    }

    //cout << total_val; 

    // //calculate base-x 
    // //find highest place 
    // int msp = 1; //most significant place 
    // while (total_val / msp > pow(des_base, msp)) {
    //     msp++; 
    // }

    // cout << msp; 

    int cur_val = 0; 
    int idx2 = 1;
    int val; 
    string final = ""; 
    while(true) {
        int temp = pow(des_base,idx2);
        val = (total_val % temp)-cur_val ; 
        if(val == 0) 
            break; 
        
        cur_val += val; 

        //store appropriate char for val
        int val2 = val / pow(des_base,idx2-1); 
        if(val2 < 10) {
            final = (char)(val2+48) + final;
        } else {
            final = (char)(val2+87) + final;
        }
        idx2++; 
    }

    return final; 
}

int main() {
    // int test[5] = {1378833,5412,7,942,-41}; 
    // for(int i = 0; i < 5; i++) {
    //     sum_indiv_digits(test[i]); 
    // }

    //two_3(2); 
    // char arr[80]; 
    // cout << "tell me a joke " <<endl; 
    // cin.getline(arr, 80); 

    // cout << &arr; 
    char* f = "ffff";
    cout << change_base(f, 16, 8);
    return 0; 
}