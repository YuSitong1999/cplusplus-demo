cmake_minimum_required(VERSION 3.25)
project(cplusplus_demo)

set(CMAKE_CXX_STANDARD 20)

add_executable(2.1.nullptr
        2.1/nullptr.cpp)

add_executable(2.1.constexpr
        2.1/constexpr.cpp)

add_executable(2.2.if_switch
        2.2/if_switch_variables.cpp)

add_executable(2.2.initializer_list
        2.2/initializer_list.cpp)

add_executable(2.2.structured_binding
        2.2/structured_binding.cpp)

add_executable(2.3.auto
        2.3/auto.cpp)

add_executable(2.3.decltype
        2.3/decltype.cpp)

add_executable(2.3.tail_type_inference
        2.3/tail_type_inference.cpp)

add_executable(2.3.decltype_auto
        2.3/decltype_auto.cpp)
