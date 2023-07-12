//
// Created by root on 23-7-12.
//

#include<vector>
#include<string>
#include<map>
#include<iostream>

//template<typename... Ts>
//class Magic;

template<typename Require, typename... Args> class Magic{

};

class Magic<int, std::vector<int>, std::map<std::string, std::vector<int>>> darkMagic;


template<typename... Args>
void printf(const std::string &str, Args... args);

template<typename... Ts>
void magic(Ts... args) {
    std::cout << sizeof...(args) << std::endl;
}


template<typename T0>
void printf1(T0 value) {
    std::cout << value << std::endl;
}

template<typename T, typename... Ts>
void printf1(T value, Ts... args) {
    std::cout << value << std::endl;
    printf1(args...);
}

template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
    std::cout << t0 << std::endl;
    if constexpr (sizeof...(t) > 0) printf2(t...);
}

template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    std::cout << value << std::endl;
    (void) std::initializer_list<T>{([&args] {
        std::cout << args << std::endl;
    }(), value)...};
}

int main() {
    magic(); // 输出0
    magic(1); // 输出1
    magic(1, ""); // 输出2

    printf1(1, 2, "123", 1.1);
    printf2(1, 2, "123", 1.1);
    printf3(1, 2, "123", 1.1);
    return 0;
}