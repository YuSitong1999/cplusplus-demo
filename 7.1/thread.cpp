//
// Created by root on 23-7-18.
//

#include <iostream>
#include <thread>

int main() {
    std::thread t([]() {
        // sleep 5s
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "hello world." << std::endl;
    });
    t.join();
    return 0;
}
