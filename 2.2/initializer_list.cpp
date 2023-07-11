//
// Created by root on 7/11/23.
//

#include <iostream>
#include <vector>



int main() {
    // before C++11
class Foo {
public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b) {}
};

    int arr[3] = {1, 2, 3};
    Foo foo(1, 2);
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::cout << "arr[0]: " << arr[0] << std::endl;
    std::cout << "foo:" << foo.value_a << ", " << foo.value_b << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }

    class MagicFoo {
    public:
        std::vector<int> vec;
        MagicFoo(std::initializer_list<int> list) {
            for (std::initializer_list<int>::iterator it = list.begin();
                 it != list.end(); ++it)
                vec.push_back(*it);
        }
        void foo(std::initializer_list<int> list) {
            for (std::initializer_list<int>::iterator it = list.begin();
                 it != list.end(); ++it) vec.push_back(*it);
        }
    };

    // after C++11
    MagicFoo magicFoo = {1, 2, 3, 4, 5};

    std::cout << "magicFoo: ";
    for (std::vector<int>::iterator it = magicFoo.vec.begin();
         it != magicFoo.vec.end(); ++it)
        std::cout << *it << std::endl;

    std::cout<<std::endl;
    magicFoo.foo({6,7,8,9});
    return 0;
}
