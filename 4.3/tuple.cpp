//
// Created by root on 23-7-18.
//

#include <tuple>
#include <iostream>

// C++17
#include <variant>

template <size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...>& tpl, size_t i) {
    if constexpr (n >= sizeof...(T))
        throw std::out_of_range("越界.");
    if (i == n)
        return std::variant<T...>{ std::in_place_index<n>, std::get<n>(tpl) };
    return _tuple_index<(n < sizeof...(T)-1 ? n+1 : 0)>(tpl, i);
}
template <typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...>& tpl, size_t i) {
    return _tuple_index<0>(tpl, i);
}
template <typename T0, typename ... Ts>
std::ostream & operator<< (std::ostream & s, std::variant<T0, Ts...> const & v) {
    std::visit([&](auto && x){ s << x;}, v);
    return s;
}

template <typename T>
auto tuple_len(T &tpl) {
    return std::tuple_size<T>::value;
}

auto get_student(int id)
{
    // 返回类型被推断为 std::tuple<double, char, std::string>

    if (id == 0)
        return std::make_tuple(3.8, 'A', "张三");
    if (id == 1)
        return std::make_tuple(2.9, 'C', "李四");
    if (id == 2)
        return std::make_tuple(1.7, 'D', "王五");
    return std::make_tuple(0.0, 'D', "null");
    // 如果只写 0 会出现推断错误, 编译失败
}


int main()
{
    {
    auto student = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << std::get<0>(student) << ", "
              << "成绩: " << std::get<1>(student) << ", "
              << "姓名: " << std::get<2>(student) << '\n';

    double gpa;
    char grade;
    std::string name;

    // 元组进行拆包
    std::tie(gpa, grade, name) = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << gpa << ", "
              << "成绩: " << grade << ", "
              << "姓名: " << name << '\n';
    }
    {
        std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);
        std::cout << std::get<std::string>(t) << std::endl;
//        std::cout << std::get<double>(t) << std::endl; // 非法, 引发编译期错误
        std::cout << std::get<3>(t) << std::endl;

        int index = 1;
//        std::get<index>(t);

        int i = 1;
        std::cout << tuple_index(t, i) << std::endl;

        auto new_tuple = std::tuple_cat(get_student(1), std::move(t));

        // 迭代
        for(int i = 0; i != tuple_len(new_tuple); ++i)
            // 运行期索引
            std::cout << tuple_index(new_tuple, i) << std::endl;
    }
}
