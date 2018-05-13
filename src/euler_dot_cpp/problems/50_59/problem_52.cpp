#include "stdafx.hpp"
#include "problem_52.hpp"

using namespace std;

int64_t impl_52_1::solve()
{
    for(int64_t i = 1;; ++i)
    {
        const auto num_str = to_string(i);
        auto success = true;
        for(auto j = 2; j <= 6; ++j)
        {
            const auto mul = i * j;
            const auto mul_str = to_string(mul);
            if(!is_permutation(mul_str.begin(), mul_str.end(), num_str.begin(), num_str.end()))
            {
                success = false;
                break;
            }
        }
        if (success)
        {
            return i;
        }
    }
    return 0LL;
}

int64_t impl_52_2::solve()
{
    int64_t start = 1;
    int64_t limit = 10;
    while (true)
    {
        const auto div_lim = limit / 6;
        for (int64_t i = start; i <= div_lim; ++i)
        {
            const auto num_str = to_string(i);
            auto success = true;
            for (auto j = 2; j <= 6; ++j)
            {
                const auto mul = i * j;
                const auto mul_str = to_string(mul);
                if (!is_permutation(mul_str.begin(), mul_str.end(), num_str.begin(), num_str.end()))
                {
                    success = false;
                    break;
                }
            }
            if (success)
            {
                return i;
            }
        }
        start = limit;
        limit *= 10;
    }
}
