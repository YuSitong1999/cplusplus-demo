//
// Created by root on 23-7-12.
//

#include<iostream>

struct Base {
    virtual void foo(int) {
        std::cout << "Base foo" << std::endl;
    }

    virtual void foo2(int) final {
        std::cout << "Base foo2" << std::endl;
    }
};

struct SubClass : Base {
    /*virtual*/ void foo(int) override {
        std::cout << "SubClass foo" << std::endl;
    } // legal
//    virtual void foo(float) override; // illegal, no virtual function in super class
};

struct SubClass1 final : Base {
}; // legal

//struct SubClass2 : SubClass1 {
//}; // illegal, SubClass1 has final

struct SubClass3 : Base {
//    void foo2(int) {
//        std::cout << "SubClass3 foo2" << std::endl;
//    }// illegal, foo has final
    void foo2() {
        std::cout << "SubClass3 foo2" << std::endl;
    }
};

int main() {
    SubClass sc;
    sc.foo(1);
    sc.foo2(1);

    SubClass1 sc1;
    sc1.foo(1);
    sc1.foo2(1);

    SubClass3 sc3;
    sc3.foo(1);
    sc3.foo2();
}