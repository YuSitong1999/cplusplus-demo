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
            // 顺序一致模型：在此模型下，原子操作满足顺序一致性，进而可能对性能产生损耗。
            counter.fetch_add(1, std::memory_order_seq_cst);
        });
    }

    for (auto &t: vt) {
        t.join();
    }
    std::cout << "current counter:" << counter << std::endl;
    return 0;
}
