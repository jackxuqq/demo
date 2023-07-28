#include <iostream>
#include <string>
#include <unordered_map>
#include "absl/container/flat_hash_map.h"

int g_count = 1000000;
void case1()
{
    std::cout << "case1:use flat_hash_map" << std::endl;
    //init map
    absl::flat_hash_map<int, int> ducks;
    for (auto i = 0; i < 1000; ++i)
    {
        ducks.insert({i, 10 * i});
    }
    ducks.rehash(0);

    int k = 0;
    long sum = 0;
    int i = 0;
    for (; i < g_count; ++i)
    {
        auto result = ducks.find(k++);
        k = k % 1000;
        if (result != ducks.end())
        {
            sum += result->second;
        }
    }

    std::cout << "sum = " << sum << "\ti = " << i << std::endl;
}

void case2()
{
    std::cout << "case2:use unordered_map" << std::endl;
    //init map
    std::unordered_map<int, int> ducks;
    for (auto i = 0; i < 1000; ++i)
    {
        ducks.insert({i, 10 * i});
    }

    int k = 0;
    long sum = 0;
    int i = 0;
    for (; i < g_count; ++i)
    {
        auto result = ducks.find(k++);
        k = k % 1000;
        if (result != ducks.end())
        {
            sum += result->second;
        }
    }

    std::cout << "sum = " << sum << "\ti = " << i << std::endl;
}

void case3()
{
    std::cout << "case3:use diy_map" << std::endl;
    //init map
    int matrix[1024][1024]{0};
    for (auto j = 0; j < 1000; ++j)
    {
        matrix[0][j] = 10*j;
    }

    int l = 0;
    int c = 0;
    long sum = 0;
    int i = 0;
    for (; i < g_count; ++i)
    {
        auto result = matrix[l][c];
        if (result != 0)
        {
            sum += result;
        }
        ++c;
        if (c == 1000)
        {
            ++l;
            c = 0;
        }
    }

    std::cout << "sum = " << sum << "\ti = " << i << std::endl;
}

int main(int c, char** v)
{
    if (c == 1)
    {
        case1();
    }
    else if (c == 2)
    {
        case2();
    }
    else if (c == 3)
    {
        case3();
    }
}
