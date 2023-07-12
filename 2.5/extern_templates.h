//
// Created by root on 23-7-12.
//

#ifndef CPLUSPLUS_DEMO_EXTERN_TEMPLATES_H
#define CPLUSPLUS_DEMO_EXTERN_TEMPLATES_H

// 在头文件中
template<class T>
class MyClass {
public:
    T getZero() {
        return T{};
    }
};

extern template
class MyClass<int>; // 声明一个外部模板

int work();

#endif //CPLUSPLUS_DEMO_EXTERN_TEMPLATES_H
