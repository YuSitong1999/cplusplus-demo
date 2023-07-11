//
// Created by root on 23-7-11.
//

#include<string>
#include<iostream>

std::string  lookup1(){
    return "lookup1";
}
std::string& lookup2(){
    static std::string s = "lookup2";
    return s;
}

// C++11
namespace CPP11 {
    std::string look_up_a_string_1() {
        return lookup1();
    }

    std::string &look_up_a_string_2() {
        return lookup2();
    }
}

// C++14
namespace CPP14 {
    decltype(auto) look_up_a_string_1() {
        return lookup1();
    }

    decltype(auto) look_up_a_string_2() {
        return lookup2();
    }
}

int main(){
    std::string cpp11Lookup1 = CPP11::look_up_a_string_1();
    std::string &cpp11Lookup2 = CPP11::look_up_a_string_2();
    std::string cpp14Lookup1 = CPP11::look_up_a_string_1();
    std::string &cpp14Lookup2 = CPP11::look_up_a_string_2();

    std::cout << cpp11Lookup1 << std::endl;
    std::cout << cpp11Lookup2 << std::endl;
    std::cout << cpp14Lookup1 << std::endl;
    std::cout << cpp14Lookup2 << std::endl;

    cpp11Lookup1 += "*";
    cpp11Lookup2 += "*";
    cpp14Lookup1 += "*";
    cpp14Lookup2 += "*";

    std::cout << cpp11Lookup1 << std::endl;
    std::cout << cpp11Lookup2 << std::endl;
    std::cout << cpp14Lookup1 << std::endl;
    std::cout << cpp14Lookup2 << std::endl;

    {
        std::string cpp11Lookup1 = CPP11::look_up_a_string_1();
        std::string &cpp11Lookup2 = CPP11::look_up_a_string_2();
        std::string cpp14Lookup1 = CPP11::look_up_a_string_1();
        std::string &cpp14Lookup2 = CPP11::look_up_a_string_2();

        std::cout << cpp11Lookup1 << std::endl;
        std::cout << cpp11Lookup2 << std::endl;
        std::cout << cpp14Lookup1 << std::endl;
        std::cout << cpp14Lookup2 << std::endl;
    }
}
