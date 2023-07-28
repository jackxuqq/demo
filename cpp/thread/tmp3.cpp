#include <iostream>
#include <type_traits>

template<typename T>
class MyClass {
public:
    void print(T value) {
        static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value,
                      "MyClass only accepts int or double types");
        std::cout << value << std::endl;
    }
};

int main() {
    MyClass<int> obj1;
    obj1.print(10); // 输出：10

    MyClass<double> obj2;
    obj2.print(10.5); // 输出：10.5

    // 编译错误，因为类型不符合限定
    MyClass<char> obj3;
    obj3.print('a');

    return 0;
}

