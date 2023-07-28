#include <iostream>

// 通用的模板类
template<typename T>
class MyClass {
public:
    void print(T value) {
        std::cout << value << std::endl;
    }
};

// 模板特化，只接受int类型的参数
template<>
class MyClass<int> {
public:
    void print(int value) {
        std::cout << "Special implementation for int: " << value << std::endl;
    }
};

// 模板特化，只接受double类型的参数
template<>
class MyClass<double> {
public:
    void print(double value) {
        std::cout << "Special implementation for double: " << value << std::endl;
    }
};

int main() {
    MyClass<int> obj1;
    obj1.print(10); // 输出：Special implementation for int: 10

    MyClass<double> obj2;
    obj2.print(10.5); // 输出：Special implementation for double: 10.5

    // 编译错误，因为类型不符合限定
    MyClass<char> obj3;
    obj3.print('a');

    return 0;
}

