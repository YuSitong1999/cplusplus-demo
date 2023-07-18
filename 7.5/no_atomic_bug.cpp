//
// Created by root on 23-7-18.
//

#include <thread>
#include <iostream>

int main() {
    int a = 0;
    int flag = 0;
//    volatile int flag = 0;
/*
在C++中，volatile关键字有一个特定的含义，它表示对象的值可能会由于程序本身之外的原因而改变。这常常用于处理硬件寄存器，或者某些需要防止编译器优化的情况。然而，volatile并不提供跨线程的内存可见性或者同步。
在你的例子中，即使使用volatile修饰a和flag，也不能保证输出"b = 5"。这是因为volatile并不能防止编译器或者硬件的重排序，也不能保证一个线程写入的值会立刻对其他线程可见。
为了保证跨线程的内存可见性和同步，你应该使用C++的std::atomic，std::mutex或者其他的同步原语。这些工具可以确保正确的内存访问顺序，并且保证一个线程写入的值会对其他线程立刻可见。
总的来说，虽然volatile在某些情况下可能看起来像是一个解决方案，但是在多线程编程中，你应该总是使用适当的同步工具，而不是依赖volatile。
*/

    std::thread t1([&]() {
        while (flag != 1);

        int b = a;
        std::cout << "b = " << b << std::endl;
    });

    std::thread t2([&]() {
        a = 5;
        flag = 1;
    });

    t1.join();
    t2.join();
    return 0;
}
