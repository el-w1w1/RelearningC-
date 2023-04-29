// CppCrashCourse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <cstdio>
#include <cstddef>
#include <bitset> 
#include "cc.h"; 

namespace bigboys {
    void dataTypes() {
        unsigned int a = 3669732608;
        printf("Yabba %x!\n", a);
        unsigned int b = 69;
        printf("There are %u,%o leaves here.\n", b, b);
    }

    void testBuff() {
        int arr[] = { 1,4,5,76 };
        printf("size: %ld", sizeof(arr) / sizeof(int));

        printf("%ld", arr[10]);
        std::byte b{ 42 };
    }

    struct Balls {
        std::string dick{ "very impressive" };
        int size = 3;
    };

    void shrinker(Balls& big) {
        big.size = 1;
    }

    void refs() {
        Balls big;
        Balls& ref_to_balls = big;

        shrinker(ref_to_balls);

        printf("size of balls: %d", big.size);
    }



}