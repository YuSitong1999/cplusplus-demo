//
// Created by root on 7/8/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};

    // 在 c++17 之前
    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end()) {
        *itr = 3;
    }

    // 需要重新定义一个新的变量
//    const std::vector<int>::iterator itr2 = std::find(vec.begin(), vec.end(), 3);
//    if (itr2 != vec.end()) {
//        *itr2 = 4;
//    }

    // C++17: 将临时变量放到 if 语句内
    if (const auto itr = std::find(vec.begin(), vec.end(), 3);
            itr != vec.end()) {
        *itr = 4;
    }

    // 将输出 1, 4, 3, 4
    for (std::vector<int>::iterator element = vec.begin(); element != vec.end();
         ++element)
        std::cout << *element << std::endl;

    std::cout << std::endl;

    switch (auto itr = std::find(vec.begin(), vec.end(), 4); *++itr) {
        case 3: {
            std::cout << 3 << std::endl;
            break;
        }
        case 4: {
            std::cout << 4 << std::endl;
            break;
        }
        default: {
            std::cout << "other" << std::endl;
            break;
        }
    }
}
