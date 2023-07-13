//
// Created by root on 23-7-12.
//

#include<iostream>

void lambda_generic() {
    auto generic = [](auto x, auto y) {
        return x + y;
    };

    std::cout << generic(1, 2) << std::endl;
    std::cout << generic(1.1, 2.2) << std::endl;
}

int main() {
    lambda_generic();
    return 0;
}
