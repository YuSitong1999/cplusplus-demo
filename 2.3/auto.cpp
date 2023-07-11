//
// Created by root on 23-7-11.
//

#include <initializer_list>
#include <vector>
#include <iostream>

class MagicFoo {
public:
    std::vector<int> vec;

    MagicFoo(std::initializer_list<int> list) {
        // 从 C++11 起, 使用 auto 关键字进行类型推导
        for (auto it = list.begin(); it != list.end(); ++it) {
            vec.push_back(*it);
        }

        // 在 C++11 之前
        // 由于 cbegin() 将返回 vector<int>::const_iterator
        // 所以 it 也应该是 vector<int>::const_iterator 类型
        for (std::vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

// C++20
int add(auto x, auto y) {
    // typename decltype(x)::type z; // Error: 'decltype(x)' is not a class, namespace, or enumeration
    return x+y;
}

int main() {
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    std::cout << "magicFoo: ";
    for (auto it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    auto i = 5; // 被推导为 int
    auto j = 6; // 被推导为 int
    std::cout << add(i, j) << std::endl;

    std::cout << add(i+0.5, j+0.5) << std::endl;
    return 0;
}
