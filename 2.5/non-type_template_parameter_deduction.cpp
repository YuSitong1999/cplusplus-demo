//
// Created by root on 23-7-12.
//

#include<iostream>

template<typename T, typename U>
auto add(T t, U u) {
    return t + u;
}


template<typename T, int BufSize>
class buffer_t {
public:
    T &alloc();

    void free(T &item);

private:
    T data[BufSize];
};

buffer_t<int, 100> buf; // 100 作为模板参数


template<auto value>
void foo() {
    std::cout << value << std::endl;
}

int main() {
    foo<10>();  // value 被推导为 int 类型
}
