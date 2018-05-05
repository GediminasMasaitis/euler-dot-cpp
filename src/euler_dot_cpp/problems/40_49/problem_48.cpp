#include "stdafx.hpp"
#include "problem_48.hpp"

using namespace std;

int64_t impl_48_1::solve()
{
    boost::multiprecision::cpp_int sum = 0;
    constexpr int64_t mod = 10000000000;
    for(int64_t i = 1; i <= 1000; ++i)
    {
        const boost::multiprecision::cpp_int i2 = i;
        const auto num = boost::multiprecision::pow(i2, i);
        sum += num;
    }
    const auto last_digits = sum % mod;
    const auto last_digits_int = static_cast<int64_t>(last_digits);
    return last_digits_int;
}

int64_t impl_48_2::solve()
{
    int64_t sum = 0;
    constexpr int64_t mod = 10000000000;
    for (int64_t i = 1; i <= 1000; ++i)
    {
        const auto num = boost::multiprecision::powm(i, i, mod);
        sum += num;
    }
    const auto last_digits = sum % mod;
    return last_digits;
}

int64_t impl_48_3::solve()
{
    int64_t sum_mod = 0;
    constexpr int64_t mod = 10000000000;

    for (int64_t i = 1; i <= 1000; ++i)
    {
        int64_t round_mod = i;
        for (int64_t j = 1; j < i; j++)
        {
            round_mod *= i;
            if (round_mod >= numeric_limits<int64_t>::max() / 1000)
            {
                round_mod %= mod;
            }
        }
        sum_mod += round_mod;
        sum_mod %= mod;
    }
    return sum_mod;
}
