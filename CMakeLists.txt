cmake_minimum_required(VERSION 3.25)
project(cplusplus_demo)

set(CMAKE_CXX_STANDARD 20)

# 最高优化级别
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

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

add_executable(2.4.if_constexpr
        2.4/if_constexpr.cpp)

add_executable(2.4.for_range
        2.4/for_range.cpp)

add_executable(2.5.extern_templates
        2.5/extern_templates.h 2.5/extern_templates.cpp 2.5/extern_templates_2.cpp)

add_executable(2.5.type_alias_templates
        2.5/type_alias_templates.cpp)

add_executable(2.5.variadic_templates
        2.5/variadic_templates.cpp)

add_executable(2.5.fold_expression
        2.5/fold_expression.cpp)

add_executable(2.5.non-type_template_parameter_deduction
        2.5/non-type_template_parameter_deduction.cpp)

add_executable(2.6.delegate_constructor
        2.6/delegate_constructor.cpp)

add_executable(2.6.inheritance_constructor
        2.6/inheritance_constructor.cpp)

add_executable(2.6.override_final 2.6/override_final.cpp)

add_executable(2.6.delete_default
        2.6/delete_default.cpp)

add_executable(2.6.strongly_typed_enumerations
        2.6/strongly_typed_enumerations.cpp)

add_executable(3.1.lambda 3.1/lambda.cpp)

add_executable(3.1.generic_lambda
        3.1/generic_lambda.cpp)

add_executable(3.2.std_function
        3.2/std_function.cpp)

add_executable(3.2.bin_placeholder 3.2/bin_placeholder.cpp)

add_executable(3.3.lvalue_rvalue 3.3/lvalue_rvalue.cpp)

add_executable(3.3.move_semantics
        3.3/move_semantics.cpp)

add_executable(3.3.perfect_forwarding
        3.3/perfect_forwarding.cpp)

add_executable(4.1.array
        4.1/array.cpp)

add_executable(4.1.forward_list
        4.1/forward_list.cpp 4.1/forward_list.cpp)

add_executable(4.2.unordered_map
        4.2/unordered_map.cpp)

add_executable(4.3.tuple
        4.3/tuple.cpp 4.3/tuple.cpp)

add_executable(5.2.shared_ptr
        5.2/shared_ptr.cpp)

add_executable(5.3.unique_ptr
        5.3/unique_ptr.cpp)

add_executable(5.4.weak_ptr
        5.4/weak_ptr.cpp)

add_executable(6.2.regex
        6.2/regex.cpp 6.2/regex.cpp)

add_executable(7.1.thread
        7.1/thread.cpp)

add_executable(7.2.mutex_lock_guard
        7.2/mutex_lock_guard.cpp)

add_executable(7.2.mutex_unique_lock
        7.2/mutex_unique_lock.cpp)
