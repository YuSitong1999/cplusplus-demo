//
// Created by root on 23-7-18.
//

#include <iostream>
#include <future>
#include <thread>

int main() {
    // 将一个返回值为7的 lambda 表达式封装到 task 中
    // std::packaged_task 的模板参数为要封装函数的类型
    std::packaged_task<int()> task([]() {
        std::cout << "sleep begin" << std::endl;
        // sleep 3s
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "sleep end" << std::endl;
        return 7;
    });
    // 获得 task 的期物
    std::future<int> result = task.get_future(); // 在一个线程中执行 task
    std::thread(std::move(task)).detach();
    std::cout << "waiting..." << std::flush;
    result.wait(); // 在此设置屏障，阻塞到期物的完成
    // 输出执行结果
    std::cout << "done!" << std::endl <<
              "future result is " << result.get() << std::endl;
    return 0;
}

/*
在C++中，std::thread::detach函数被用来将线程与相应的线程对象分离，使得线程的执行可以独立进行。
 一旦线程被分离，它就不能被显式地管理。这意味着我们不能直接从分离的线程中获取结果，也不能等待其结束。分离的线程在执行完毕后会自动释放所占用的资源。

一般来说，对于std::thread对象，你必须调用join或detach之一，否则在std::thread对象析构时程序会终止。
 join会等待线程结束，而detach则允许线程独立运行。

在你的代码中，detach是必须的，因为你需要让包含task的线程独立运行，同时主线程可以继续执行并输出"waiting..."。
 如果不调用detach，那么当std::thread对象析构时（例如，因为离开了作用域），如果线程仍在运行，程序会终止。

然而，如果你的程序需要等待线程完成并可能需要其结果，那么你可能需要使用join而不是detach。
 在你的代码中，虽然你使用了detach，但是你依然可以通过std::future来获取线程的结果，
 这是因为你使用了std::packaged_task来打包任务，并通过get_future获取了一个与任务结果相关联的std::future。
*/
