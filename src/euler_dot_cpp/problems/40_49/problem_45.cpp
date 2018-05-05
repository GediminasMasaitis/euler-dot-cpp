#include "stdafx.hpp"
#include "problem_45.hpp"
#include "../../common/ngonal_numbers.h"

using namespace std;

int64_t impl_45_1::solve()
{
    constexpr int64_t given = 143;
    for (auto i = given + 1;; ++i)
    {
        auto num = hexagonal_num(i);
        if (is_triangle_num(num) && is_pentagonal_num(num))
        {
            return num;
        }
    }
    return -1;
}

int64_t impl_45_2::solve()
{
    constexpr int64_t given = 40755;
    for(auto i = given + 1;; ++i)
    {
        if(is_triangle_num(i) && is_pentagonal_num(i) && is_hexagonal_num(i))
        {
            return i;
        }
    }
    return -1;
}
