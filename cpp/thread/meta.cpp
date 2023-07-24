/***************************************************************************************
* @file       meta.cpp
* @brief      replaceme
* @details
* @author     xuzewei
* @date       2023-07-20
* @version    V1.0
* @copyright  Copyright (c) 2022-2025  Shen Zhen Poisson Software Technology CO.,LTD
**************************************************************************************/
#include <type_traits>
 
class A {};
class B : A {};
class C : B {};
class D {};
union E {};
 
static_assert(std::is_base_of_v<A, A>     == true  &&
              std::is_base_of_v<A, B>     == true  &&
              std::is_base_of_v<A, C>     == true  &&
              std::is_base_of_v<A, D>     == false &&
              std::is_base_of_v<B, A>     == false &&
              std::is_base_of_v<D, D>     == true &&
              std::is_base_of_v<E, E>     == false &&
              std::is_base_of<int, int>::value == false);
 
int main() {}
