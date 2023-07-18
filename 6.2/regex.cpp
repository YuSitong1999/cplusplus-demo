//
// Created by root on 23-7-18.
//

#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string fileNames[] = {"foo.txt", "bar.txt", "test", "a0.txt", "AAA.txt"};
    // 在 C++ 中 \ 会被作为字符串内的转义符，
    // 为使 \. 作为正则表达式传递进去生效，需要对 \ 进行二次转义，从而有 \\.
    std::regex txt_regex("[a-z]+\\.txt");
    for (const auto &fileName: fileNames)
        std::cout << fileName << ": " << std::regex_match(fileName, txt_regex) << std::endl;

    std::regex base_regex("([a-z]+)\\.txt");
    std::smatch base_match;
    for (const auto &fileName: fileNames) {
        if (std::regex_match(fileName, base_match, base_regex)) {
            // std::smatch 的第一个元素匹配整个字符串
            // std::smatch 的第二个元素匹配了第一个括号表达式
            if (base_match.size() == 2) {
                std::cout << "sub-match[0]: " << base_match[0].str() << std::endl;
                std::string base = base_match[1].str();
                std::cout << fileName << " sub-match[1]: " << base << std::endl;
            }
        }
    }

    return 0;
}
