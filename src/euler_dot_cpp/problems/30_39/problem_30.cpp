#include "stdafx.hpp"
#include "problem_30.hpp"
#include "../../common/transform_sequence.hpp"
#include "../../common/digits.hpp"

using namespace std;

int64_t impl_30_1::solve()
{
    constexpr uint32_t power = 5;
    
    int64_t max_digit_pow = 9;
    for (auto i = 1; i < power; i++)
    {
        max_digit_pow *= 9;
    }
    
    int64_t temp = 9;
    int64_t limit = max_digit_pow;
    while(temp < limit)
    {
        temp *= 10;
        temp += 9;
        limit += max_digit_pow;
    }

    int64_t result = 0;
    for(int64_t i = 2; i <= limit; i++)
    {
        auto str = to_string(i);
        int64_t digit_sum = 0;
        for(auto ch : str)
        {
            const auto digit = static_cast<int64_t>(ch - 0x30);
            int64_t digit_power = digit;
            for(auto i = 1; i < power; i++)
            {
                digit_power *= digit;
            }
            digit_sum += digit_power;
        }
        if(digit_sum == i)
        {
            result += i;
        }
    }
    return result;
}

int64_t impl_30_2::solve()
{
    const uint32_t power = 5;

    array<int64_t, 10> powers;

    for(auto i = 0; i <= 9; i++)
    {
        int64_t digit_pow = i;
        for (auto j = 1; j < power; j++)
        {
            digit_pow *= i;
        }
        powers[i] = digit_pow;
    }

    int64_t temp = 9;
    int64_t limit = powers[9];
    while (temp < limit)
    {
        temp *= 10;
        temp += 9;
        limit += powers[9];
    }

    int64_t result = 0;
    for (int64_t i = 2; i <= limit; i++)
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

template<typename TValue, typename TIndex, int32_t VPower>
constexpr TValue int_pow(TIndex index)
{
    TValue digit_pow = index;
    for (int32_t j = 1; j < VPower; j++)
    {
        digit_pow *= index;
    }
    return digit_pow;
}

/*template<typename TValue, typename TIndex, int32_t VPower>
using power_sequence = transform_sequence_templ<>*/


int64_t impl_30_3::solve()
{
    constexpr uint32_t power = 5;
    constexpr transform_sequence<int64_t, int32_t, 0, 10> powers(&int_pow<int64_t, int32_t, power>);

    int64_t temp = 9;
    int64_t limit = powers.values[9];
    while (temp < limit)
    {
        temp *= 10;
        temp += 9;
        limit += powers.values[9];
    }

    int64_t result = 0;
    for (int64_t i = 2; i <= limit; i++)
    {
        int64_t digit_sum = 0;
        unordered_get_digits<int64_t, int64_t>(i, [&digit_sum, &powers](uint32_t, const int64_t  digit)
        {
            const auto digit_power = powers.values[digit];
            digit_sum += digit_power;
            return true;
        });
        if (digit_sum == i)
        {
            result += i;
        }
    }
    return result;
}
