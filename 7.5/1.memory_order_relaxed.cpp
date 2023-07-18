//
// Created by root on 23-7-18.
//

#include<atomic>
#include<vector>
#include<thread>
#include<iostream>

int main() {
    std::atomic<int> counter = {0};
    std::vector<std::thread> vt;
    for (int i = 0; i < 100; ++i) {
        vt.emplace_back([&]() {
            // 宽松模型：在此模型下，单个线程内的原子操作都是顺序执行的，不允许指令重排，但不同线程间原子操作的顺序是任意的。
            counter.fetch_add(1, std::memory_order_relaxed);
        });
    }

    for (auto &t: vt) {
        t.join();
    }
    std::cout << "current counter:" << counter << std::endl;
    return 0;
}
