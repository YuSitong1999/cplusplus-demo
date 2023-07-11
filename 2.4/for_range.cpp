//
// Created by root on 23-7-11.
//

#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};
    if (auto itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end()) *itr = 4;
    for (auto element: vec)
        std::cout << element << std::endl; // read only
    for (auto &element: vec) {
        element += 1;                      // writeable
    }
    std::cout << std::endl;
    for (auto element: vec)
        std::cout << element << std::endl; // read only
}
