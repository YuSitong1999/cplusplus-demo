//
// Created by root on 23-7-12.
//

#include<iostream>

class Magic {
public:
    Magic() = default; // 显式声明使用编译器生成的构造
    Magic &operator=(const Magic &) = delete; // 显式声明拒绝编译器生成构造
    Magic(int magic_number) {
        std::cout << magic_number << std::endl;
    }
};

int main() {
    Magic magic;
//    magic = Magic(1);
    Magic magic2(2);
}
