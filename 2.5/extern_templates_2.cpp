//
// Created by root on 23-7-12.
//

#include"extern_templates.h"

// 在一个源文件中
template
class MyClass<int>; // 实例化模板

int work() {
    MyClass<int> a;
    return a.getZero();
}
