/* compile time poly (templates) */
#include <iostream> 
#include <stdexcept>
#include <concepts> 
#include <type_traits>


template <typename To, typename From>
To narrow_cast(From value) {
	const auto converted = static_cast<To>(value); 
	const auto backwards = static_cast<From>(converted); 
	if (value != backwards) throw std::runtime_error{ "Narrowed!" }; 
	return converted; 
}


//struct TemplateClass {
//	X foo(Y&); 
//};

template <typename T> 
struct SimpleUniquePointer {

	SimpleUniquePointer() = default; //explicit defining constructor as default 

	SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept {
		if (pointer) delete pointer; 
		pointer = other.pointer; 
		other.pointer = nullptr; 
		return *this;
	}
private: 
	T* pointer; 
};


void casts() {
	int perfect{ 496 }; 
	const auto perfect_short = narrow_cast<short>(perfect); 
	printf("perfect_short: %d\n", perfect_short); 
	try {
	int cyclic{ 142857 }; 
		const auto cyclic_short = narrow_cast<short>(cyclic); 
		printf("cyclic_short: %d\n", cyclic_short);
	}
	catch (const std::runtime_error& e) {
		printf("Exception: %s\n", e.what()); 
	}
	auto f = narrow_cast<long>(32); 
	printf("longboy %ld", f); 
}


//template<typename T> 
//size_t test(std::copyable* s) {
//	//something something where you need to copy s 
//};

template<typename T> requires std::is_copy_constructible<T>::value
T get_copy(T* pointer) {
	//blah blah 
}

template <typename T>
concept averagable = requires(T a) {
	std::is_default_constructible<T>::value
		&& requires (T a, T b) {
			{ a += b } -> std::same_as<T>;
			{ a / size_t{ 1 } } -> std::same_as<T>;
	};
};


template<averagable T>
T mean(const T* values, size_t length) {
	T result{};
	for (size_t i{}; i < length; i++) {
		result += values[i];
	}
	return result / length;
}


void meany() {
	const double nums_d[]{ 1.0, 2.0, 3.0, 4.0 };
	const auto result1 = mean<double>(nums_d, 4);

	std::cout << "double boys mean: " << result1 << std::endl;

	const long arr[]{ 4,6,7,8,3,2,66 };
	//auto result = mean<long>(arr, sizeof(arr) / sizeof(long));
	auto result = mean(arr, sizeof(arr) / sizeof(long)); //can infer type for generic (equiv to top) 

	std::cout << "long boys mean: " << result << std::endl;

	//FAILS 
	//auto value1 = 0.0;
	//auto value2 = 1.0;
	//const double* values[]{ &value1, &value2 };
	//mean(values, 2);
}

#pragma region Reg1
//template<typename T> 
//concept has_mem = requires {typename T::type; };
// This concept tests whether 'T::value' is a valid expression which can be implicitly converted to bool
// 'std::convertible_to' is a concept defined in <concepts>
//template<typename T>
//concept has_bool_value_member = requires { { T::value } -> std::convertible_to<bool>; };
//
//struct S1 {
//	bool test = false; 
//};
//template <class T> constexpr bool has_type_member_f(T) { return has_type_member<T>; }
//static_assert(!has_type_member_f(S1{}));
//
// This concept tests whether 't + u' is a valid expression
//template<typename T, typename U>
//concept can_add = requires(T t, U u) {
//	t + u; 
//	{t == u}; 
//	u == t; 
//	std::cout << t; 
//};


//
//
//
//template<typename T>
//concept NonPointer = not std::is_pointer_v<T>;

#pragma endregion Reg1


void typeChecker() {

}

//int main() {
//	meany(); 
//}