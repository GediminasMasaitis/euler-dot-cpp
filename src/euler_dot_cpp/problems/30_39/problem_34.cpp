#include "stdafx.hpp"
#include "problem_34.hpp"

#include "../../common/basic_math.hpp"

using namespace std;

int64_t impl_34_1::solve()
{
    // Similar to problem 30
    constexpr factorial_sequence<int64_t, size_t, 0, 10> seq;

    auto& powers = seq.values;

    int64_t temp = 9;
    int64_t limit = powers[9];
    while (temp < limit)
    {
        temp *= 10;
        temp += 9;
        limit += powers[9];
    }

    int64_t result = 0;
    for (int64_t i = 3; i <= limit; i++)
    {
        auto str = to_string(i);
        int64_t digit_sum = 0;
        for (auto ch : str)
        {
            const auto digit = static_cast<int64_t>(ch - 0x30);
            const auto digit_power = powers[digit];
            digit_sum += digit_power;
        }
        if (digit_sum == i)
        {
            result += i;
        }
    }
    return result;
}
