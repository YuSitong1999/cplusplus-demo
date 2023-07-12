//
// Created by root on 23-7-11.
//

#include<iostream>
#include"extern_templates.h"

// 在一个源文件中
template
class MyClass<int>; // 实例化模板

int main() {
    MyClass<double> a;
    std::cout << a.getZero() << std::endl;

    std::cout << work() << std::endl;
}
