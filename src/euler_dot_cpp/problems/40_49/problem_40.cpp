#include "stdafx.hpp"
#include "problem_40.hpp"

#include "../../common/digits.hpp"

using namespace std;

int64_t impl_40_1::solve()
{
    int64_t product = 1;
    int64_t current_digit = 0;
    int64_t next_digit = 10;

    for (int64_t i = 1;; ++i)
    {
        const auto digit_count = get_digit_count(i);
        current_digit += digit_count;
        if (current_digit < next_digit)
        {
            continue;
        }
        const auto diff = current_digit - next_digit;
        auto num = i;
        for(auto j = 0; j < diff; ++j)
        {
            num /= 10;
        }

        const auto result_digit = num % 10;
        product *= result_digit;

        if (next_digit == 1000000)
        {
            break;
        }
        next_digit *= 10;
    }

	return product;
}