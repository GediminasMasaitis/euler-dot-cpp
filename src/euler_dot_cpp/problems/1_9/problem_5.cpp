#include "stdafx.hpp"
#include "problem_5.hpp"

#include "../../common/basic_math.hpp"

using namespace std;

int64_t impl_5_1::solve()
{
    int64_t lcm = 1;
    for(int64_t i = 1; i <= 20; ++i)
    {
        lcm = lowest_common_multiple(lcm, i);
    }
    return lcm;
}

int64_t impl_5_2::solve()
{
    int64_t lcm = 1;
    for (int64_t i = 20; i > 1; --i)
    {
        lcm = lowest_common_multiple(lcm, i);
    }
    return lcm;
}

int64_t impl_5_3::solve()
{
    int64_t num = 1;
    while(true)
    {
        auto success = true;
        for(int64_t j = 1; j <= 20; ++j)
        {
            if(num%j != 0)
            {
                success = false;
                break;
            }
        }
        if(success)
        {
            break;
        }
        ++num;
    }
    return num;
}