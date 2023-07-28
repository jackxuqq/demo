#include <iostream>

template<typename T>
class MyClass {
public:
    void print(T value)
        requires (
        std::is_same_v<T, int> ||
        std::is_same_v<T, double*> ||
        std::is_same_v<T, char> ||
        std::is_same_v<T, float>
        )
    {
        std::cout << value << std::endl;
    }
};

int main() {
    MyClass<int> obj;
    obj.print(10); // 输出：10

    // 编译错误，因为类型不符合限定
    MyClass<double*> obj2;
    double d = 10.5;
    obj2.print(&d);
    return 0;
}

