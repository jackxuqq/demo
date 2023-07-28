/***************************************************************************************
* @file       meta2.cpp
* @brief      replaceme
* @details
* @author     xuzewei
* @date       2023-07-20
* @version    V1.0
* @copyright  Copyright (c) 2022-2025  Shen Zhen Poisson Software Technology CO.,LTD
**************************************************************************************/
#include <iostream>
#include <type_traits>
 
class A {};
 
class B : A {};
 
class C {};
 
int main() 
{
    std::cout << std::boolalpha;
    std::cout << "a2b: " << std::is_base_of_v<A, B> << '\n';
    std::cout << "b2a: " << std::is_base_of_v<B, A> << '\n';
    std::cout << "c2b: " << std::is_base_of_v<C, B> << '\n';
    std::cout << "same type: " << std::is_base_of_v<C, C><< '\n';
    std::cout << "same type: " << std::is_base_of_v<int, int><< '\n';
}
