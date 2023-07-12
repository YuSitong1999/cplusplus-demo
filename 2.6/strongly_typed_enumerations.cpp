//
// Created by root on 23-7-12.
//

#include <iostream>

enum class new_enum : unsigned int {
    value1,
    value2,
    value3 = 100,
    value4 = 100
};

template<typename T>
std::ostream& operator<<(
        typename std::enable_if<std::is_enum<T>::value,
                std::ostream>::type& stream, const T& e)
{
    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}

int main(){
    if (new_enum::value3 == new_enum::value4) {
        // 会输出
        std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
    }

    std::cout << new_enum::value3 << std::endl;
}
