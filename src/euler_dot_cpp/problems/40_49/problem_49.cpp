#include "stdafx.hpp"
#include "problem_49.hpp"
#include "../../common/digits.hpp"

using namespace std;

int64_t impl_49_1::solve()
{
    mt19937 rng(0);
    for(int64_t i = 1000; i <= 8999; ++i)
    {
        const auto num1 = i;
        if(!boost::multiprecision::miller_rabin_test(num1, 5, rng))
        {
            continue;
        }
        const auto num1_str = to_string(num1);
        for (int64_t j = 1000; j <= 4999; j += 2)
        {
            if(i == 1487 && j == 3330)
            {
                continue;
            }
            const auto num2 = i+j;
            const auto num3 = i+j*2;

            if(num3 > 9999)
            {
                break;
            }

            if (!boost::multiprecision::miller_rabin_test(num2, 5, rng))
            {
                continue;
            }
            if (!boost::multiprecision::miller_rabin_test(num3, 5, rng))
            {
                continue;
            }

            const auto num2_str = to_string(num2);
            if(!is_permutation(num2_str.begin(), num2_str.end(), num1_str.begin(), num1_str.end()))
            {
                continue;
            }
            const auto num3_str = to_string(num3);
            if (!is_permutation(num3_str.begin(), num3_str.end(), num1_str.begin(), num1_str.end()))
            {
                continue;
            }
            const int64_t pt1 = concat_num(num1, num2);
            const int64_t pt2 = concat_num(pt1, num3);
            return pt2;
        }
    }
    return 0LL;
}