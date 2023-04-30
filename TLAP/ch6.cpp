#include <iostream> 
#include <concepts>
#include <type_traits>

short increment_as_short(void* target) {
    auto as_short = static_cast<short*>(target);
    *as_short = *as_short + 1;
    return *as_short;
}

//should require T is an int
template<typename T>
concept Integer = std::is_same_v<T, int>;



template<Integer T> 
T test(T* boos) {
    return *boos + *boos; 
}

int main() {
    int f = 12; 
    int g = 5; 
    std::cout << test(&f) << std::endl; 
    ++f; 
    float test = static_cast<float>(g); 
    float t {f}; 
    std::cout << 0.1f + 0.2f << std::endl; 
    short beast{ 665 };
    
    auto mark_of_the_beast = increment_as_short(&beast);
    printf("%d is the mark_of_the_beast.", mark_of_the_beast);
}