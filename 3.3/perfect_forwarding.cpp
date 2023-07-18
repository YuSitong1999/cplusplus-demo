//
// Created by root on 23-7-12.
//

#include <iostream>

void reference(int &v) {
    std::cout << "左值" << std::endl;
}

void reference(int &&v) {
    std::cout << "右值" << std::endl;
}

template<typename T>
void pass(T &&v) {
    std::cout << "普通传参:";
    reference(v); // 始终调用 reference(int&)
}

template<typename T>
void pass2(T &&v) {
    std::cout << "              普通传参: ";
    reference(v);
    std::cout << "       std::move 传参: ";
    reference(std::move(v));
    std::cout << "    std::forward 传参: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> 传参: ";
    reference(static_cast<T &&>(v));
}

int main() {
    {
        std::cout << "传递右值:" << std::endl;
        pass(1); // 1是右值, 但输出是左值

        std::cout << "传递左值:" << std::endl;
        int l = 1;
        pass(l); // l 是左值, 输出左值
    }
    std::cout << std::endl;
    {
        std::cout << "传递右值:" << std::endl;
        pass2(1);

        std::cout << "传递左值:" << std::endl;
        int v = 1;
        pass2(v);
    }
    return 0;
}