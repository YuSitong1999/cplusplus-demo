//
// Created by root on 23-7-12.
//

#include<vector>
#include<string>
#include<iostream>

template<typename T, typename U>
class MagicType {
public:
    T dark;
    U magic;

    MagicType() = default;

    MagicType(T dark, U magic) : dark(dark), magic(magic) {}

    void output() const {
        std::cout << dark.size() << " " << magic << std::endl;
    }
};

// not allowed
//template<typename T>
//typedef MagicType<std::vector<T>, std::string> FakeDarkMagic;

typedef int (*process)(void *);

using NewProcess = int (*)(void *);

template<typename T>
using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

int main() {
    TrueDarkMagic<bool> you(std::vector<bool>{true, false}, "123");
    you.output();
}
